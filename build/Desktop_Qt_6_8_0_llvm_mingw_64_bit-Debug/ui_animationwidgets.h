/********************************************************************************
** Form generated from reading UI file 'animationwidgets.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ANIMATIONWIDGETS_H
#define UI_ANIMATIONWIDGETS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AnimationWidgets
{
public:
    QSlider *FPSSlider;
    QSpinBox *FPSBox;
    QLabel *label;
    QLabel *animationDisplay;
    QPushButton *addFrameButton;
    QPushButton *removeFrameButton;
    QCheckBox *checkBox;
    QFrame *widgets_frame;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *AnimationWidgets)
    {
        if (AnimationWidgets->objectName().isEmpty())
            AnimationWidgets->setObjectName("AnimationWidgets");
        AnimationWidgets->resize(559, 438);
        FPSSlider = new QSlider(AnimationWidgets);
        FPSSlider->setObjectName("FPSSlider");
        FPSSlider->setGeometry(QRect(340, 20, 31, 171));
        FPSSlider->setOrientation(Qt::Orientation::Vertical);
        FPSBox = new QSpinBox(AnimationWidgets);
        FPSBox->setObjectName("FPSBox");
        FPSBox->setGeometry(QRect(430, 140, 61, 21));
        label = new QLabel(AnimationWidgets);
        label->setObjectName("label");
        label->setGeometry(QRect(390, 140, 53, 15));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        label->setTextFormat(Qt::TextFormat::PlainText);
        animationDisplay = new QLabel(AnimationWidgets);
        animationDisplay->setObjectName("animationDisplay");
        animationDisplay->setGeometry(QRect(50, 40, 211, 221));
        addFrameButton = new QPushButton(AnimationWidgets);
        addFrameButton->setObjectName("addFrameButton");
        addFrameButton->setGeometry(QRect(350, 210, 141, 23));
        removeFrameButton = new QPushButton(AnimationWidgets);
        removeFrameButton->setObjectName("removeFrameButton");
        removeFrameButton->setGeometry(QRect(350, 240, 141, 23));
        checkBox = new QCheckBox(AnimationWidgets);
        checkBox->setObjectName("checkBox");
        checkBox->setGeometry(QRect(390, 170, 82, 21));
        widgets_frame = new QFrame(AnimationWidgets);
        widgets_frame->setObjectName("widgets_frame");
        widgets_frame->setGeometry(QRect(20, 290, 511, 111));
        widgets_frame->setFrameShape(QFrame::Shape::StyledPanel);
        widgets_frame->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout = new QHBoxLayout(widgets_frame);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(478, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        retranslateUi(AnimationWidgets);
        QObject::connect(FPSBox, &QSpinBox::valueChanged, FPSSlider, &QSlider::setValue);
        QObject::connect(FPSSlider, &QSlider::valueChanged, FPSBox, &QSpinBox::setValue);

        QMetaObject::connectSlotsByName(AnimationWidgets);
    } // setupUi

    void retranslateUi(QWidget *AnimationWidgets)
    {
        AnimationWidgets->setWindowTitle(QCoreApplication::translate("AnimationWidgets", "Form", nullptr));
        label->setText(QCoreApplication::translate("AnimationWidgets", "FPS", nullptr));
        animationDisplay->setText(QCoreApplication::translate("AnimationWidgets", "TextLabel", nullptr));
        addFrameButton->setText(QCoreApplication::translate("AnimationWidgets", "Add Frame", nullptr));
        removeFrameButton->setText(QCoreApplication::translate("AnimationWidgets", "Remove Frame", nullptr));
        checkBox->setText(QCoreApplication::translate("AnimationWidgets", "Play", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AnimationWidgets: public Ui_AnimationWidgets {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANIMATIONWIDGETS_H
