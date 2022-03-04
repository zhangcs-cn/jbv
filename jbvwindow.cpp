#include "jbvwindow.h"
#include "ui_jbvwindow.h"

JBVWindow::JBVWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::JBVWindow)
{
    ui->setupUi(this);
}

JBVWindow::~JBVWindow()
{
    delete ui;
}

