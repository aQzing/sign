#include "datawidget.h"
#include "ui_datawidget.h"
#include <QDebug>
#include<QSqlRecord>
DataWidget::DataWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DataWidget)
{
    ui->setupUi(this);
    qDebug() << QSqlDatabase::drivers();

    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setPort(3306);
    db.setDatabaseName("sign");
    db.setUserName("root");
    db.setPassword("123456");
    bool ok = db.open();

    if (ok)
    {
        qDebug() << "连接数据库ok";
    }
    else
    {
        qDebug() << "连接数据库失败";
    }
// 数据查询测试
//    QSqlQuery query(db);
//    query.exec("select *from dutyinfo");
//    while(query.next()){

//        qDebug()<<query.value(0).toString();

//    }
    QSqlQuery query(db);
    query.exec("select *from user_sign");
    QSqlRecord rec = query.record();
    // 列数
    int columnCount = rec.count();
    // 行数
    int rowCount =  query.size();
    qDebug() << "表的列数：" << columnCount;
    qDebug() << "表的行数：" << rowCount;
    ui->tableWidget->setColumnCount(columnCount);//设置列数
    ui->tableWidget->setRowCount(rowCount);//设置行数
    QStringList m_Header;
    m_Header<<QString("学号")<<QString("姓名")<<QString("打卡地点")<<QString("打卡时间");
    ui->tableWidget->setHorizontalHeaderLabels(m_Header);//添加横向表头
     ui->tableWidget->verticalHeader()->setVisible(true);//纵向表头可视化
     ui->tableWidget->horizontalHeader()->setVisible(true);//横向表头可视化
//    for(int rows=0;rows<rowCount;rows++)
//    {
//        for(int columns=0;columns<columnCount;columns++)
//        {
//            //ui->tableWidget->setColumnWidth(columns,125);
//            ui->tableWidget->setRowHeight(rows,30);
//            ui->tableWidget->item(rows,columns)->setTextAlignment(Qt::AlignCenter);//居中显示
//            //ui->qTableWidget->item(rows,columns)->setBackgroundColor(QColor(85,170,255));//设置前景颜色
//            //ui->qTableWidget->item(rows,columns)->setTextColor(QColor(0,0,0));//设置文本颜色
//            //ui->qTableWidget->item(rows,columns)->setFont(QFont("Helvetica"));//设置字体为黑体

//        }
//    }
    int num = 0;
    while(query.next()){

        for(int columns=0;columns<columnCount;columns++)
        {
            ui->tableWidget->setItem(num,columns,new QTableWidgetItem(query.value(columns).toString()));
            ui->tableWidget->setColumnWidth(columns,200);
            ui->tableWidget->item(num,columns)->setTextAlignment(Qt::AlignCenter);//居中显示

        }
        num++;


    }
   // db.close();

}

DataWidget::~DataWidget()
{
    delete ui;
}
//刷新功能
void DataWidget::on_pushButton_clicked()
{
    QSqlQuery query(db);
    query.exec("select *from user_sign");
    QSqlRecord rec = query.record();
    // 列数
    int columnCount = rec.count();
    // 行数
    int rowCount =  query.size();
    qDebug() << "表的列数：" << columnCount;
    qDebug() << "表的行数：" << rowCount;
    ui->tableWidget->setColumnCount(columnCount);//设置列数
    ui->tableWidget->setRowCount(rowCount);//设置行数
    QStringList m_Header;
    m_Header<<QString("学号")<<QString("姓名")<<QString("打卡地点")<<QString("打卡时间");
    ui->tableWidget->setHorizontalHeaderLabels(m_Header);//添加横向表头
     ui->tableWidget->verticalHeader()->setVisible(true);//纵向表头可视化
     ui->tableWidget->horizontalHeader()->setVisible(true);//横向表头可视化
    int num = 0;
    while(query.next()){

        for(int columns=0;columns<columnCount;columns++)
        {
            ui->tableWidget->setItem(num,columns,new QTableWidgetItem(query.value(columns).toString()));
            ui->tableWidget->setColumnWidth(columns,200);
            ui->tableWidget->item(num,columns)->setTextAlignment(Qt::AlignCenter);//居中显示

        }
        num++;


    }
}
