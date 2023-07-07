#include "enterpathwin.h"
#include "ui_enterpathwin.h"

EnterPathWin::EnterPathWin(QWidget *parent, QImage *image) :
    QMainWindow(parent),
    ui(new Ui::EnterPathWin)
{
    ui->setupUi(this);
    this->setWindowTitle("Enter path");
    image_ = image;
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
    *image_ = QImage(ui->lineEdit->text());
    if (!image_->isNull())
    {
        this-close();
    }
}
