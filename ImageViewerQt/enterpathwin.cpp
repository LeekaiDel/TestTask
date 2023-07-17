#include "enterpathwin.h"
#include "ui_enterpathwin.h"

EnterPathWin::EnterPathWin(QWidget *parent, QImage *image, QImage *preview_image) :
    QMainWindow(parent),
    ui(new Ui::EnterPathWin)
{
    ui->setupUi(this);
    this->setWindowTitle("Enter path");
    image_ = image;
    preview_image_ = preview_image;
}

EnterPathWin::~EnterPathWin()
{
    delete ui;
}

void EnterPathWin::on_ButtCancel_clicked()
{
    this->close();
}


void EnterPathWin::on_ButtEnter_clicked()
{
    *image_ = QImage("/home/leekai/TestTask/ImageViewerQt/6.jpg"); //ui->lineEdit->text()
    if (!image_->isNull())
    {
        *preview_image_ = *image_;
        this-close();
    }
}
