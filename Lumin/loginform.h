#ifndef LOGINFORM_H
#define LOGINFORM_H
#include <QStackedWidget>
#include <QResizeEvent>
#include <QDebug>
#include <QIcon>
#include <QWidget>
#include <QLabel>
#include <QPixmap>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QCheckBox>

#include "registerform.h"
#include "verifyform.h"

class LoginForm : public QWidget
{
    Q_OBJECT
public:
    explicit LoginForm(QWidget* parent = nullptr);

protected:
    void resizeEvent(QResizeEvent* event) override;

private:
    QHBoxLayout* mainLayout;
    QLabel* labelForPhoto;
    QPixmap pixmap;
};


#endif // LOGINFORM_H
