#include "multipleedit.h"
#include <QDebug>
#include <QShortcut>
#include <QApplication>
#include <QClipboard>
#include <QRegularExpression>
#include <QPainter>
#include <QPaintEvent>
#include <QKeyEvent>

UnderlinedLineEdit::UnderlinedLineEdit(QWidget* parent)
    : QLineEdit(parent)
{
    setFixedSize(60, 60);
    setMaxLength(1);
    setAlignment(Qt::AlignHCenter);
    setStyleSheet(
        "font-size: 32px;"
        "font-weight: medium;"
        "border: 1px solid #dfe1e7;"
        "border-radius: 8px;"
        "background-color: white;"
        );
}

void UnderlinedLineEdit::keyPressEvent(QKeyEvent* event)
{
    if (event->matches(QKeySequence::Paste)) {
        event->ignore();
        return;
    }

    if (event->key() >= Qt::Key_0 && event->key() <= Qt::Key_9) {
        setText(event->text());
        return;
    }

    if (event->key() == Qt::Key_Backspace) {
        clear();
        return;
    }
    QLineEdit::keyPressEvent(event);
}

void UnderlinedLineEdit::paintEvent(QPaintEvent* event)
{
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
        boxes.push_back(edit);
        mainlayout->addWidget(edit);

        connect(edit, &QLineEdit::textChanged, this, [=](const QString& txt) {
            edit->setStyleSheet(
                "font-size: 32px;"
                "font-weight: medium;"
                "border: 1px solid #499a79;"
                "border-radius: 8px;"
                "background-color: white;"
                );
            onTextChanged(i, txt);
            editFilled();
        });
    }
    mainlayout->addStretch();

    setupPasteShortcut();
    setFocusPolicy(Qt::StrongFocus);
}

void MultipleEdit::setupPasteShortcut()
{
    QShortcut* pasteShortcut = new QShortcut(QKeySequence::Paste, this);

    connect(pasteShortcut, &QShortcut::activated, this, [this]() {
        QClipboard* clipboard = QApplication::clipboard();
        QString clipboardText = clipboard->text();

        if (clipboardText.isEmpty()) {
            return;
        }

        clipboardText.remove(QRegularExpression("[^0-9]"));

        qDebug() << "Pasting text:" << clipboardText;

        if (!clipboardText.isEmpty()) {
            int startIndex = 0;
            for (int i = 0; i < boxes.size(); ++i) {
                if (boxes[i]->hasFocus() || boxes[i]->text().isEmpty()) {
                    startIndex = i;
                    break;
                }
            }

            int textIndex = 0;
            for (int i = startIndex; i < boxes.size() && textIndex < clipboardText.length(); ++i) {
                boxes[i]->blockSignals(true);
                boxes[i]->setText(QString(clipboardText[textIndex]));
                boxes[i]->blockSignals(false);
                textIndex++;
            }

            int nextIndex = startIndex + clipboardText.length();
            if (nextIndex < boxes.size()) {
                boxes[nextIndex]->setFocus();
            } else if (!boxes.isEmpty()) {
                boxes.last()->setFocus();
            }

            editFilled();
        }
    });
}

void MultipleEdit::keyPressEvent(QKeyEvent* event)
{
    if (event->matches(QKeySequence::Paste)) {
        QClipboard* clipboard = QApplication::clipboard();
        QString clipboardText = clipboard->text();

        if (!clipboardText.isEmpty()) {
            clipboardText.remove(QRegularExpression("[^0-9]"));

            if (!clipboardText.isEmpty()) {
                int startIndex = 0;
                QWidget* focused = focusWidget();
                for (int i = 0; i < boxes.size(); ++i) {
                    if (boxes[i] == focused) {
                        startIndex = i;
                        break;
                    }
                }

                for (int i = 0; i < clipboardText.length() && (startIndex + i) < boxes.size(); ++i) {
                    boxes[startIndex + i]->blockSignals(true);
                    boxes[startIndex + i]->setText(QString(clipboardText[i]));
                    boxes[startIndex + i]->blockSignals(false);
                }

                int nextIndex = startIndex + clipboardText.length();
                if (nextIndex < boxes.size()) {
                    boxes[nextIndex]->setFocus();
                }

                editFilled();
                return;
            }
        }
    }

    QWidget::keyPressEvent(event);
}

void MultipleEdit::pasteText(const QString& text)
{
    if (text.isEmpty()) return;

    QString cleanedText = text;
    cleanedText.remove(QRegularExpression("[^0-9]"));

    if (cleanedText.isEmpty()) return;

    int startIndex = 0;
    for (int i = 0; i < boxes.size(); ++i) {
        if (boxes[i]->hasFocus()) {
            startIndex = i;
            break;
        }
    }

    for (int i = 0; i < cleanedText.length() && (startIndex + i) < boxes.size(); ++i) {
        boxes[startIndex + i]->blockSignals(true);
        boxes[startIndex + i]->setText(QString(cleanedText[i]));
        boxes[startIndex + i]->blockSignals(false);
    }

    int nextIndex = startIndex + cleanedText.length();
    if (nextIndex < boxes.size()) {
        boxes[nextIndex]->setFocus();
    } else if (!boxes.isEmpty()) {
        boxes.last()->setFocus();
    }

    editFilled();
}

void MultipleEdit::editFilled()
{
    bool cond = true;
    for (auto line : boxes) {
        cond &= !line->text().isEmpty();
    }
    emit allFilled(cond);
}

void MultipleEdit::onTextChanged(int index, const QString& txt)
{
    if (!txt.isEmpty() && index < length - 1) {
        boxes[index + 1]->setFocus();
    }

    if (txt.length() > 1) {
        for (int i = 1; i < txt.length() && (index + i) < boxes.size(); ++i) {
            boxes[index + i]->blockSignals(true);
            boxes[index + i]->setText(QString(txt[i]));
            boxes[index + i]->blockSignals(false);
        }

        int nextIndex = index + txt.length();
        if (nextIndex < boxes.size()) {
            boxes[nextIndex]->setFocus();
        }
    }
}

QString MultipleEdit::txt() const
{
    QString text;
    for (auto line : boxes) {
        text += line->text();
    }
    qDebug() << "MultipleEdit OTP code:" << text;
    return text;
}
//123456
