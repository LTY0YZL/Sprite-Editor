/**
 * Author: Yang Hong
 * Date: 11/13/2024
 *
 * Declaration of the MainWindow class, the main application window for the sprite editor.
 * provides the primary user interface for managing and editing a sprite's frames. The
 * interface includes tools for drawing, erasing, and managing colors, as well as functions
 * for adding, removing, and playing back frames as an animation.
 **/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QColorDialog>
#include <QColor>
#include <QPalette>
#include <QLabel>
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>
#include <QMessageBox>
#include "SpriteEditor.h"
#include "Sprite.h"
#include "ui_mainwindow.h"



QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

//Manages the main application window, integrating the SpriteEditor and Sprite models.
class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    Ui::MainWindow *ui; // view
    Sprite& sprite; // model
    SpriteEditor *spriteEditor; // control
    QTimer* frameTimer;
    int fps;
    int currentAnimateFrameIndex;
    QVector<QColor> colorHistory;
    QVector<QPushButton*> frameButtons;
    void scaleAndSetPixmapOnLabel(QPixmap &pixmap, QLabel &label);  // Helper to scale and set pixmap on a QLabel
    void scaleAndSetPixmapOnButton(QPixmap &pixmap, QPushButton &button); // Helper to scale and set pixmap on a QPushButton
    void addColorToHistory(const QColor& color);  // Adds color to color history
    void addOnFrameBar();                         // Adds a new frame button to the frame bar
    QPushButton* createFrameButton(int frameIndex); // Creates a button to represent a frame in the frame bar

public:
    MainWindow(Sprite& sprite, QWidget *parent = nullptr);
    ~MainWindow();
    void showCanvasSizeDialog();  // Opens a dialog to set the canvas size
    void updateCanvas();          // Updates the canvas display
    void saveCanvas();           // Saves the current canvas to the sprite frame
    void mousePressEvent(QMouseEvent *event);  // Handles mouse press events for drawing
    void mouseMoveEvent(QMouseEvent *event);   // Handles mouse move events for previewing/drawing
    void keyPressEvent(QKeyEvent *event);      // Handles key press events for shortcuts

private slots:
    void on_setColorButton_clicked();           // Slot for the color selection button
    void on_addFrameButton_clicked();           // Slot for adding a new frame
    void on_saveCurrentCanvasButton_clicked();  // Slot to save current canvas changes
    void on_drawButton_clicked();             // Slot to set tool to Draw
    void on_eraseButton_clicked();            // Slot to set tool to Erase
    void on_drawRectButton_clicked();         // Slot to set tool to DrawRect
    void on_clearButton_clicked();            // Slot to clear the canvas
    void on_removeFrameButton_clicked();        // Slot for removing a frame
    void on_clearColorHistoryButton_clicked();  // Slot to clear color history
    void on_actionSaveFile_triggered();         // Slot to save sprite to file
    void on_actionLoad_File_triggered();        // Slot to load sprite from file
    void updateFrame();                         // Slot to update the animation frame
    void on_playCheckBox_toggled(bool checked); // Slot to handle animation play toggle
    void on_fpsChanged(int newFps);             // Slot for FPS slider/spinbox change
};
#endif // MAINWINDOW_H
