#include "vpushbutton.h"

#include <QPainter>
#include <QStyleOptionButton>
#include <QDebug>
#include <QStylePainter>

VPushButton::VPushButton(QWidget *parent)
    : QPushButton(parent)
{ }

VPushButton::VPushButton(const QString &text, QWidget *parent)
    : QPushButton(text, parent)
{ }

VPushButton::VPushButton(const QIcon &icon, const QString &text, QWidget *parent)
    : QPushButton(icon, text, parent)
{ }

QSize VPushButton::sizeHint() const
{
    QSize sh = QPushButton::sizeHint();

    if (mOrientation != VPushButton::Horizontal)
    {
        sh.transpose();
    }

    return sh;
}

void VPushButton::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QStylePainter painter(this);
    QStyleOptionButton option;
    initStyleOption(&option);

    if (mOrientation == VPushButton::VerticalTopToBottom)
    {
        painter.rotate(90);
        painter.translate(0, -1 * width());
        option.rect = option.rect.transposed();
    }

    else if (mOrientation == VPushButton::VerticalBottomToTop)
    {
        painter.rotate(-90);
        painter.translate(-1 * height(), 0);
        option.rect = option.rect.transposed();
    }

    painter.drawControl(QStyle::CE_PushButton, option);
}

VPushButton::Orientation VPushButton::orientation() const
{
    return mOrientation;
}

void VPushButton::setOrientation(const VPushButton::Orientation &orientation)
{
    mOrientation = orientation;
}
