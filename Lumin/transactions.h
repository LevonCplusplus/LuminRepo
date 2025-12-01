#ifndef TRANSACTIONS_H
#define TRANSACTIONS_H
#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>

class Transactions : public QLabel{
    Q_OBJECT
public:
    explicit Transactions(QWidget *parent = nullptr);

signals:
};

#endif // TRANSACTIONS_H
