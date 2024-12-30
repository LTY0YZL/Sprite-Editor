/********************************************************************************
** Form generated from reading UI file 'toolbar.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOOLBAR_H
#define UI_TOOLBAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ToolBar
{
public:
    QWidget *widget;
    QLabel *label;
    QPushButton *setColorButton;
    QWidget *layoutWidget;
    QFormLayout *formLayout;
    QPushButton *drawButton;
    QPushButton *eraseButton;

    void setupUi(QWidget *ToolBar)
    {
        if (ToolBar->objectName().isEmpty())
            ToolBar->setObjectName("ToolBar");
        ToolBar->resize(400, 300);
        widget = new QWidget(ToolBar);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(20, 20, 181, 261));
        label = new QLabel(widget);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 180, 73, 16));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        QFont font;
        font.setBold(true);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8(""));
        setColorButton = new QPushButton(widget);
        setColorButton->setObjectName("setColorButton");
        setColorButton->setGeometry(QRect(38, 96, 79, 79));
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(setColorButton->sizePolicy().hasHeightForWidth());
        setColorButton->setSizePolicy(sizePolicy1);
        setColorButton->setMinimumSize(QSize(79, 79));
        setColorButton->setMaximumSize(QSize(50, 50));
        setColorButton->setStyleSheet(QString::fromUtf8("background-color:rgb(0, 0, 0)"));
        layoutWidget = new QWidget(widget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(21, 31, 108, 52));
        formLayout = new QFormLayout(layoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        drawButton = new QPushButton(layoutWidget);
        drawButton->setObjectName("drawButton");
        drawButton->setEnabled(true);
        sizePolicy1.setHeightForWidth(drawButton->sizePolicy().hasHeightForWidth());
        drawButton->setSizePolicy(sizePolicy1);
        drawButton->setMinimumSize(QSize(50, 50));
        drawButton->setMaximumSize(QSize(50, 16777215));

        formLayout->setWidget(0, QFormLayout::LabelRole, drawButton);

        eraseButton = new QPushButton(layoutWidget);
        eraseButton->setObjectName("eraseButton");
        sizePolicy1.setHeightForWidth(eraseButton->sizePolicy().hasHeightForWidth());
        eraseButton->setSizePolicy(sizePolicy1);
        eraseButton->setMinimumSize(QSize(50, 50));
        eraseButton->setMaximumSize(QSize(50, 16777215));

        formLayout->setWidget(0, QFormLayout::FieldRole, eraseButton);


        retranslateUi(ToolBar);

        QMetaObject::connectSlotsByName(ToolBar);
    } // setupUi

    void retranslateUi(QWidget *ToolBar)
    {
        ToolBar->setWindowTitle(QCoreApplication::translate("ToolBar", "Form", nullptr));
        label->setText(QCoreApplication::translate("ToolBar", "Select Color", nullptr));
        setColorButton->setText(QString());
        drawButton->setText(QCoreApplication::translate("ToolBar", "Draw", nullptr));
        eraseButton->setText(QCoreApplication::translate("ToolBar", "Erase", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ToolBar: public Ui_ToolBar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOOLBAR_H
