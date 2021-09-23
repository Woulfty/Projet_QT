/********************************************************************************
** Form generated from reading UI file 'tcpclient.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TCPCLIENT_H
#define UI_TCPCLIENT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FenClient
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *serveurIP;
    QLabel *label_2;
    QSpinBox *serveurPort;
    QPushButton *boutonConnexion;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QLabel *label_5;
    QLabel *label_6;
    QTextEdit *listeMessages;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *pseudo;
    QLabel *label_4;
    QLineEdit *message;
    QPushButton *boutonEnvoyer;

    void setupUi(QWidget *FenClient)
    {
        if (FenClient->objectName().isEmpty())
            FenClient->setObjectName(QString::fromUtf8("FenClient"));
        FenClient->resize(628, 480);
        QIcon icon;
        icon.addFile(QString::fromUtf8("chat.png"), QSize(), QIcon::Normal, QIcon::Off);
        FenClient->setWindowIcon(icon);
        FenClient->setWindowOpacity(53.000000000000000);
        verticalLayout_2 = new QVBoxLayout(FenClient);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(FenClient);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        serveurIP = new QLineEdit(FenClient);
        serveurIP->setObjectName(QString::fromUtf8("serveurIP"));
        serveurIP->setMaximumSize(QSize(150, 16777215));

        horizontalLayout->addWidget(serveurIP);

        label_2 = new QLabel(FenClient);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        serveurPort = new QSpinBox(FenClient);
        serveurPort->setObjectName(QString::fromUtf8("serveurPort"));
        serveurPort->setMinimumSize(QSize(60, 0));
        serveurPort->setMinimum(1024);
        serveurPort->setMaximum(65535);
        serveurPort->setValue(50885);

        horizontalLayout->addWidget(serveurPort);

        boutonConnexion = new QPushButton(FenClient);
        boutonConnexion->setObjectName(QString::fromUtf8("boutonConnexion"));

        horizontalLayout->addWidget(boutonConnexion);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_5 = new QLabel(FenClient);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setPixmap(QPixmap(QString::fromUtf8("chat.png")));

        verticalLayout->addWidget(label_5);

        label_6 = new QLabel(FenClient);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        QFont font;
        font.setPointSize(11);
        font.setBold(false);
        font.setWeight(50);
        label_6->setFont(font);
        label_6->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_6);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout);

        listeMessages = new QTextEdit(FenClient);
        listeMessages->setObjectName(QString::fromUtf8("listeMessages"));
        listeMessages->setReadOnly(true);

        verticalLayout_2->addWidget(listeMessages);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(FenClient);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        pseudo = new QLineEdit(FenClient);
        pseudo->setObjectName(QString::fromUtf8("pseudo"));
        pseudo->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_2->addWidget(pseudo);

        label_4 = new QLabel(FenClient);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_2->addWidget(label_4);

        message = new QLineEdit(FenClient);
        message->setObjectName(QString::fromUtf8("message"));

        horizontalLayout_2->addWidget(message);

        boutonEnvoyer = new QPushButton(FenClient);
        boutonEnvoyer->setObjectName(QString::fromUtf8("boutonEnvoyer"));
        boutonEnvoyer->setIcon(icon);

        horizontalLayout_2->addWidget(boutonEnvoyer);


        verticalLayout_2->addLayout(horizontalLayout_2);


        retranslateUi(FenClient);

        QMetaObject::connectSlotsByName(FenClient);
    } // setupUi

    void retranslateUi(QWidget *FenClient)
    {
        FenClient->setWindowTitle(QCoreApplication::translate("FenClient", "dreamcordClient", nullptr));
        label->setText(QCoreApplication::translate("FenClient", "IP du serveur :", nullptr));
        serveurIP->setText(QCoreApplication::translate("FenClient", "127.0.0.1", nullptr));
        label_2->setText(QCoreApplication::translate("FenClient", "Port du serveur :", nullptr));
        boutonConnexion->setText(QCoreApplication::translate("FenClient", "Connexion", nullptr));
        label_6->setText(QCoreApplication::translate("FenClient", "dreamcord", nullptr));
        label_3->setText(QCoreApplication::translate("FenClient", "Pseudo :", nullptr));
        label_4->setText(QCoreApplication::translate("FenClient", "Message :", nullptr));
        boutonEnvoyer->setText(QCoreApplication::translate("FenClient", "Envoyer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FenClient: public Ui_FenClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TCPCLIENT_H
