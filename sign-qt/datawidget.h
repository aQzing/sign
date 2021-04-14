#ifndef DATAWIDGET_H
#define DATAWIDGET_H
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QWidget>

namespace Ui {
class DataWidget;
}

class DataWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DataWidget(QWidget *parent = 0);
    ~DataWidget();

private slots:
    void on_pushButton_clicked();

private:
    Ui::DataWidget *ui;
     QSqlDatabase db;
};

#endif // DATAWIDGET_H
