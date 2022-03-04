#ifndef JBVWINDOW_H
#define JBVWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class JBVWindow; }
QT_END_NAMESPACE

class JBVWindow : public QMainWindow
{
    Q_OBJECT

public:
    JBVWindow(QWidget *parent = nullptr);
    ~JBVWindow();

private:
    Ui::JBVWindow *ui;
};
#endif // JBVWINDOW_H
