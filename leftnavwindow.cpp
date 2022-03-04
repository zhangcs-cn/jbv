#include "leftnavwindow.h"

#include <QBoxLayout>
#include <QPushButton>
#include <QToolBar>

LeftNavWindow::LeftNavWindow(bool isShow) : QMainWindow()
{
    showLeftNavFlag = isShow;
    this->setHidden(!showLeftNavFlag);

    this->initUI();
}

void LeftNavWindow::initUI() {
    this->setMaximumWidth(200);
    this->setAutoFillBackground(true);

    // left nav tool bar
    auto toolBar = new QToolBar();
    toolBar->setMovable(false);

    leftNavToolBarCloseBtn = new QPushButton();
    leftNavToolBarCloseBtn->setText("-");
    leftNavToolBarCloseBtn->setToolTip("收起");
    leftNavToolBarCloseBtn->setStyleSheet("border: 0;padding: 2 5");
    connect(leftNavToolBarCloseBtn, &QPushButton::clicked, [=](){
        showLeftNav();
    });

    QWidget* leftNavToolBarSpacer = new QWidget();
    leftNavToolBarSpacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    toolBar->addWidget(leftNavToolBarSpacer);
    toolBar->addWidget(leftNavToolBarCloseBtn);
    toolBar->setMaximumHeight(20);

    this->addToolBar(toolBar);
}

void LeftNavWindow::showLeftNav() {
    showLeftNavFlag = !showLeftNavFlag;
    this->setHidden(!showLeftNavFlag);
}
