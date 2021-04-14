#ifndef CODEWIDGET_H
#define CODEWIDGET_H

#include <QWidget>

namespace Ui {
class CodeWidget;
}

class CodeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CodeWidget(QWidget *parent = 0);
    ~CodeWidget();

private slots:
    void on_code_btn_clicked();

    void on_save_btn_clicked();

private:
    Ui::CodeWidget *ui;
    QPixmap qrPixmap;
};

#endif // CODEWIDGET_H
