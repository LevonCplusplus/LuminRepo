#ifndef MULTIPLEEDIT_H
#define MULTIPLEEDIT_H
#include <QWidget>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QPainter>
#include <vector>

class UnderlinedLineEdit : public QLineEdit {
    Q_OBJECT
public:
    explicit UnderlinedLineEdit(QWidget* parent = nullptr);

protected:
    void paintEvent(QPaintEvent* event)override;

};

class MultipleEdit : public QWidget {
    Q_OBJECT
public:
    explicit MultipleEdit(int n, QWidget* parent = nullptr);
signals:
    void allFilled(bool cond);
private:
    int length;
    std::vector<UnderlinedLineEdit*> boxes;
    void editFilled();
    void onTextChanged(int index, const QString &txt);
};

#endif // MULTIPLEEDIT_H
