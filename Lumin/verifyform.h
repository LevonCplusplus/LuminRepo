#ifndef VERIFYFORM_H
#define VERIFYFORM_H
#include <QWidget>
#include <QIcon>
#include <QWidget>
#include <QLabel>
#include <QPixmap>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QTimer>

#include "multipleedit.h"


class VerifyForm: public QWidget{

public:
    VerifyForm(QWidget * patrent = nullptr);
};

#endif // VERIFYFORM_H
