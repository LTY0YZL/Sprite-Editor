/**
 * Author: Yang Hong
 * Date: 11/13/2024
 *
 * A dialog to set the width and height for the canvas, allowing the user to select dimensions.
 * The dialog uses QSpinBoxes to input width and height, with a maximum size limit of 64x64.
**/
#ifndef CANVASSIZEDIALOG_H
#define CANVASSIZEDIALOG_H

#include <QDialog>
#include <QSpinBox>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

//Canvas Size Dialog class .h file
class CanvasSizeDialog : public QDialog {
    Q_OBJECT

private:
    QSpinBox *widthBox;
    QSpinBox *heightBox;

public:
    explicit CanvasSizeDialog(QWidget *parent = nullptr); //Constructor for CanvasSizeDialog.

    int getWidth() const; //Gets the selected width from the dialog.
    int getHeight() const; //Gets the selected height from the dialog.


};

#endif // CANVASSIZEDIALOG_H
