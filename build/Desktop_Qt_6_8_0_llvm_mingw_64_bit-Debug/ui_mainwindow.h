/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "animationwidgets.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *canvasLabel;
    QWidget *widget;
    QLabel *label;
    QPushButton *setColorButton;
    QWidget *layoutWidget;
    QFormLayout *formLayout;
    QPushButton *drawButton;
    QPushButton *clearButton;
    QPushButton *eraseButton;
    AnimationWidgets *widget_2;
    QMenuBar *menubar;
    QMenu *menuSpriteEditor;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1317, 736);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setAcceptDrops(true);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        canvasLabel = new QLabel(centralwidget);
        canvasLabel->setObjectName("canvasLabel");
        canvasLabel->setEnabled(true);
        canvasLabel->setGeometry(QRect(260, 30, 601, 601));
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(10, 20, 201, 481));
        label = new QLabel(widget);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 400, 73, 16));
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        QFont font;
        font.setBold(true);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8(""));
        setColorButton = new QPushButton(widget);
        setColorButton->setObjectName("setColorButton");
        setColorButton->setGeometry(QRect(40, 310, 79, 79));
        sizePolicy.setHeightForWidth(setColorButton->sizePolicy().hasHeightForWidth());
        setColorButton->setSizePolicy(sizePolicy);
        setColorButton->setMinimumSize(QSize(79, 79));
        setColorButton->setMaximumSize(QSize(50, 50));
        setColorButton->setStyleSheet(QString::fromUtf8("background-color:rgb(0, 0, 0)"));
        layoutWidget = new QWidget(widget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(20, 40, 131, 109));
        formLayout = new QFormLayout(layoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        drawButton = new QPushButton(layoutWidget);
        drawButton->setObjectName("drawButton");
        drawButton->setEnabled(true);
        sizePolicy.setHeightForWidth(drawButton->sizePolicy().hasHeightForWidth());
        drawButton->setSizePolicy(sizePolicy);
        drawButton->setMinimumSize(QSize(50, 50));
        drawButton->setMaximumSize(QSize(50, 16777215));

        formLayout->setWidget(0, QFormLayout::LabelRole, drawButton);

        clearButton = new QPushButton(layoutWidget);
        clearButton->setObjectName("clearButton");
        sizePolicy.setHeightForWidth(clearButton->sizePolicy().hasHeightForWidth());
        clearButton->setSizePolicy(sizePolicy);
        clearButton->setMinimumSize(QSize(50, 50));
        clearButton->setMaximumSize(QSize(50, 16777215));

        formLayout->setWidget(1, QFormLayout::FieldRole, clearButton);

        eraseButton = new QPushButton(layoutWidget);
        eraseButton->setObjectName("eraseButton");
        sizePolicy.setHeightForWidth(eraseButton->sizePolicy().hasHeightForWidth());
        eraseButton->setSizePolicy(sizePolicy);
        eraseButton->setMinimumSize(QSize(50, 50));
        eraseButton->setMaximumSize(QSize(50, 16777215));

        formLayout->setWidget(0, QFormLayout::FieldRole, eraseButton);

        widget_2 = new AnimationWidgets(centralwidget);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(950, 10, 351, 381));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1317, 26));
        menuSpriteEditor = new QMenu(menubar);
        menuSpriteEditor->setObjectName("menuSpriteEditor");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuSpriteEditor->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        canvasLabel->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "Select Color", nullptr));
        setColorButton->setText(QString());
        drawButton->setText(QCoreApplication::translate("MainWindow", "Draw", nullptr));
        clearButton->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        eraseButton->setText(QCoreApplication::translate("MainWindow", "Erase", nullptr));
        menuSpriteEditor->setTitle(QCoreApplication::translate("MainWindow", "SpriteEditor", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
