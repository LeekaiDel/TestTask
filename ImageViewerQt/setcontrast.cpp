#include "setcontrast.h"
#include "ui_setcontrast.h"

SetContrast::SetContrast(QWidget *parent, QImage *origin_image, QImage *preview_image) :
    QDialog(parent),
    ui(new Ui::SetContrast)
{
    ui->setupUi(this);
    origin_image_ = origin_image;
    preview_image_ = preview_image;
}

SetContrast::~SetContrast()
{
    delete ui;
}

void SetContrast::setContrast()
{
    // Находим минимумы и максимумы яркости для каждого канала
//    for (int h = 0; h < origin_image_->height(); ++h)
//    {
//        QRgb *row = (QRgb *)origin_image_->scanLine(h);
//        for (int w = 0; w < origin_image_->width(); ++w)
//        {
//            min_r = std::min(min_r, qRed(row[w]));
//            min_g = std::min(min_g, qGreen(row[w]));
//            min_b = std::min(min_b, qBlue(row[w]));

//            max_r = std::max(max_r, qRed(row[w]));
//            max_g = std::max(max_g, qGreen(row[w]));
//            max_b = std::max(max_b, qBlue(row[w]));

//            min_r = std::max(min_r, min);
//            min_g = std::max(min_g, min);
//            min_b = std::max(min_b, min);

//            max_r = std::min(max_r, max);
//            max_g = std::min(max_g, max);
//            max_b = std::min(max_b, max);
//        }
//    }

    for (int h = 0; h < preview_image_->height(); ++h)
    {
        QRgb *row = (QRgb *)origin_image_->scanLine(h);
        for (int w = 0; w < preview_image_->width(); ++w)
        {
            if (min != max)
            {
                int new_r = 255 * ((qRed(row[w]) - min) / (max - min));
                int new_g = 255 * ((qGreen(row[w]) - min) / (max - min));
                int new_b = 255 * ((qBlue(row[w]) - min) / (max - min));

                preview_image_->setPixel(w, h, qRgb(new_r, new_g, new_b));
            }
        }
    }
}


void SetContrast::on_changeMinSlider_sliderMoved(int position)
{
    min = position;
    SetContrast::setContrast();
}


void SetContrast::on_changeMaxSlider_sliderMoved(int position)
{
    max = position;
    SetContrast::setContrast();
}


void SetContrast::on_SetContrast_finished(int result)
{
    *origin_image_ = *preview_image_;
}
