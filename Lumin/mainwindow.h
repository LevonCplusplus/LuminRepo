#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QWidget>
#include "loginform.h"
#include "registerform.h"

class MainWIndow:public QMainWindow{
    Q_OBJECT

public:
    MainWIndow(QWidget* parent = nullptr);
};

#endif // MAINWINDOW_H
