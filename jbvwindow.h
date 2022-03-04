#ifndef JBVWINDOW_H
#define JBVWINDOW_H

#include <QMainWindow>
#include "common/vpushbutton.h"

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

    // 左侧导航栏按钮
    VPushButton* leftNavBtn;
    // 左侧导航窗口
    QMainWindow* leftNavDialog;
    // 右侧主窗口
    QWidget* mainDialog;

private:
    // 初始化界面
    void initUI();

};
#endif // JBVWINDOW_H
