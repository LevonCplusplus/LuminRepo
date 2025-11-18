#ifndef SUCCESSFORM_H
#define SUCCESSFORM_H
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPixmap>
#include <QPushButton>
#include <QLabel>
#include <QComboBox>
#include <QIcon>
#include <QListView>

class SuccessForm: public QWidget{
    Q_OBJECT
public:
    SuccessForm(QWidget* parent = nullptr);
};

#endif // SUCCESSFORM_H
