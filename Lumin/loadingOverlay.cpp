#include "loadingOverlay.h"

 LoadingOverlay::LoadingOverlay(QWidget* parent)
    : QWidget(parent)
{
     if (parentWidget())
         setGeometry(parentWidget()->rect());



    hide();

    spinner = new RotatingLabel(this);
    spinner->setFixedSize(50,50);
    spinner->setAttribute(Qt::WA_TranslucentBackground);
    QPixmap pix(":/images/luminIcon.png");
    spinner->setPixmap(pix.scaled(32,32,Qt::KeepAspectRatio,Qt::SmoothTransformation));
    spinner->move(width()/2 - spinner->width()/2, height()/2 - spinner->height()/2);

    anim = new QPropertyAnimation(spinner, "angle", this);
    anim->setStartValue(0);
    anim->setEndValue(360);
    anim->setDuration(1000);
    anim->setLoopCount(-1);
}

void LoadingOverlay::start() {
    if(parentWidget())
        setGeometry(parentWidget()->rect());
    show();
    spinner->show();
    anim->start();
    QTimer::singleShot(10000,[this]() {
        anim->stop();
        spinner->hide();
        this->hide();
    });
}

void LoadingOverlay::stop() {
    anim->stop();
    spinner->hide();
    hide();
}

void LoadingOverlay::resizeEvent(QResizeEvent* event) {
    if(parentWidget())
        setGeometry(parentWidget()->rect());
    spinner->move(width()/2 - spinner->width()/2, height()/2 - spinner->height()/2);
    QWidget::resizeEvent(event);
}
void LoadingOverlay::paintEvent(QPaintEvent* ) {
    QPainter p(this);
    p.fillRect(rect(), QColor(0,0,0,100)); // полупрозрачный черный фон
}
