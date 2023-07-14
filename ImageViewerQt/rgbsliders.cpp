#include "rgbsliders.h"
#include "ui_rgbsliders.h"

RGBSliders::RGBSliders(QWidget *parent, QImage *origin_image, QImage *preview_image) :
    QDialog(parent),
    ui(new Ui::RGBSliders)
{
    origin_image_ = origin_image;
    preview_image_ = preview_image;

    ui->setupUi(this);
    this->setWindowTitle("RGB Sliders");
    ui->labelValueR->setText(QString::fromStdString(std::to_string(ui->sliderR->value())));
    ui->labelValueG->setText(QString::fromStdString(std::to_string(ui->sliderG->value())));
    ui->labelValueB->setText(QString::fromStdString(std::to_string(ui->sliderB->value())));
}

RGBSliders::~RGBSliders()
{
    delete ui;
}

void RGBSliders::setRgbChannels()
{
    for(int h = 0; h < preview_image_->height(); ++h)
    {
        QRgb *row = (QRgb *)origin_image_->scanLine(h);
        for(int w = 0; w < preview_image_->width(); ++w)
        {
            // RED
            int new_r = qRed(row[w]) + slider_r_pose;
            if (new_r < 0)
                new_r = 0;
            if (new_r > 255)
                new_r = 255;
            
            // GREEN
            int new_g = qGreen(row[w]) + slider_g_pose;
            if (new_g < 0)
                new_g = 0;
            if (new_g > 255)
                new_g = 255;

            // BLUE
            int new_b = qBlue(row[w]) + slider_b_pose;
            if (new_b < 0)
                new_b = 0;
            if (new_b > 255)
                new_b = 255;
            
            preview_image_->setPixel(w, h, qRgb(new_r, new_g, new_b));
        }
    }
}


void RGBSliders::on_sliderR_sliderMoved(int position)
{
    slider_r_pose = position;
    ui->labelValueR->setText(QString::fromStdString(std::to_string(position)));
    RGBSliders::setRgbChannels();
}

void RGBSliders::on_sliderG_sliderMoved(int position)
{
    slider_g_pose = position;
    ui->labelValueG->setText(QString::fromStdString(std::to_string(position)));
    RGBSliders::setRgbChannels();
}

void RGBSliders::on_sliderB_sliderMoved(int position)
{
    slider_b_pose = position;
    ui->labelValueB->setText(QString::fromStdString(std::to_string(position)));
    RGBSliders::setRgbChannels();
}

void RGBSliders::on_RGBSliders_finished(int result)
{
    *origin_image_ = *preview_image_;
}

