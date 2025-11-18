#include "passwordhintwidget.h"

PasswordHintWidget::PasswordHintWidget(QWidget* parent):QWidget(parent)
{
    this->setFixedSize(432, 260);
    rows.reserve(5);
    rows.push_back({"At least 8 characters", false});
    rows.push_back({"Only latin letters (A-Z, a-z)", false});
    rows.push_back({"At least 1 uppercase and lowercase  letters", false});
    rows.push_back({"At least 1 number", false});
    rows.push_back({"-_*/?!  At least 1 special symbol", false});
    validEdit = false;
}

void PasswordHintWidget::paintEvent(QPaintEvent* ){

    QPainter painter(this);
    QPixmap pixmap(":/images/passwordHint.png");
    QPixmap scaled = pixmap.scaled(420, 239, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    painter.drawPixmap(rect() ,scaled);

    QPixmap pixmapValid(":/images/valid.png");
    QPixmap scaledValid = pixmapValid.scaled(25, 25, Qt::KeepAspectRatio, Qt::SmoothTransformation);

    QPixmap pixmapNoneValid(":/images/nonevalid.png");
    QPixmap scaledNoneValid = pixmapNoneValid.scaled(25,25,Qt::KeepAspectRatio, Qt::SmoothTransformation);
    painter.fillRect(10,10,410,220,Qt::white);



    QFont font;
    font.setPointSize(12);
    font.setWeight(QFont::DemiBold);
    painter.setFont(font);
    painter.setPen(Qt::black);
    painter.drawText(30,40,"Password must contain");


    font.setWeight(440);
    painter.setFont(font);

    for (int i = 0; i < 5; ++i){
        if(rows[i].valid){
            painter.drawPixmap(30, i*35 + 60 , 25, 25, scaledValid );
            painter.setPen(Qt::black);
            painter.drawText(65, i*35 + 79 ,rows[i].line);
        }
        else{
            painter.drawPixmap(30, i*35 + 60 , 25, 25, scaledNoneValid );
            painter.setPen(QColor("#a6a6a6"));
            painter.drawText(65, i*35 + 79 ,rows[i].line);
        }
    }
}
bool PasswordHintWidget::validationUpdate(const QString& str){

    QRegularExpression reLetters("^[A-Za-z\\-_!?\\=\\0-9\\+]+$");
    QRegularExpression reUpperLower("^(?=.*[A-Z])(?=.*[a-z]).+$");
    QRegularExpression re1("^(?=.*[a-z]).+$");
    QRegularExpression re2("^(?=.*[A-Z]).+$");
    QRegularExpression reDigit(".*[0-9].*");
    QRegularExpression reSpecial(".*[-_*/?!].*");
    rows[0].valid = str.length() >= 8;
    rows[1].valid = reLetters.match(str).hasMatch();
    rows[2].valid = reUpperLower.match(str).hasMatch();
    rows[3].valid = reDigit.match(str).hasMatch();
    rows[4].valid = reSpecial.match(str).hasMatch();
    rows[1].valid &= re1.match(str).hasMatch() || re2.match(str).hasMatch();
    return rows[0].valid & rows[1].valid & rows[2].valid & rows[3].valid & rows[4].valid;
}
