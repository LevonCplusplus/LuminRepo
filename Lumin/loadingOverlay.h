#ifndef LOADINGOVERLAY_H
#define LOADINGOVERLAY_H

#include <QWidget>
#include <QLabel>
#include <QPropertyAnimation>
#include <QPixmap>
#include <QPainter>
#include <QTimer>

class RotatingLabel : public QLabel
{
    Q_OBJECT
    Q_PROPERTY(qreal angle READ angle WRITE setAngle)
public:
    RotatingLabel(QWidget* parent = nullptr) : QLabel(parent), m_angle(0) {}

    qreal angle() const { return m_angle; }
    void setAngle(qreal a) { m_angle = a; update(); }

protected:
    void paintEvent(QPaintEvent* ) override {
        QPixmap pix = pixmap(Qt::ReturnByValue);
        if (pix.isNull()) return;

        QPainter p(this);
        p.setRenderHint(QPainter::SmoothPixmapTransform);
        p.translate(width()/2.0, height()/2.0);
        p.rotate(m_angle);
        p.translate(-pix.width()/2.0, -pix.height()/2.0);
        p.drawPixmap(0,0,pix);
    }

private:
    qreal m_angle;
};

class LoadingOverlay : public QWidget
{
    Q_OBJECT

public:

    explicit LoadingOverlay(QWidget* parent = nullptr);
    void paintEvent(QPaintEvent* );
    void start();
    void stop();

protected:
    void resizeEvent(QResizeEvent* event) override;
private:

    RotatingLabel* spinner;
    QPropertyAnimation* anim;
};

#endif // LOADINGOVERLAY_H
