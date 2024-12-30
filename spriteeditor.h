/**
 * Author: Yang Hong
 * Date: 11/13/2024
 *
 * A widget that allows pixel-by-pixel editing of a QPixmap, representing an animation or image frame.
 * It supports tools like a brush and an eraser and allows for setting colors and previewing edits.
**/
#ifndef SPRITEEDITOR_H
#define SPRITEEDITOR_H

#include <QWidget>
#include <QPixmap>
#include <QLabel>
#include <QPoint>
#include <QPainter>
#include <QMouseEvent>

class SpriteEditor : public QWidget {
    Q_OBJECT
private:
    int canvasWidth;                                // Width of the canvas
    int canvasHeight;                               // Height of the canvas
    int currentFrame;                               // Current frame number being edited
    QPixmap *origionalPixelMap;                     // Reference to the original pixel map
    QPixmap pixelMapCopy;                           // Copy of the pixel map for live editing
    QColor brushColor;                              // Current brush color
    QLabel *canvasLabel;                            // QLabel displaying the canvas
    QPoint lastPos;                                 // Last position of the previewed pixel
    QPoint startPoint;                              // The first point for drawing the Rectangle
    std::vector<std::vector<QColor>> pixelColors;   // Stores colors of each pixel for preview purposes

    void initializeCanvas();                        // Initializes the canvas with a checkerboard pattern
    void drawRect(const QPoint &start, const QPoint &end); // Draw a rectangle from the start point to the end point
    void setPixelColor(const QPoint &pos, const QColor &color); // Sets a pixel's color
    void clearPreview();                            // Clears preview effects from the canvas
    bool borderCheck(const QPoint &pos);            // Check the cursor is in the canvas
    QColor getCheckerboardColor(int x, int y) const;// Returns checkerboard color based on pixel position
    QColor getColor(const QPoint &pos) const;       // Gets color at a specific position

public:
    explicit SpriteEditor(QPixmap& pixmap, int width, int height, QLabel *displayLabel, QWidget *parent = nullptr);

    enum ToolType { Brush, Eraser, DrawRect };
    ToolType currentTool = Brush;                   // Current selected tool (default is Brush)

    const QPixmap& getCanvas() const;               // Returns a copy of the canvas pixmap
    void drawPixel(const QPoint &pos);              // Draws a pixel at the specified position
    void setBrushColor(QColor newColor);            // Sets the color of the brush
    void setEditingPixelMap(QPixmap& pixelMap, int frameNumber); // Sets the current frame for editing
    void saveDrawing();                             // Saves the current drawing to the original pixel map
    void clearCanvas();                             // Clears the entire canvas
    void setTool(ToolType tool);                    // Sets the current tool (Brush or Eraser)
    void previewPixel(const QPoint &pos);           // Previews the brush/eraser effect at a position
    int getCurrentFrameNumber();                    // Returns the number of the current frame
    QPixmap createTransParentPixmap();              // Creates a transparent pixmap with a checkerboard pattern
    QColor getBrushColor() const;                   // Gets the current brush color
    QPoint changeScale(const QPoint &pos) const;    // Adjusts point coordinates to match the scale of the canvas
    void setSpriteSize(const int size);             // Reset the sprite size
};

#endif // SPRITEEDITOR_H
