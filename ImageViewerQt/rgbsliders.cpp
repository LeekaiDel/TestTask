#include "rgbsliders.h"
#include "ui_rgbsliders.h"

RGBSliders::RGBSliders(QWidget *parent, QImage *origin_image, QImage *preview_image) :
    QDialog(parent),
    ui(new Ui::RGBSliders)
{
    origin_image_ = origin_image;
//    preview_image_ = new QImage(origin_image->width(), origin_image->height(), QImage::Format_RGB32);
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

    // int delta_slider_r = ui->sliderR->value() - last_slider_r_pose;
    // int delta_slider_g = ui->sliderG->value() - last_slider_g_pose;
    // int delta_slider_b = ui->sliderB->value() - last_slider_b_pose;

    for(int h = 0; h < preview_image_->height(); ++h)
    {
        QRgb *row = (QRgb *)origin_image_->scanLine(h);
        for(int w = 0; w < preview_image_->width(); ++w)
        {
            // RED
            int new_r = qRed(row[w]) + ui->sliderR->value();
            if (new_r < 0)
                new_r = 0;
            if (new_r > 255)
                new_r = 255;
            
            // GREEN
            int new_g = qGreen(row[w]) + ui->sliderG->value();
            if (new_g < 0)
                new_g = 0;
            if (new_g > 255)
                new_g = 255;

            // BLUE
            int new_b = qBlue(row[w]) + ui->sliderB->value();
            if (new_b < 0)
                new_b = 0;
            if (new_b > 255)
                new_b = 255;
            
            preview_image_->setPixel(w, h, qRgb(new_r, new_g, new_b));
        }
    }

    // last_slider_r_pose = ui->sliderR->value();
    // last_slider_g_pose = ui->sliderG->value();
    // last_slider_b_pose = ui->sliderB->value();
}


void RGBSliders::on_sliderR_sliderMoved(int position)
{
    ui->labelValueR->setText(QString::fromStdString(std::to_string(ui->sliderR->value())));
    RGBSliders::setRgbChannels();
}

void RGBSliders::on_sliderG_sliderMoved(int position)
{
    ui->labelValueG->setText(QString::fromStdString(std::to_string(position)));
    RGBSliders::setRgbChannels();
}

void RGBSliders::on_sliderB_sliderMoved(int position)
{
    ui->labelValueB->setText(QString::fromStdString(std::to_string(position)));
    RGBSliders::setRgbChannels();
}

void RGBSliders::on_RGBSliders_finished(int result)
{
    *origin_image_ = *preview_image_;
}

