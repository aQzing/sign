#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "codewidget.h"
#include "datawidget.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    cw = new CodeWidget();
    dw = new DataWidget();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_code_btn_clicked()
{
    cw->setWindowTitle("qt签到系统-二维码生成");
    cw->show();
}

void MainWindow::on_sign_btn_clicked()
{
    dw->setWindowTitle("qt签到系统-数据查询");
    dw->show();
}
