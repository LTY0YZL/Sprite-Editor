/**
 * Author: Yang Hong
 * Date: 11/13/2024
 *
 * A dialog to set the width and height for the canvas, allowing the user to select dimensions.
 * The dialog uses QSpinBoxes to input width and height, with a maximum size limit of 64x64.
**/
#include "CanvasSizeDialog.h"

//Canvas Size Dialog class .cpp file
CanvasSizeDialog::CanvasSizeDialog(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("Set Canvas Size");

    QVBoxLayout *layout = new QVBoxLayout(this);

    QLabel *label = new QLabel("Canvas Size (Max: 64x64):", this);
    layout->addWidget(label);

    widthBox = new QSpinBox(this);
    widthBox->setRange(1, 64);
    widthBox->setValue(32);
    layout->addWidget(new QLabel("Width:", this));
    layout->addWidget(widthBox);

    heightBox = new QSpinBox(this);
    heightBox->setRange(1, 64);
    heightBox->setValue(32);
    layout->addWidget(new QLabel("Height:", this));
    layout->addWidget(heightBox);

    QPushButton *okButton = new QPushButton("OK", this);
    layout->addWidget(okButton);

    connect(okButton, &QPushButton::clicked, this, &CanvasSizeDialog::accept);
}

//Retrieves the selected width from the width spin box.
int CanvasSizeDialog::getWidth() const {
    return widthBox->value();
}

//Retrieves the selected width from the width spin box.
int CanvasSizeDialog::getHeight() const {
    return heightBox->value();
}
