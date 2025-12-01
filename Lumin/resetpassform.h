#ifndef RESETPASSFORM_H
#define RESETPASSFORM_H

#include <QWidget>
#include <QIcon>
#include <QWidget>
#include <QLabel>
#include <QPixmap>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>

#include "passwordhintwidget.h"

class ResetPassForm: public QWidget{
    Q_OBJECT
signals:
    void onBackToLoginClicked();

public:
    ResetPassForm(QWidget* parent = nullptr);
};

#endif // RESETPASSFORM_H
