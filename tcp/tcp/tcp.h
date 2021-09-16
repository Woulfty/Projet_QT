#pragma once

#include <QtWidgets/QWidget>
#include <ActiveQt/QAxBindable>

#include "ui_tcp.h"

class tcp : public QWidget, public QAxBindable
{
    Q_OBJECT

public:
    tcp(QWidget *parent = Q_NULLPTR);

private:
    Ui::tcpClass ui;
};
