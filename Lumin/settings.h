#ifndef SETTINGS_H
#define SETTINGS_H

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLineEdit>

#include "user.h"

class Settings : public QWidget
{
    Q_OBJECT
public:
    explicit Settings(const User* user,QWidget *parent = nullptr);

signals:
    void onSaveChangesClicked(const QString& str1, const QString& str2, const QString& str3);
private:
    const User* user;
};

#endif // SETTINGS_H
