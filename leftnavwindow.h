#ifndef LEFTNAVWINDOW_H
#define LEFTNAVWINDOW_H

#include <QBoxLayout>
#include <QMainWindow>
#include <QPushButton>

class LeftNavWindow : public QMainWindow
{
public:
    LeftNavWindow(bool isShow = false);

private:
    // 左侧导航栏
    QMainWindow* leftNavDialog;
    // 左侧导航栏-工具栏-关闭按钮
    QPushButton* leftNavToolBarCloseBtn;

    // 是否展示左侧导航栏
    bool showLeftNavFlag = true;

    void initUI();

public:

    /**
     * @brief showLeftNav 展示导航面板
     */
    void showLeftNav();

};

#endif // LEFTNAVWINDOW_H
