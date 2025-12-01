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
signals:
    void onStartClicked();
public:
    SuccessForm(const QString& header, const QString& lowHeader, const QString& buttonText,QWidget* parent = nullptr);
    void formUpdate(const QString& header, const QString& lowHeader, const QString& buttonText);
private:
    QPushButton* startButton;
    QLabel* textLabel;
    QLabel* headTextLabel;
};

#endif // SUCCESSFORM_H
