#include "transactions.h"

Transactions::Transactions(QWidget *parent)
    : QLabel{parent}
{
    this->setStyleSheet(
        "   border: 1px solid #eeeeee;"
        "   background-color: #ffffff;"
        "   border-radius: 12px;"
        );

    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    QLabel* header = new QLabel("Transactions");
    header->setStyleSheet(" font-family: 'Outfit';"
                          " border: none;"
                          " font-weight: 600;"
                          " font-size: 24px;"
                          " line-height: 150%;"
                          " letter-spacing: 0%;"
                          " color: #1b1b1b;");
    QLabel* lowHeader = new QLabel("View and manage all payment transactions");
    lowHeader->setStyleSheet(" font-family: 'Outfit';"
                             " font-weight: 400;"
                             " border: none;"
                             " font-size: 16px;"
                             " line-height: 150%;"
                             " letter-spacing: 0%;"
                             " color: #838383;");

    QLabel* totalLabel = new QLabel;
    totalLabel->setFixedHeight(205);
    QVBoxLayout* totalLayout = new QVBoxLayout(totalLabel);
    QLabel* totalHeader = new QLabel("Total Revenue");
    totalHeader->setStyleSheet(" font-family: 'Outfit';"
                                " border: none;"
                                " font-weight: 500;"
                                " font-size: 18px;"
                                " line-height: 150%;"
                                " letter-spacing: 0%;"
                                " color: #111113;"
                               );
    QLabel* totalLowHeader = new QLabel("All-time platform revenue");
    totalLowHeader->setStyleSheet(" font-family: 'Outfit';"
                                    " border: none;"
                                    " font-weight: 400;"
                                    " font-size: 14px;"
                                    " line-height: 140%;"
                                    " letter-spacing: 0%;"
                                    " color: #838383;"
                                    );

    double val = 0.00;
    QLabel* totalVal = new QLabel("$" + QString::number(val,'f',2));
    totalVal->setStyleSheet(" font-family: 'Outfit';"
                            " border: none;"
                            " font-weight: 500;"
                            " font-size: 32px;"
                            " line-height: 120%;"
                            " letter-spacing: 0%;"
                            " color: #111113;"
                            );
    QLabel* textLabel = new QLabel("Revenue will appear here once students start purchasing courses");
    textLabel->setStyleSheet(" font-family: 'Outfit';"
                             " border: none;"
                             " font-weight: 400;"
                             " font-size: 12px;"
                             " line-height: 155%;"
                             " letter-spacing: 0%;"
                             " color: #838383;"
                             );
    totalLayout->addWidget(totalHeader);
    totalLayout->addWidget(totalLowHeader);
    totalLayout->addWidget(totalVal);
    totalLayout->addWidget(textLabel);

    mainLayout->setContentsMargins(24,24,24,0);
    mainLayout->addWidget(header,0,Qt::AlignLeft);
    mainLayout->addWidget(lowHeader,0,Qt::AlignLeft);
    mainLayout->addSpacing(24);
    mainLayout->addWidget(totalLabel);
    mainLayout->addStretch();
}
