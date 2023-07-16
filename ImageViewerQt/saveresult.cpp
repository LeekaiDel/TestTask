#include "saveresult.h"
#include "ui_saveresult.h"

SaveResult::SaveResult(QWidget *parent, QImage *image) :
    QDialog(parent),
    ui(new Ui::SaveResult)
{
    ui->setupUi(this);
    image_ = image;
}

SaveResult::~SaveResult()
{
    delete ui;
}

void SaveResult::on_buttCancel_clicked()
{
    this->close();
}


void SaveResult::on_buttSave_clicked()
{
    if(!SaveResult::image_->isNull())
    {
        SaveResult::image_->save(ui->enterLine->text());
        this->close();
    }
}

