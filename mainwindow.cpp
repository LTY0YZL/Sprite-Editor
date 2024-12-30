/**
 * Author: Yang Hong
 * Date: 11/13/2024
 *
 * Declaration of the MainWindow class, the main application window for the sprite editor.
 * provides the primary user interface for managing and editing a sprite's frames. The
 * interface includes tools for drawing, erasing, and managing colors, as well as functions
 * for adding, removing, and playing back frames as an animation.
 **/
#include "mainwindow.h"
#include "CanvasSizeDialog.h"

//Constructs the MainWindow, setting up UI, connections, and initializing default values.
MainWindow::MainWindow(Sprite& sprite,QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    sprite(sprite), // sprite model
    fps(1),
    currentAnimateFrameIndex(0)
{
    ui->setupUi(this);
    frameTimer = new QTimer(this);
    QTimer::singleShot(0, this, &MainWindow::showCanvasSizeDialog);
    connect(frameTimer, &QTimer::timeout, this, &MainWindow::updateFrame);
    connect(ui->drawButton, &QPushButton::clicked, this, &MainWindow::on_drawButton_clicked);
    connect(ui->eraseButton, &QPushButton::clicked, this, &MainWindow::on_eraseButton_clicked);
    connect(ui->drawRectButton, &QPushButton::clicked, this, &MainWindow::on_drawRectButton_clicked);
    connect(ui->playCheckBox, &QCheckBox::toggled, this, &MainWindow::on_playCheckBox_toggled);
    connect(ui->fpsSlider, &QSlider::valueChanged, this, &MainWindow::on_fpsChanged);
    connect(ui->fpsSpinBox, QOverload<int>::of(&QSpinBox::valueChanged), this, &MainWindow::on_fpsChanged);
}

//Displays the canvas size dialog to set the initial frame size.
void MainWindow::showCanvasSizeDialog() {
    CanvasSizeDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        int width = dialog.getWidth();
        int height = dialog.getHeight();
        sprite.addFrame(width,height);
        spriteEditor = new SpriteEditor(sprite.getFrame(0),width, height, ui->canvasLabel, this);
        addOnFrameBar();
        updateCanvas();
    }
    else {
        close();
    }
}

//Updates the display of the canvas and all frame buttons.
void MainWindow::updateCanvas() {
    if (spriteEditor) {
        ui->canvasLabel->setPixmap(
            spriteEditor->getCanvas().scaled(
                ui->canvasLabel->size(),
                Qt::KeepAspectRatio,
                Qt::FastTransformation
            )
        );
        spriteEditor->saveDrawing();
    }

    for (int i = 0; i < frameButtons.size(); i++) { // Update frame buttons display
        if (i < sprite.frameCount()) {
            scaleAndSetPixmapOnButton(sprite.getFrame(i), *frameButtons[i]);
        }
    }
}

//Toggles animation playback based on checkbox state.
void MainWindow::on_playCheckBox_toggled(bool checked) {
    if (checked) {
        if (fps <= 0) {
            ui->playCheckBox->setChecked(false); // Uncheck the checkbox
            return;
        }
        frameTimer->start(1000 / fps);
    }
    else {
        frameTimer->stop();
    }
}

//Handles mouse press event to draw a pixel on the canvas.
void MainWindow::mousePressEvent(QMouseEvent *event) {
    if (spriteEditor) {
        spriteEditor->drawPixel(event->pos());
        updateCanvas();
    }
}

//Handles mouse move event to preview or draw on the canvas.
void MainWindow::mouseMoveEvent(QMouseEvent *event) {
    if (spriteEditor) {
        if (event->buttons() == Qt::NoButton) {
            spriteEditor->previewPixel(event->pos());
        } else if (event->buttons() & Qt::LeftButton && spriteEditor->currentTool != SpriteEditor::DrawRect) {
            spriteEditor->drawPixel(event->pos());
        }
        updateCanvas();
    }
}

//Custom key press handler for keyboard shortcuts.
void MainWindow::keyPressEvent(QKeyEvent *event) { // ui not working so use this
    switch (event->key()) {
    case Qt::Key_B:
        on_drawButton_clicked();
        break;
    case Qt::Key_E:
        on_eraseButton_clicked();
        break;
    case Qt::Key_S:
        on_saveCurrentCanvasButton_clicked();
        break;
    case Qt::Key_R:
        on_clearButton_clicked();
        break;
    case Qt::Key_C:
        on_setColorButton_clicked();
        break;
    case Qt::Key_T:
        on_drawRectButton_clicked();
        break;
    case Qt::Key_P:
        if (ui->playCheckBox) {
            bool checkStatus = ui->playCheckBox->isChecked();
            ui->playCheckBox->setChecked(!checkStatus);  // Toggle the checkbox
        }
        break;
    default:
        break;
    }
}

//Helper function to scale and set a QPixmap on a QLabel.
void MainWindow::scaleAndSetPixmapOnLabel(QPixmap &pixmap, QLabel &label) {
    QSize pixmapSize = pixmap.size();
    QSize labelSize = label.size(); // Calculate scale factors for label width and height
    qreal scaleFactorWidth = static_cast<qreal>(labelSize.width()) / pixmapSize.width();
    qreal scaleFactorHeight = static_cast<qreal>(labelSize.height()) / pixmapSize.height(); // Choose the smaller scale factor
    qreal scaleFactor = qMin(scaleFactorWidth, scaleFactorHeight);// Calculate new size while maintaining aspect ratio
    int newWidth = static_cast<int>(pixmapSize.width() * scaleFactor);
    int newHeight = static_cast<int>(pixmapSize.height() * scaleFactor);
    QPixmap scaledPixmap = pixmap.scaled(newWidth, newHeight, Qt::KeepAspectRatio);
    label.setPixmap(scaledPixmap);
}
//Helper function to scale and set a QPixmap on a QPushButton.
void MainWindow::scaleAndSetPixmapOnButton(QPixmap &pixmap, QPushButton &button) {
    QSize pixmapSize = pixmap.size();
    QSize buttonSize = button.size();
    qreal scaleFactorWidth = static_cast<qreal>(buttonSize.width()) / pixmapSize.width();
    qreal scaleFactorHeight = static_cast<qreal>(buttonSize.height()) / pixmapSize.height();
    qreal scaleFactor = qMin(scaleFactorWidth, scaleFactorHeight);
    int newWidth = static_cast<int>(pixmapSize.width() * scaleFactor);
    int newHeight = static_cast<int>(pixmapSize.height() * scaleFactor);
    QPixmap scaledPixmap = pixmap.scaled(newWidth, newHeight, Qt::KeepAspectRatio);
    button.setIcon(QIcon(scaledPixmap));
    button.setIconSize(scaledPixmap.size()); // Ensure the button icon size matches the scaled pixmap
}

//Destructor for MainWindow, cleans up UI.
MainWindow::~MainWindow() {
    delete ui;
}

//Opens a color dialog and sets the selected color as the brush color.
void MainWindow::on_setColorButton_clicked() {
    addColorToHistory(spriteEditor->getBrushColor());
    QColor pickedColor = QColorDialog::getColor(Qt::white, this, tr("Select Color"));
    if (pickedColor.isValid()) {
        spriteEditor->setBrushColor(pickedColor);
        QString style = QString("background-color: %1; border: 2px solid lightgray; border-radius: 5px;").arg(pickedColor.name());
        ui->setColorButton->setStyleSheet(style);
    }
}

//Opens a color dialog and sets the selected color as the brush color in history.
void MainWindow::addColorToHistory(const QColor& color) {
    if (!color.isValid()||colorHistory.contains(color)) {
        return;
    }
    colorHistory.append(color);
    QPushButton* colorButton = new QPushButton(ui->ColorScroll);
    colorButton->setFixedSize(40, 40);
    QString style = QString("background-color: %1; border: 2px solid lightgray; border-radius: 5px;").arg(color.name());
    colorButton->setStyleSheet(style);
    QHBoxLayout* layout = qobject_cast<QHBoxLayout*>(ui->ColorScroll->layout());
    layout->insertWidget(0,colorButton);
    connect(colorButton, &QPushButton::clicked, this, [this, color]() {
        addColorToHistory(spriteEditor->getBrushColor());
        spriteEditor->setBrushColor(color);
        QString style = QString("QPushButton { background-color: %1; }").arg(color.name());
        ui->setColorButton->setStyleSheet(style);
    });
}

//Adds a new frame to the sprite and updates the UI.
void MainWindow::on_addFrameButton_clicked() {
    sprite.addFrame(spriteEditor->createTransParentPixmap());
    addOnFrameBar();
    int frameIndex = sprite.frameCount() - 1;
    spriteEditor->setEditingPixelMap(sprite.getFrame(frameIndex), frameIndex);
    if (sprite.frameCount() > 1) {
        ui->removeFrameButton->setEnabled(true);
    }
}

//Creates and adds a new button for a frame to the frame bar.
void MainWindow::addOnFrameBar() {
    saveCanvas();
    int frameIndex = sprite.frameCount() - 1;
    QPushButton* button = createFrameButton(frameIndex);
    button->click();
}

//Handles the draw button click to activate the drawing tool.
void MainWindow::on_drawButton_clicked() {
    if (spriteEditor) {
        spriteEditor->setTool(SpriteEditor::Brush);
    }

    ui->drawButton->setStyleSheet("background-color: lightblue;");
    ui->eraseButton->setStyleSheet("");
    ui->drawRectButton->setStyleSheet("");
}

//Handles the erase button click to activate the erasing tool.
void MainWindow::on_eraseButton_clicked() {
    qDebug() << "Erase button clicked";

    if (spriteEditor) {
        spriteEditor->setTool(SpriteEditor::Eraser);
    }

    ui->drawButton->setStyleSheet("");
    ui->eraseButton->setStyleSheet("background-color: lightblue;");
    ui->drawRectButton->setStyleSheet("");
}

//Handles the draw rectangle button click to activate the drawing rectangle tool.
void MainWindow::on_drawRectButton_clicked() {
    if (spriteEditor) {
        spriteEditor->setTool(SpriteEditor::DrawRect);
    }

    ui->drawButton->setStyleSheet("");
    ui->eraseButton->setStyleSheet("");
    ui->drawRectButton->setStyleSheet("background-color: lightblue;");
}

//Clears the current canvas, with confirmation.
void MainWindow::on_clearButton_clicked() {
    qDebug() << "Clear button clicked";

    if (QMessageBox::question(this, tr("Clear Canvas"),
        tr("Are you sure you want to clear the canvas?"),
        QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes)
    {
        if (spriteEditor) {
            spriteEditor->clearCanvas();
            updateCanvas();
        }
    }
}

//Saves the current canvas drawing to the sprite.
void MainWindow::on_saveCurrentCanvasButton_clicked() {
    saveCanvas();
}

// Save to canvas
void MainWindow::saveCanvas() {
    spriteEditor->saveDrawing();
    qDebug() << "Save Current Canvas";
    scaleAndSetPixmapOnLabel(sprite.getFrame(spriteEditor->getCurrentFrameNumber()), *ui->animationDisplayLabel);
}

//Removes the current frame from the sprite.
void MainWindow::on_removeFrameButton_clicked() {
    if (sprite.frameCount() <= 1) {
        return;
    }
    int currentFrameIndex = spriteEditor->getCurrentFrameNumber();
    if(currentFrameIndex>=1) {
    spriteEditor->setEditingPixelMap( sprite.getFrame(currentFrameIndex-1),currentFrameIndex-1);
    }
    sprite.removeFrame(currentFrameIndex);
    QPushButton* buttonToRemove = frameButtons.last();
    QLayout* layout = ui->framesDisplay->layout();
    layout->removeWidget(buttonToRemove);
    frameButtons.removeLast();
    delete buttonToRemove;

    updateCanvas();
    if (sprite.frameCount() <= 1) {
        ui->removeFrameButton->setEnabled(false);
    }
}
void MainWindow::on_fpsChanged(int newFps) {
    fps = newFps;
    if (frameTimer->isActive()) {
        frameTimer->setInterval(1000 / fps);
    }
}

//Updates the frame rate and restarts the animation if active.
void MainWindow::updateFrame() {
    if (sprite.frameCount() == 0) {
        return;
    }
    currentAnimateFrameIndex = (currentAnimateFrameIndex + 1) % sprite.frameCount(); // It will never out of range
    scaleAndSetPixmapOnLabel(sprite.getFrame(currentAnimateFrameIndex), *ui->animationDisplayLabel);
}

//Clears the color history and updates the UI.
void MainWindow::on_clearColorHistoryButton_clicked() {
    QHBoxLayout* layout = qobject_cast<QHBoxLayout*>(ui->ColorScroll->layout());
    while (QLayoutItem* item = layout->takeAt(0)) {
        if (item->spacerItem()) {
            layout->addItem(item);
            break;
        }
        if (QWidget* widget = item->widget()) {
            delete widget; // Deletes the button
        }
        delete item;
    }
    colorHistory.clear();
}

//Saves the sprite to a JSON file.
void MainWindow::on_actionSaveFile_triggered() {
    QString filePath = QFileDialog::getSaveFileName(this, tr("Save Sprite"), "", tr("JSON Files (*.json)"));
    if (!filePath.isEmpty()) {
        sprite.saveToJson(filePath);
    }
}

//Loads a sprite from a JSON file and updates the UI.
void MainWindow::on_actionLoad_File_triggered() {
    QString filePath = QFileDialog::getOpenFileName(this, tr("Load Sprite"), "", tr("JSON Files (*.json)"));
    QLayout* layout = ui->framesDisplay->layout();
    if (!filePath.isEmpty()) {
        if (!sprite.loadFromJson(filePath)) {
            QMessageBox::warning(this, tr("Load Error"), tr("Failed to load the file"));
            return;
        }
        int width = sprite.getFrame(0).width();
        spriteEditor->setSpriteSize(width);
        for (QPushButton* button : frameButtons) {
            layout->removeWidget(button);
            delete button;
        }
        frameButtons.clear();
        for (int i = 0; i < sprite.frameCount(); i++) {
            createFrameButton(i); // No need to capture the returned button if no further actions are needed
        }
        if (sprite.frameCount() > 0) {
            spriteEditor->setEditingPixelMap(sprite.getFrame(0), 0);
            updateCanvas();
        }
    }
}

//Creates a button to represent a frame and adds it to the frame bar.
QPushButton* MainWindow::createFrameButton(int frameIndex) {
    QPushButton* button = new QPushButton(this);
    button->setFixedSize(60, 60);
    button->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    scaleAndSetPixmapOnButton(sprite.getFrame(frameIndex), *button);
    frameButtons.append(button);
    connect(button, &QPushButton::clicked, this, [this, frameIndex]() {
        qDebug() << "Current frame set to:" << frameIndex;
        spriteEditor->setEditingPixelMap(sprite.getFrame(frameIndex), frameIndex);
        scaleAndSetPixmapOnLabel(sprite.getFrame(frameIndex), *ui->animationDisplayLabel);
        updateCanvas();
    });
    QHBoxLayout* layout = qobject_cast<QHBoxLayout*>(ui->framesDisplay->layout());
    layout->addWidget(button);
    return button;
}
