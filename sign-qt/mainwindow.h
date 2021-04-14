#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<codewidget.h>
#include <QMainWindow>
#include<datawidget.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_code_btn_clicked();

    void on_sign_btn_clicked();

private:
    Ui::MainWindow *ui;
    CodeWidget *cw;
    DataWidget *dw;

};

#endif // MAINWINDOW_H
