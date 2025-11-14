/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *labelPort;
    QComboBox *comboBoxPort;
    QPushButton *btnRefresh;
    QComboBox *comboBoxBaudRate;
    QPushButton *btnOpen;
    QLabel *labelDataBits;
    QComboBox *comboBoxDataBits;
    QPushButton *btnClose;
    QLabel *labelStopBits;
    QComboBox *comboBoxStopBits;
    QLabel *labelParity;
    QComboBox *comboBoxParity;
    QLabel *labelIndicator;
    QLabel *labelBaudRate;
    QTextEdit *textEditSend;
    QGridLayout *gridLayout_2;
    QRadioButton *radioHexSend;
    QRadioButton *radioAsciiSend;
    QCheckBox *checkAutoSend;
    QLabel *label_6;
    QSpinBox *spinBoxInterval;
    QCheckBox *checkSendNewLine;
    QPushButton *btnSend;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QTextEdit *textEditReceive;
    QGridLayout *gridLayout_3;
    QPushButton *btnClearReceive;
    QPushButton *btnSaveReceive;
    QPushButton *btnPauseReceive;
    QRadioButton *radioHexReceive;
    QRadioButton *radioAsciiReceive;
    QCheckBox *checkAutoLine;
    QCheckBox *checkTimestamp;
    QLabel *labelStatus;
    QLabel *labelRxCount;
    QLabel *labelTxCount;
    QWidget *tab_2;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(1049, 656);
        horizontalLayout = new QHBoxLayout(Widget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        labelPort = new QLabel(Widget);
        labelPort->setObjectName("labelPort");

        gridLayout->addWidget(labelPort, 0, 0, 1, 1);

        comboBoxPort = new QComboBox(Widget);
        comboBoxPort->setObjectName("comboBoxPort");
        comboBoxPort->setMinimumSize(QSize(70, 0));

        gridLayout->addWidget(comboBoxPort, 0, 1, 1, 1);

        btnRefresh = new QPushButton(Widget);
        btnRefresh->setObjectName("btnRefresh");

        gridLayout->addWidget(btnRefresh, 0, 2, 1, 1);

        comboBoxBaudRate = new QComboBox(Widget);
        comboBoxBaudRate->addItem(QString());
        comboBoxBaudRate->addItem(QString());
        comboBoxBaudRate->addItem(QString());
        comboBoxBaudRate->addItem(QString());
        comboBoxBaudRate->addItem(QString());
        comboBoxBaudRate->setObjectName("comboBoxBaudRate");
        comboBoxBaudRate->setMinimumSize(QSize(70, 0));

        gridLayout->addWidget(comboBoxBaudRate, 1, 1, 1, 1);

        btnOpen = new QPushButton(Widget);
        btnOpen->setObjectName("btnOpen");

        gridLayout->addWidget(btnOpen, 1, 2, 1, 1);

        labelDataBits = new QLabel(Widget);
        labelDataBits->setObjectName("labelDataBits");

        gridLayout->addWidget(labelDataBits, 2, 0, 1, 1);

        comboBoxDataBits = new QComboBox(Widget);
        comboBoxDataBits->addItem(QString());
        comboBoxDataBits->addItem(QString());
        comboBoxDataBits->addItem(QString());
        comboBoxDataBits->addItem(QString());
        comboBoxDataBits->setObjectName("comboBoxDataBits");
        comboBoxDataBits->setMinimumSize(QSize(70, 0));

        gridLayout->addWidget(comboBoxDataBits, 2, 1, 1, 1);

        btnClose = new QPushButton(Widget);
        btnClose->setObjectName("btnClose");

        gridLayout->addWidget(btnClose, 2, 2, 1, 1);

        labelStopBits = new QLabel(Widget);
        labelStopBits->setObjectName("labelStopBits");

        gridLayout->addWidget(labelStopBits, 3, 0, 1, 1);

        comboBoxStopBits = new QComboBox(Widget);
        comboBoxStopBits->addItem(QString());
        comboBoxStopBits->addItem(QString());
        comboBoxStopBits->setObjectName("comboBoxStopBits");
        comboBoxStopBits->setMinimumSize(QSize(70, 0));

        gridLayout->addWidget(comboBoxStopBits, 3, 1, 1, 1);

        labelParity = new QLabel(Widget);
        labelParity->setObjectName("labelParity");

        gridLayout->addWidget(labelParity, 4, 0, 1, 1);

        comboBoxParity = new QComboBox(Widget);
        comboBoxParity->addItem(QString());
        comboBoxParity->addItem(QString());
        comboBoxParity->addItem(QString());
        comboBoxParity->setObjectName("comboBoxParity");
        comboBoxParity->setMinimumSize(QSize(70, 0));

        gridLayout->addWidget(comboBoxParity, 4, 1, 1, 1);

        labelIndicator = new QLabel(Widget);
        labelIndicator->setObjectName("labelIndicator");

        gridLayout->addWidget(labelIndicator, 3, 2, 2, 1);

        labelBaudRate = new QLabel(Widget);
        labelBaudRate->setObjectName("labelBaudRate");

        gridLayout->addWidget(labelBaudRate, 1, 0, 1, 1);

        gridLayout->setColumnStretch(0, 1);
        gridLayout->setColumnStretch(1, 2);
        gridLayout->setColumnStretch(2, 1);

        verticalLayout->addLayout(gridLayout);

        textEditSend = new QTextEdit(Widget);
        textEditSend->setObjectName("textEditSend");
        textEditSend->setMaximumSize(QSize(300, 300));

        verticalLayout->addWidget(textEditSend);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        radioHexSend = new QRadioButton(Widget);
        radioHexSend->setObjectName("radioHexSend");

        gridLayout_2->addWidget(radioHexSend, 0, 0, 1, 1);

        radioAsciiSend = new QRadioButton(Widget);
        radioAsciiSend->setObjectName("radioAsciiSend");

        gridLayout_2->addWidget(radioAsciiSend, 0, 1, 1, 2);

        checkAutoSend = new QCheckBox(Widget);
        checkAutoSend->setObjectName("checkAutoSend");

        gridLayout_2->addWidget(checkAutoSend, 1, 0, 1, 1);

        label_6 = new QLabel(Widget);
        label_6->setObjectName("label_6");

        gridLayout_2->addWidget(label_6, 1, 1, 1, 1);

        spinBoxInterval = new QSpinBox(Widget);
        spinBoxInterval->setObjectName("spinBoxInterval");
        spinBoxInterval->setMaximum(100000);

        gridLayout_2->addWidget(spinBoxInterval, 1, 2, 1, 1);

        checkSendNewLine = new QCheckBox(Widget);
        checkSendNewLine->setObjectName("checkSendNewLine");

        gridLayout_2->addWidget(checkSendNewLine, 2, 0, 1, 1);

        btnSend = new QPushButton(Widget);
        btnSend->setObjectName("btnSend");

        gridLayout_2->addWidget(btnSend, 2, 1, 1, 2);

        gridLayout_2->setColumnStretch(0, 1);
        gridLayout_2->setColumnStretch(1, 1);
        gridLayout_2->setColumnStretch(2, 1);

        verticalLayout->addLayout(gridLayout_2);

        verticalLayout->setStretch(0, 2);
        verticalLayout->setStretch(1, 1);
        verticalLayout->setStretch(2, 2);

        horizontalLayout->addLayout(verticalLayout);

        tabWidget = new QTabWidget(Widget);
        tabWidget->setObjectName("tabWidget");
        tab = new QWidget();
        tab->setObjectName("tab");
        verticalLayout_3 = new QVBoxLayout(tab);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        textEditReceive = new QTextEdit(tab);
        textEditReceive->setObjectName("textEditReceive");

        verticalLayout_2->addWidget(textEditReceive);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName("gridLayout_3");
        btnClearReceive = new QPushButton(tab);
        btnClearReceive->setObjectName("btnClearReceive");

        gridLayout_3->addWidget(btnClearReceive, 0, 0, 1, 1);

        btnSaveReceive = new QPushButton(tab);
        btnSaveReceive->setObjectName("btnSaveReceive");

        gridLayout_3->addWidget(btnSaveReceive, 0, 1, 1, 1);

        btnPauseReceive = new QPushButton(tab);
        btnPauseReceive->setObjectName("btnPauseReceive");

        gridLayout_3->addWidget(btnPauseReceive, 0, 2, 1, 1);

        radioHexReceive = new QRadioButton(tab);
        radioHexReceive->setObjectName("radioHexReceive");

        gridLayout_3->addWidget(radioHexReceive, 0, 3, 1, 1);

        radioAsciiReceive = new QRadioButton(tab);
        radioAsciiReceive->setObjectName("radioAsciiReceive");

        gridLayout_3->addWidget(radioAsciiReceive, 0, 4, 1, 1);

        checkAutoLine = new QCheckBox(tab);
        checkAutoLine->setObjectName("checkAutoLine");

        gridLayout_3->addWidget(checkAutoLine, 1, 0, 1, 1);

        checkTimestamp = new QCheckBox(tab);
        checkTimestamp->setObjectName("checkTimestamp");

        gridLayout_3->addWidget(checkTimestamp, 1, 1, 1, 1);

        labelStatus = new QLabel(tab);
        labelStatus->setObjectName("labelStatus");

        gridLayout_3->addWidget(labelStatus, 1, 2, 1, 1);

        labelRxCount = new QLabel(tab);
        labelRxCount->setObjectName("labelRxCount");

        gridLayout_3->addWidget(labelRxCount, 1, 3, 1, 1);

        labelTxCount = new QLabel(tab);
        labelTxCount->setObjectName("labelTxCount");

        gridLayout_3->addWidget(labelTxCount, 1, 4, 1, 1);


        verticalLayout_2->addLayout(gridLayout_3);


        verticalLayout_3->addLayout(verticalLayout_2);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        tabWidget->addTab(tab_2, QString());

        horizontalLayout->addWidget(tabWidget);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 3);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        labelPort->setText(QCoreApplication::translate("Widget", "\344\270\262\345\217\243\357\274\232", nullptr));
        btnRefresh->setText(QCoreApplication::translate("Widget", "\345\210\267\346\226\260\344\270\262\345\217\243", nullptr));
        comboBoxBaudRate->setItemText(0, QCoreApplication::translate("Widget", "4800", nullptr));
        comboBoxBaudRate->setItemText(1, QCoreApplication::translate("Widget", "9600", nullptr));
        comboBoxBaudRate->setItemText(2, QCoreApplication::translate("Widget", "19200", nullptr));
        comboBoxBaudRate->setItemText(3, QCoreApplication::translate("Widget", "38400", nullptr));
        comboBoxBaudRate->setItemText(4, QCoreApplication::translate("Widget", "57600", nullptr));

        btnOpen->setText(QCoreApplication::translate("Widget", "\346\211\223\345\274\200\344\270\262\345\217\243", nullptr));
        labelDataBits->setText(QCoreApplication::translate("Widget", "\346\225\260\346\215\256\344\275\215\357\274\232", nullptr));
        comboBoxDataBits->setItemText(0, QCoreApplication::translate("Widget", "8", nullptr));
        comboBoxDataBits->setItemText(1, QCoreApplication::translate("Widget", "7", nullptr));
        comboBoxDataBits->setItemText(2, QCoreApplication::translate("Widget", "6", nullptr));
        comboBoxDataBits->setItemText(3, QCoreApplication::translate("Widget", "5", nullptr));

        btnClose->setText(QCoreApplication::translate("Widget", "\345\205\263\351\227\255\344\270\262\345\217\243", nullptr));
        labelStopBits->setText(QCoreApplication::translate("Widget", "\345\201\234\346\255\242\344\275\215\357\274\232", nullptr));
        comboBoxStopBits->setItemText(0, QCoreApplication::translate("Widget", "1", nullptr));
        comboBoxStopBits->setItemText(1, QCoreApplication::translate("Widget", "2", nullptr));

        labelParity->setText(QCoreApplication::translate("Widget", "\346\240\241\351\252\214\344\275\215\357\274\232", nullptr));
        comboBoxParity->setItemText(0, QCoreApplication::translate("Widget", "\346\227\240", nullptr));
        comboBoxParity->setItemText(1, QCoreApplication::translate("Widget", "\345\245\207", nullptr));
        comboBoxParity->setItemText(2, QCoreApplication::translate("Widget", "\345\201\266", nullptr));

        labelIndicator->setText(QString());
        labelBaudRate->setText(QCoreApplication::translate("Widget", "\346\263\242\347\211\271\347\216\207\357\274\232", nullptr));
        radioHexSend->setText(QCoreApplication::translate("Widget", "HEX\345\217\221\351\200\201", nullptr));
        radioAsciiSend->setText(QCoreApplication::translate("Widget", "ASCII\345\217\221\351\200\201", nullptr));
        checkAutoSend->setText(QCoreApplication::translate("Widget", "\350\207\252\345\212\250\345\217\221\351\200\201", nullptr));
        label_6->setText(QCoreApplication::translate("Widget", "\351\227\264\351\232\224(ms):", nullptr));
        checkSendNewLine->setText(QCoreApplication::translate("Widget", "\345\217\221\351\200\201\346\226\260\350\241\214", nullptr));
        btnSend->setText(QCoreApplication::translate("Widget", "\345\217\221\351\200\201", nullptr));
        btnClearReceive->setText(QCoreApplication::translate("Widget", "\346\270\205\347\251\272\346\216\245\346\224\266", nullptr));
        btnSaveReceive->setText(QCoreApplication::translate("Widget", "\344\277\235\345\255\230\346\225\260\346\215\256", nullptr));
        btnPauseReceive->setText(QCoreApplication::translate("Widget", "\346\232\202\345\201\234\346\216\245\346\224\266", nullptr));
        radioHexReceive->setText(QCoreApplication::translate("Widget", "HEX\346\230\276\347\244\272", nullptr));
        radioAsciiReceive->setText(QCoreApplication::translate("Widget", "ASCII\346\230\276\347\244\272", nullptr));
        checkAutoLine->setText(QCoreApplication::translate("Widget", "\350\207\252\345\212\250\346\215\242\350\241\214", nullptr));
        checkTimestamp->setText(QCoreApplication::translate("Widget", "\346\230\276\347\244\272\346\227\266\351\227\264\346\210\263", nullptr));
        labelStatus->setText(QCoreApplication::translate("Widget", "\346\234\252\350\277\236\346\216\245", nullptr));
        labelRxCount->setText(QCoreApplication::translate("Widget", "\346\216\245\346\224\266\357\274\232", nullptr));
        labelTxCount->setText(QCoreApplication::translate("Widget", "\345\217\221\351\200\201\357\274\232", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("Widget", "Tab 1", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("Widget", "Tab 2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
