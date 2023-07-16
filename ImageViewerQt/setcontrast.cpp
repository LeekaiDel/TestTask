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
   for (int h = 0; h < origin_image_->height(); ++h)
   {
       QRgb *row = (QRgb *)origin_image_->scanLine(h);
       for (int w = 0; w < origin_image_->width(); ++w)
       {
           min_r = std::min(min_r, qRed(row[w]));
           min_g = std::min(min_g, qGreen(row[w]));
           min_b = std::min(min_b, qBlue(row[w]));

           max_r = std::max(max_r, qRed(row[w]));
           max_g = std::max(max_g, qGreen(row[w]));
           max_b = std::max(max_b, qBlue(row[w]));

            min_r = std::max(min_r, offset);
            min_g = std::max(min_g, offset);
            min_b = std::max(min_b, offset);

            max_r = std::min(max_r, 255 - offset);
            max_g = std::min(max_g, 255 - offset);
            max_b = std::min(max_b, 255 - offset);
       }
   }

    for (int h = 0; h < preview_image_->height(); ++h)
    {
        QRgb *row = (QRgb *)origin_image_->scanLine(h);
        for (int w = 0; w < preview_image_->width(); ++w)
        {
            if (min_r != max_r && min_g != max_g && min_b != max_b)
            {
                int new_r = (qRed(row[w]) - min_r) * (255 / (max_r - min_r));
                int new_g = (qGreen(row[w]) - min_g) * (255 / (max_g - min_g));
                int new_b = (qBlue(row[w]) - min_b) * (255 / (max_b - min_b));

                preview_image_->setPixel(w, h, qRgb(new_r, new_g, new_b));
            }
        }
    }
}


void SetContrast::on_SetContrast_finished(int result)
{
    *origin_image_ = *preview_image_;
}

void SetContrast::on_changeOffsetSlider_sliderMoved(int position)
{
    offset = position;
    ui->labelValue->setText(QString::fromStdString(std::to_string(position)));
}


void SetContrast::on_buttGetResult_clicked()
{
    SetContrast::setContrast();
}

