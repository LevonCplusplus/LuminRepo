// #ifndef MULTIPLEEDIT_H
// #define MULTIPLEEDIT_H
// #include <QWidget>
// #include <QLineEdit>
// #include <QHBoxLayout>
// #include <QPainter>
// #include <vector>

// class UnderlinedLineEdit : public QLineEdit {
//     Q_OBJECT
// public:
//     explicit UnderlinedLineEdit(QWidget* parent = nullptr);
// protected:
//     void paintEvent(QPaintEvent* event)override;

// };

// // class MultipleEdit : public QWidget {
// //     Q_OBJECT
// // public:
// //     explicit MultipleEdit(int n, QWidget* parent = nullptr);
// //     QString txt();
// // signals:
// //     void allFilled(bool cond);
// // private:
// //     int length;
// //     std::vector<UnderlinedLineEdit*> boxes;
// //     void editFilled();
// //     void onTextChanged(int index, const QString &txt);
// // };

// class MultipleEdit : public QWidget
// {
//     Q_OBJECT

// public:
//     explicit MultipleEdit(int n, QWidget* parent = nullptr);

//     QString txt() const;
//     void pasteText(const QString& text);

// signals:
//     void allFilled(bool condition);

// private slots:
//     void editFilled();
//     void onTextChanged(int index, const QString& txt);

// private:
//     void setupPasteShortcut();

//     int length;
//     QVector<UnderlinedLineEdit*> boxes;
// };

// #endif // MULTIPLEEDIT_H

#ifndef MULTIPLEEDIT_H
#define MULTIPLEEDIT_H

#include <QWidget>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVector>
#include <QPainter>
#include <QKeyEvent>

class UnderlinedLineEdit : public QLineEdit
{
    Q_OBJECT

public:
    explicit UnderlinedLineEdit(QWidget* parent = nullptr);

protected:
    void paintEvent(QPaintEvent* event) override;
    void keyPressEvent(QKeyEvent* event) override;
};

class MultipleEdit : public QWidget
{
    Q_OBJECT

public:
    explicit MultipleEdit(int n, QWidget* parent = nullptr);

    QString txt() const;
    void pasteText(const QString& text);

signals:
    void allFilled(bool condition);

private slots:
    void editFilled();
    void onTextChanged(int index, const QString& txt);

protected:
    void keyPressEvent(QKeyEvent* event) override;

private:
    void setupPasteShortcut();

    int length;
    QVector<UnderlinedLineEdit*> boxes;
};

#endif // MULTIPLEEDIT_H

