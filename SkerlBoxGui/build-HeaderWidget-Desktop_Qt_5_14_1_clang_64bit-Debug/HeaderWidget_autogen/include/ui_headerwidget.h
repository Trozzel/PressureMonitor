/********************************************************************************
** Form generated from reading UI file 'headerwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HEADERWIDGET_H
#define UI_HEADERWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HeaderWidget
{
public:
    QVBoxLayout *verticalLayout_2;
    QLabel *deviceNameLabel;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QLabel *timeLabel;
    QLabel *dateLabel;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_4;
    QLCDNumber *pressureLcd;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *ledLayout;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *quitBtn;

    void setupUi(QWidget *HeaderWidget)
    {
        if (HeaderWidget->objectName().isEmpty())
            HeaderWidget->setObjectName(QString::fromUtf8("HeaderWidget"));
        HeaderWidget->resize(220, 319);
        verticalLayout_2 = new QVBoxLayout(HeaderWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        deviceNameLabel = new QLabel(HeaderWidget);
        deviceNameLabel->setObjectName(QString::fromUtf8("deviceNameLabel"));
        QFont font;
        font.setPointSize(28);
        deviceNameLabel->setFont(font);
        deviceNameLabel->setAlignment(Qt::AlignCenter);
        deviceNameLabel->setIndent(-1);

        verticalLayout_2->addWidget(deviceNameLabel);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        timeLabel = new QLabel(HeaderWidget);
        timeLabel->setObjectName(QString::fromUtf8("timeLabel"));

        verticalLayout->addWidget(timeLabel);

        dateLabel = new QLabel(HeaderWidget);
        dateLabel->setObjectName(QString::fromUtf8("dateLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(dateLabel->sizePolicy().hasHeightForWidth());
        dateLabel->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(dateLabel);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_4 = new QSpacerItem(37, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        pressureLcd = new QLCDNumber(HeaderWidget);
        pressureLcd->setObjectName(QString::fromUtf8("pressureLcd"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pressureLcd->sizePolicy().hasHeightForWidth());
        pressureLcd->setSizePolicy(sizePolicy1);
        pressureLcd->setMinimumSize(QSize(100, 75));
        pressureLcd->setDigitCount(8);

        horizontalLayout_2->addWidget(pressureLcd);

        horizontalSpacer_3 = new QSpacerItem(37, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        verticalLayout_2->addLayout(horizontalLayout_2);

        ledLayout = new QHBoxLayout();
        ledLayout->setObjectName(QString::fromUtf8("ledLayout"));

        verticalLayout_2->addLayout(ledLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_5 = new QSpacerItem(34, 14, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        quitBtn = new QPushButton(HeaderWidget);
        quitBtn->setObjectName(QString::fromUtf8("quitBtn"));

        horizontalLayout_3->addWidget(quitBtn);


        verticalLayout_2->addLayout(horizontalLayout_3);


        retranslateUi(HeaderWidget);

        QMetaObject::connectSlotsByName(HeaderWidget);
    } // setupUi

    void retranslateUi(QWidget *HeaderWidget)
    {
        HeaderWidget->setWindowTitle(QCoreApplication::translate("HeaderWidget", "Ruska 9050i", nullptr));
        deviceNameLabel->setText(QCoreApplication::translate("HeaderWidget", "Pressure", nullptr));
        timeLabel->setText(QCoreApplication::translate("HeaderWidget", "TextLabel", nullptr));
        dateLabel->setText(QCoreApplication::translate("HeaderWidget", "TextLabel", nullptr));
        quitBtn->setText(QCoreApplication::translate("HeaderWidget", "Quit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HeaderWidget: public Ui_HeaderWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HEADERWIDGET_H
