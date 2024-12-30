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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSaveFile;
    QAction *actionLoad_File;
    QAction *actionNew_File;
    QWidget *centralwidget;
    QWidget *widget;
    QWidget *layoutWidget;
    QFormLayout *formLayout;
    QPushButton *drawButton;
    QPushButton *eraseButton;
    QPushButton *clearButton;
    QPushButton *drawRectButton;
    QLabel *label;
    QPushButton *setColorButton;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QFrame *frame;
    QLabel *animationDisplayLabel;
    QPushButton *removeFrameButton;
    QLabel *label_2;
    QSlider *fpsSlider;
    QCheckBox *playCheckBox;
    QSpinBox *fpsSpinBox;
    QPushButton *addFrameButton;
    QLabel *label_3;
    QPushButton *saveCurrentCanvasButton;
    QScrollArea *scrollArea_2;
    QWidget *framesDisplay;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QFrame *frame_2;
    QLabel *canvasLabel;
    QWidget *colorHistory;
    QGridLayout *gridLayout;
    QScrollArea *scrollArea;
    QWidget *ColorScroll;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *clearColorHistoryButton;
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
        MainWindow->setMouseTracking(true);
        MainWindow->setAcceptDrops(true);
        actionSaveFile = new QAction(MainWindow);
        actionSaveFile->setObjectName("actionSaveFile");
        actionLoad_File = new QAction(MainWindow);
        actionLoad_File->setObjectName("actionLoad_File");
        actionNew_File = new QAction(MainWindow);
        actionNew_File->setObjectName("actionNew_File");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setMouseTracking(true);
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(10, 20, 171, 561));
        widget->setMouseTracking(true);
        layoutWidget = new QWidget(widget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(20, 60, 111, 111));
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

        eraseButton = new QPushButton(layoutWidget);
        eraseButton->setObjectName("eraseButton");
        sizePolicy.setHeightForWidth(eraseButton->sizePolicy().hasHeightForWidth());
        eraseButton->setSizePolicy(sizePolicy);
        eraseButton->setMinimumSize(QSize(50, 50));
        eraseButton->setMaximumSize(QSize(50, 16777215));

        formLayout->setWidget(0, QFormLayout::FieldRole, eraseButton);

        clearButton = new QPushButton(layoutWidget);
        clearButton->setObjectName("clearButton");
        sizePolicy.setHeightForWidth(clearButton->sizePolicy().hasHeightForWidth());
        clearButton->setSizePolicy(sizePolicy);
        clearButton->setMinimumSize(QSize(50, 50));
        clearButton->setMaximumSize(QSize(50, 16777215));

        formLayout->setWidget(1, QFormLayout::FieldRole, clearButton);

        drawRectButton = new QPushButton(layoutWidget);
        drawRectButton->setObjectName("drawRectButton");
        drawRectButton->setEnabled(true);
        sizePolicy.setHeightForWidth(drawRectButton->sizePolicy().hasHeightForWidth());
        drawRectButton->setSizePolicy(sizePolicy);
        drawRectButton->setMinimumSize(QSize(50, 50));
        drawRectButton->setMaximumSize(QSize(50, 16777215));

        formLayout->setWidget(1, QFormLayout::LabelRole, drawRectButton);

        label = new QLabel(widget);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 270, 131, 16));
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
        setColorButton->setGeometry(QRect(40, 190, 60, 60));
        sizePolicy.setHeightForWidth(setColorButton->sizePolicy().hasHeightForWidth());
        setColorButton->setSizePolicy(sizePolicy);
        setColorButton->setMinimumSize(QSize(60, 60));
        setColorButton->setMaximumSize(QSize(50, 50));
        setColorButton->setStyleSheet(QString::fromUtf8("background-color:rgb(0, 0, 0);\n"
"border: 2px solid darkgra;\n"
"border-radius: 5px;"));
        label_4 = new QLabel(widget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(20, 310, 61, 16));
        label_5 = new QLabel(widget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(20, 330, 61, 16));
        label_6 = new QLabel(widget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(20, 350, 61, 16));
        label_7 = new QLabel(widget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(20, 370, 61, 16));
        label_8 = new QLabel(widget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(20, 390, 61, 16));
        label_9 = new QLabel(widget);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(20, 410, 131, 16));
        label_10 = new QLabel(widget);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(20, 430, 131, 16));
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(830, 0, 481, 431));
        frame->setMouseTracking(true);
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        animationDisplayLabel = new QLabel(frame);
        animationDisplayLabel->setObjectName("animationDisplayLabel");
        animationDisplayLabel->setGeometry(QRect(20, 30, 250, 250));
        animationDisplayLabel->setMaximumSize(QSize(400, 400));
        removeFrameButton = new QPushButton(frame);
        removeFrameButton->setObjectName("removeFrameButton");
        removeFrameButton->setGeometry(QRect(320, 260, 141, 23));
        label_2 = new QLabel(frame);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(350, 160, 53, 15));
        QFont font1;
        font1.setPointSize(12);
        label_2->setFont(font1);
        label_2->setTextFormat(Qt::TextFormat::PlainText);
        fpsSlider = new QSlider(frame);
        fpsSlider->setObjectName("fpsSlider");
        fpsSlider->setGeometry(QRect(320, 40, 31, 171));
        fpsSlider->setMinimum(1);
        fpsSlider->setMaximum(100);
        fpsSlider->setOrientation(Qt::Orientation::Vertical);
        playCheckBox = new QCheckBox(frame);
        playCheckBox->setObjectName("playCheckBox");
        playCheckBox->setGeometry(QRect(360, 190, 82, 21));
        fpsSpinBox = new QSpinBox(frame);
        fpsSpinBox->setObjectName("fpsSpinBox");
        fpsSpinBox->setGeometry(QRect(390, 160, 61, 21));
        fpsSpinBox->setMinimum(1);
        fpsSpinBox->setMaximum(100);
        addFrameButton = new QPushButton(frame);
        addFrameButton->setObjectName("addFrameButton");
        addFrameButton->setGeometry(QRect(320, 230, 141, 23));
        label_3 = new QLabel(frame);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 10, 191, 16));
        saveCurrentCanvasButton = new QPushButton(frame);
        saveCurrentCanvasButton->setObjectName("saveCurrentCanvasButton");
        saveCurrentCanvasButton->setGeometry(QRect(10, 290, 131, 23));
        scrollArea_2 = new QScrollArea(frame);
        scrollArea_2->setObjectName("scrollArea_2");
        scrollArea_2->setGeometry(QRect(10, 330, 483, 91));
        scrollArea_2->setWidgetResizable(true);
        framesDisplay = new QWidget();
        framesDisplay->setObjectName("framesDisplay");
        framesDisplay->setGeometry(QRect(0, 0, 481, 89));
        horizontalLayout_3 = new QHBoxLayout(framesDisplay);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        scrollArea_2->setWidget(framesDisplay);
        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(190, 0, 621, 621));
        frame_2->setMouseTracking(true);
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        canvasLabel = new QLabel(frame_2);
        canvasLabel->setObjectName("canvasLabel");
        canvasLabel->setEnabled(true);
        canvasLabel->setGeometry(QRect(10, 10, 601, 601));
        canvasLabel->setMouseTracking(true);
        canvasLabel->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);
        colorHistory = new QWidget(centralwidget);
        colorHistory->setObjectName("colorHistory");
        colorHistory->setGeometry(QRect(820, 430, 501, 131));
        gridLayout = new QGridLayout(colorHistory);
        gridLayout->setObjectName("gridLayout");
        scrollArea = new QScrollArea(colorHistory);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        ColorScroll = new QWidget();
        ColorScroll->setObjectName("ColorScroll");
        ColorScroll->setGeometry(QRect(0, 0, 481, 82));
        horizontalLayout_2 = new QHBoxLayout(ColorScroll);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        scrollArea->setWidget(ColorScroll);

        gridLayout->addWidget(scrollArea, 0, 0, 1, 1);

        clearColorHistoryButton = new QPushButton(colorHistory);
        clearColorHistoryButton->setObjectName("clearColorHistoryButton");

        gridLayout->addWidget(clearColorHistoryButton, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1317, 20));
        menuSpriteEditor = new QMenu(menubar);
        menuSpriteEditor->setObjectName("menuSpriteEditor");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuSpriteEditor->menuAction());
        menuSpriteEditor->addAction(actionSaveFile);
        menuSpriteEditor->addAction(actionLoad_File);

        retranslateUi(MainWindow);
        QObject::connect(fpsSpinBox, &QSpinBox::valueChanged, fpsSlider, &QSlider::setValue);
        QObject::connect(fpsSlider, &QSlider::sliderMoved, fpsSpinBox, &QSpinBox::setValue);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionSaveFile->setText(QCoreApplication::translate("MainWindow", "Save File", nullptr));
        actionLoad_File->setText(QCoreApplication::translate("MainWindow", "Load File", nullptr));
        actionNew_File->setText(QCoreApplication::translate("MainWindow", "New File", nullptr));
        drawButton->setText(QCoreApplication::translate("MainWindow", "Draw", nullptr));
        eraseButton->setText(QCoreApplication::translate("MainWindow", "Erase", nullptr));
        clearButton->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        drawRectButton->setText(QCoreApplication::translate("MainWindow", "Rect", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Select Current Color", nullptr));
        setColorButton->setText(QString());
        label_4->setText(QCoreApplication::translate("MainWindow", "HOT KEY :", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "B:Draw", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "E:Eraser", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "C:ColorSelection", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "R:Clear", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "S:Save Current Canvas", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "P:Play/Stop ", nullptr));
        animationDisplayLabel->setText(QString());
        removeFrameButton->setText(QCoreApplication::translate("MainWindow", "Remove Frame", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "FPS", nullptr));
        playCheckBox->setText(QCoreApplication::translate("MainWindow", "Play", nullptr));
        addFrameButton->setText(QCoreApplication::translate("MainWindow", "Add Frame", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Saved Pixel / Animation Display", nullptr));
        saveCurrentCanvasButton->setText(QCoreApplication::translate("MainWindow", "Save Current Canvas", nullptr));
        canvasLabel->setText(QString());
        clearColorHistoryButton->setText(QCoreApplication::translate("MainWindow", "Clear Color History", nullptr));
        menuSpriteEditor->setTitle(QCoreApplication::translate("MainWindow", "SpriteEditorFile", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
