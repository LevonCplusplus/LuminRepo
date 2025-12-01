#include "multipleedit.h"
#include <QDebug>
UnderlinedLineEdit::UnderlinedLineEdit(QWidget* parent)
    : QLineEdit(parent)
{
    setFixedSize(60,60);
    setMaxLength(1);
    setAlignment(Qt::AlignHCenter);
    setStyleSheet("font-size: 32px;"
                  "font-weight: medium;"
                  "border:1px solid #dfe1e7;"
                  "border-radius: 8px;"
                  "border: 1px solid #dfe1e7;"
                  );
}

void UnderlinedLineEdit::paintEvent(QPaintEvent* event) {
    QLineEdit::paintEvent(event);
    QPainter painter(this);

    QRect r = rect();
    r.adjust(0, 0, 0, -4);

    QFont f = font();
    f.setWeight(QFont::Normal);
    painter.setFont(f);

    if (text().isEmpty()) {
        painter.setPen(QColor("#dfe1e7"));
        painter.drawText(r, Qt::AlignHCenter | Qt::AlignBottom, "_");
    } else {
        painter.setPen(QColor("#499a79"));
        painter.drawText(r, Qt::AlignHCenter | Qt::AlignBottom, "_");
    }
}


MultipleEdit::MultipleEdit(int n, QWidget* parent)
    : QWidget(parent), length(n)
{
    QHBoxLayout* mainlayout = new QHBoxLayout(this);
    mainlayout->setSpacing(12);

    for (int i = 0; i < length; ++i) {
        UnderlinedLineEdit* edit = new UnderlinedLineEdit(this);
        edit->setFixedSize(60,60);

        boxes.push_back(edit);
        mainlayout->addWidget(edit);

        connect(edit, &QLineEdit::textChanged, this, [=](const QString &txt){
            edit->setStyleSheet("font-size: 32px;"
                                "font-weight: medium;"
                                "border:1px solid #499a79;"
                                "border-radius: 8px;"
                                );
            onTextChanged(i, txt);
            editFilled();
        });
    }
    mainlayout->addStretch();
}


void MultipleEdit::editFilled(){
    bool cond = true;
    for(auto line: boxes){
        cond &= !line->text().isEmpty();
    }
    emit allFilled(cond);
}
void MultipleEdit::onTextChanged(int index, const QString &txt) {
   // UnderlinedLineEdit* current = boxes[index];
    if (!txt.isEmpty() && index < length - 1) {
        boxes[index+1]->setFocus();
    }

    // if (txt.length() > 1) {
    //     int pos = index;
    //     for (int k = 0; k < txt.length() && pos < length; ++k, ++pos) {
    //         boxes[pos]->blockSignals(true);
    //         boxes[pos]->setText(QString(txt[k]));
    //         boxes[pos]->blockSignals(false);
    //     }
    //     for (int p = index; p < length; ++p) {
    //         if (boxes[p]->text().isEmpty()) {
    //             boxes[p]->setFocus();
    //             return;
    //         }
    //     }
    //     boxes[length-1]->setFocus();
    //}
}
QString MultipleEdit::txt(){
    QString text;
    for(auto line : boxes){
        text += line->text();
    }
    qDebug() << text;
    return text;
}
