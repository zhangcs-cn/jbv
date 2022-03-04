#include "jbvwindow.h"
#include "ui_jbvwindow.h"

#include "common/vpushbutton.h"

#include <leftnavwindow.h>
#include <QHBoxLayout>

JBVWindow::JBVWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::JBVWindow)
{
    ui->setupUi(this);
    // 初始化界面
    initUI();
}

JBVWindow::~JBVWindow()
{
    delete ui;
}

void JBVWindow::initUI() {
    // 左侧导航栏按钮
    leftNavBtn = new VPushButton("Project", this);
    leftNavBtn->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Minimum);
    leftNavBtn->setOrientation(VPushButton::VerticalBottomToTop);
    leftNavBtn->setStyleSheet("color: #000;border: 0;padding: 2 10");
    ui->toolBar->addWidget(leftNavBtn);

    QHBoxLayout* layout = new QHBoxLayout();
    layout->setContentsMargins(0,0,0,0);
    layout->setSpacing(1);

    LeftNavWindow* leftNavWindow = new LeftNavWindow(true);
    layout->addWidget(leftNavWindow);

    connect(leftNavBtn, &QPushButton::clicked, leftNavWindow, [=](){
        leftNavWindow->showLeftNav();
    });

    // 右侧主窗口
    mainDialog = new QWidget();
    mainDialog->setAutoFillBackground(true);
//    mainDialog->setStyleSheet("background-color: blue");
    mainDialog->setContentsMargins(0,0,0,0);
    layout->addWidget(mainDialog);

    QWidget* central = ui->centralwidget;
    central->setLayout(layout);
    central->show();
}
