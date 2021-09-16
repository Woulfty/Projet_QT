/********************************************************************************
** Form generated from reading UI file 'tcp.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TCP_H
#define UI_TCP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_tcpClass
{
public:

    void setupUi(QWidget *tcpClass)
    {
        if (tcpClass->objectName().isEmpty())
            tcpClass->setObjectName(QString::fromUtf8("tcpClass"));
        tcpClass->resize(600, 482);

        retranslateUi(tcpClass);

        QMetaObject::connectSlotsByName(tcpClass);
    } // setupUi

    void retranslateUi(QWidget *tcpClass)
    {
        tcpClass->setWindowTitle(QCoreApplication::translate("tcpClass", "tcp", nullptr));
    } // retranslateUi

};

namespace Ui {
    class tcpClass: public Ui_tcpClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TCP_H
