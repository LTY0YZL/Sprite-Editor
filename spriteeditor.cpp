/**
 * Author: Yang Hong
 * Date: 11/13/2024
 *
 * A widget that allows pixel-by-pixel editing of a QPixmap, representing an animation or image frame.
 * It supports tools like a brush and an eraser and allows for setting colors and previewing edits.
**/
#include "SpriteEditor.h"


//Constructor for SpriteEditor.
SpriteEditor::SpriteEditor(QPixmap& pixelMap,int width, int height, QLabel *displayLabel, QWidget *parent)
    : QWidget(parent),
    canvasWidth(width),
    canvasHeight(height),
    currentFrame(0),
    origionalPixelMap(&pixelMap),
    brushColor(Qt::black),
    canvasLabel(displayLabel)
{
    pixelMapCopy=origionalPixelMap->copy();
    startPoint = QPoint(-1, -1);
    pixelColors = std::vector<std::vector<QColor>>(height, std::vector<QColor>(width, Qt::lightGray));
    initializeCanvas();
}

//Sets the pixel map to be edited and the frame number.
void SpriteEditor::setEditingPixelMap(QPixmap& pixelMap, int frameNumber) {
    currentFrame=frameNumber;
    *origionalPixelMap=pixelMapCopy;// save changes to origional
    origionalPixelMap=&pixelMap;// set the ref to new pixel Map
    pixelMapCopy=pixelMap.copy(); // edit the copy again

    QImage image = pixelMapCopy.toImage();
    for (int y = 0; y < canvasHeight; ++y) {
        for (int x = 0; x < canvasWidth; ++x) {
            pixelColors[y][x] = image.pixelColor(x, y);
        }
    }

    clearPreview();
    lastPos = QPoint(-1, -1);
}

//Initializes the canvas with a transparent checkerboard background.
void SpriteEditor::initializeCanvas() {
    pixelMapCopy.fill(Qt::transparent);
    QPainter painter(&pixelMapCopy);
    int tileSize = 1;
    for (int y = 0; y < canvasHeight; y += tileSize) {
        for (int x = 0; x < canvasWidth; x += tileSize) {
            QColor color = getCheckerboardColor(x, y);
            painter.fillRect(x, y, tileSize, tileSize, color);
            pixelColors[y][x] = color;
        }
    }

    canvasLabel->setPixmap(pixelMapCopy);
}

//Gets the checkerboard color at a given position.
QColor SpriteEditor::getCheckerboardColor(int x, int y) const {
    int tileSize = 1;
    return ((x / tileSize + y / tileSize) % 2 == 0) ? Qt::lightGray : Qt::darkGray;
}

//Draws pixels at the specified position, using the brush, eraser or draw rectangle tool.
void SpriteEditor::drawPixel(const QPoint &pos) {
    QPoint canvasPos = changeScale(pos);
    if (!borderCheck(canvasPos)) {
        return;
    }

    if (currentTool == Brush) {
        qDebug() << "Tool: Brush. Drawing at" << canvasPos.x() << canvasPos.y() << "with color" << brushColor;
        setPixelColor(canvasPos, brushColor);
    }
    else if (currentTool == Eraser) {
        qDebug() << "Tool: Eraser. Erasing at" << canvasPos.x() << canvasPos.y();
        QColor bgColor = getCheckerboardColor(canvasPos.x(), canvasPos.y());
        setPixelColor(canvasPos, bgColor);
    }
    else if (currentTool == DrawRect) {
        if (startPoint != QPoint(-1, -1)) {
            drawRect(startPoint, canvasPos);
        }
        else{
            startPoint = canvasPos;
        }
        qDebug() << "Tool: DrawRect. Draw Rectangle from" << canvasPos.x() << "to" << canvasPos.y();
    }
}

// A private helper function for drawing rectangles
void SpriteEditor::drawRect(const QPoint &start, const QPoint &end) {
    int x1 = qMin(start.x(), end.x());
    int x2 = qMax(start.x(), end.x());
    int y1 = qMin(start.y(), end.y());
    int y2 = qMax(start.y(), end.y());

    for (int y = y1; y <= y2; ++y) {
        for (int x = x1; x <= x2; ++x) {
            setPixelColor(QPoint(x, y), brushColor);
        }
    }

    startPoint = QPoint(-1, -1);
}

//Sets the color of a specific pixel on the canvas.
void SpriteEditor::setPixelColor(const QPoint &pos, const QColor &color) {
    QPainter painter(&pixelMapCopy);
    painter.setPen(Qt::NoPen);
    painter.setBrush(color);
    painter.drawRect(pos.x(), pos.y(), 1, 1);
    pixelColors[pos.y()][pos.x()] = color;
    canvasLabel->setPixmap(pixelMapCopy);
}

//Previews the brush or eraser effect at the specified position.
void SpriteEditor::previewPixel(const QPoint &pos) {
    QPoint canvasPos = changeScale(pos);
    if (canvasPos == lastPos) return;
    if (!borderCheck(canvasPos)) {
        clearPreview();
        return;
    }


    clearPreview();
    QColor currentColor = pixelColors[canvasPos.y()][canvasPos.x()];
    QColor previewColor;
    if (currentColor.lightness() < 50) {
        previewColor = QColor(230, 230, 230, 250);
    }
    else {
        previewColor = currentColor.lighter(200);
    }

    QPainter painter(&pixelMapCopy);
    painter.setPen(Qt::NoPen);
    painter.setBrush(previewColor);
    painter.drawRect(canvasPos.x(), canvasPos.y(), 1, 1);
    canvasLabel->setPixmap(pixelMapCopy);
    lastPos = canvasPos;
    // qDebug() << "Preivewing at" << canvasPos.x() << canvasPos.y();
}

//Clears the preview effect from the canvas.
void SpriteEditor::clearPreview() {
    if (lastPos.x() != -1 && lastPos.y() != -1) {
        QColor originalColor = pixelColors[lastPos.y()][lastPos.x()];
        setPixelColor(lastPos, originalColor);
    }
    lastPos = QPoint(-1, -1);
    // qDebug() << "Clear color at" << lastPos.x() << lastPos.y();
}

//Creates a transparent pixmap with a checkerboard background.
QPixmap SpriteEditor::createTransParentPixmap() {
    QPixmap pixmap(canvasWidth, canvasHeight);
    pixmap.fill(Qt::transparent);
    QPainter painter(&pixmap);
    int tileSize = 1;
    for (int y = 0; y < canvasHeight; y += tileSize) {
        for (int x = 0; x < canvasWidth; x += tileSize) {
            QColor color = getCheckerboardColor(x, y);
            painter.fillRect(x, y, tileSize, tileSize, color);
        }
    }
    return pixmap;
}

//Saves the current drawing to the original pixel map.
void SpriteEditor::saveDrawing(){
    *origionalPixelMap=pixelMapCopy.copy();
}

//Returns a constant reference to the current canvas.
const QPixmap& SpriteEditor::getCanvas() const {
    return pixelMapCopy;
}

//Sets a new color for the brush.
void SpriteEditor::setBrushColor(QColor newColor) {
    brushColor=newColor;
}

//Sets the current tool to either Brush or Eraser.
void SpriteEditor::setTool(ToolType tool) {
    currentTool = tool;
}

//Clears the canvas by reinitializing it.
void SpriteEditor::clearCanvas() {
    initializeCanvas();
}

//Gets the number of the current frame.
int SpriteEditor::getCurrentFrameNumber() {
    return currentFrame;
}

//Gets the current brush color.
QColor SpriteEditor::getBrushColor() const {
    return brushColor;
}

//Adjusts point coordinates to fit the scale of the canvas.
QPoint SpriteEditor::changeScale(const QPoint &pos) const {
    if (!canvasLabel) {
        return QPoint(-1, -1);
    }
    int offsetX = canvasLabel->x() + 190, offsetY = canvasLabel->y() + 30;
    int labelWidth = canvasLabel->width();
    int labelHeight = canvasLabel->height();
    double canvasRatio = static_cast<double>(canvasWidth) / canvasHeight;
    double labelRatio = static_cast<double>(labelWidth) / labelHeight;
    double scaleX, scaleY;

    if (canvasRatio > labelRatio) {
        scaleX = static_cast<double>(canvasWidth) / labelWidth;
        scaleY = scaleX;
    } else {
        scaleY = static_cast<double>(canvasHeight) / labelHeight;
        scaleX = scaleY;
    }
    int x = (pos.x() - offsetX) * scaleX;
    int y = (pos.y() - offsetY) * scaleY;
    if (x >= 0 && x < canvasWidth && y >= 0 && y < canvasHeight) {
        return QPoint(x, y);
    }
    return QPoint(-1, -1);
}

//Check the cursor location is in the canvas
bool SpriteEditor::borderCheck(const QPoint &pos) {
    if (!canvasLabel) {
        return false;
    }
    if (pos.x() < 0 || pos.x() >= canvasWidth ||
        pos.y() < 0 || pos.y() >= canvasHeight) {
        return false;
    }

    return true;
}
void SpriteEditor::setSpriteSize(const int size) {
    canvasWidth = size;
    canvasHeight = size;
}
