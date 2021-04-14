#include "codewidget.h"
#include "ui_codewidget.h"
#include <QDebug>
#include <QPainter>
#include <QFileDialog>
#include <QDateTime>
#include "qrencode/qrencode.h"
CodeWidget::CodeWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CodeWidget)
{
    ui->setupUi(this);
}

CodeWidget::~CodeWidget()
{
    delete ui;
}

/**
 * @brief GernerateQRCode
 * 生成二维码函数
 * @param text  二维码内容
 * @param qrPixmap  二维码像素图
 * @param scale 二维码缩放比例
 */
void GernerateQRCode(const QString &text, QPixmap &qrPixmap, int scale)
{
    if(text.isEmpty())
    {
        return;
    }

    //二维码数据
    QRcode *qrCode = nullptr;

    //这里二维码版本传入参数是2,实际上二维码生成后，它的版本是根据二维码内容来决定的
    qrCode = QRcode_encodeString(text.toStdString().c_str(), 2,
                                 QR_ECLEVEL_Q, QR_MODE_8, 1);

    if(nullptr == qrCode)
    {
        return;
    }

    int qrCode_Width = qrCode->width > 0 ? qrCode->width : 1;
    int width = scale * qrCode_Width;
    int height = scale * qrCode_Width;

    QImage image(width, height, QImage::Format_ARGB32_Premultiplied);

    QPainter painter(&image);
    QColor background(Qt::white);
    painter.setBrush(background);
    painter.setPen(Qt::NoPen);
    painter.drawRect(0, 0, width, height);
    QColor foreground(Qt::black);
    painter.setBrush(foreground);
    for(int y = 0; y < qrCode_Width; ++y)
    {
        for(int x = 0; x < qrCode_Width; ++x)
        {
            unsigned char character = qrCode->data[y * qrCode_Width + x];
            if(character & 0x01)
            {
               QRect rect(x * scale, y * scale, scale, scale);
               painter.drawRects(&rect, 1);
            }
        }
    }

    qrPixmap = QPixmap::fromImage(image);
    QRcode_free(qrCode);
}

// 点击生成二维码按钮
void CodeWidget::on_code_btn_clicked()
{
    QString  text = ui->content_pte->toPlainText();
    qDebug()<<"获取输入文本："<<text;

    //QPixmap qrPixmap;
    int width = ui->pic_label->width();
    int height = ui->pic_label->height();
    GernerateQRCode(text, qrPixmap, 3);
    qrPixmap = qrPixmap.scaled(QSize(width, height),
                               Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    ui->pic_label->setPixmap(qrPixmap);


}
// 保存图片
void CodeWidget::on_save_btn_clicked()
{
 //qDebug()<<"保存成功了吗？"<<qrPixmap.save("qrencode.jpg",nullptr,-1);//这里直接就保存为图片
    //文件夹路径
    QString srcDirPath = QFileDialog::getExistingDirectory(
               this, "请选择图片保存的目录",
                "/");

    if (srcDirPath.isEmpty())
    {
        return;
    }
    else
    {
        srcDirPath += "/";
    }
    QString absolutePicName = srcDirPath+QDateTime::currentDateTime().toString("yyyyMMddHHmmszzz")+".jpg";
    qDebug() << "图片路径：" <<absolutePicName  ;
    bool isSave = qrPixmap.save(absolutePicName,nullptr,-1);
    qDebug() << "是否保存成功？" <<isSave;
}


