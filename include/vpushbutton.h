#ifndef VPUSHBUTTON_H
#define VPUSHBUTTON_H

#include <QPushButton>

class VPushButton : public QPushButton
{
    Q_OBJECT
    public:
        enum Orientation {
            Horizontal,
            VerticalTopToBottom,
            VerticalBottomToTop
        };

        VPushButton(QWidget * parent = nullptr);
        VPushButton(const QString & text, QWidget *parent = nullptr);
        VPushButton(const QIcon & icon, const QString & text, QWidget *parent = nullptr);

        QSize sizeHint() const;

        VPushButton::Orientation orientation() const;
        void setOrientation(const VPushButton::Orientation &orientation);

    protected:
        void paintEvent(QPaintEvent *event);

    private:
        Orientation mOrientation = Horizontal;

};

#endif // VPUSHBUTTON_H
