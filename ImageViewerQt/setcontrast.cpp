#include "setcontrast.h"
#include "ui_setcontrast.h"

SetContrast::SetContrast(QWidget *parent, QImage *origin_image) :
    QDialog(parent),
    ui(new Ui::SetContrast)
{
    ui->setupUi(this);
    image = origin_image;
    min = 0;
    max = 255;
}

SetContrast::~SetContrast()
{
    delete ui;
}

void SetContrast::on_changeMinSlider_sliderReleased()
{
        QImage *contrast_image = new QImage(image->width(), image->height(), QImage::Format_RGB32);
        int min_r = 255;
        int min_g = 255;
        int min_b = 255;

        int max_r = 0;
        int max_g = 0;
        int max_b = 0;

        for (int h = 0; h < image->height(); ++h)
        {
            QRgb *row = (QRgb *)image->scanLine(h);
            for (int w = 0; w < image->width(); ++w)
            {
                min_r = std::min(min_r, qRed(row[w]));
                min_g = std::min(min_g, qGreen(row[w]));
                min_b = std::min(min_b, qBlue(row[w]));

                max_r = std::max(max_r, qRed(row[w]));
                max_g = std::max(max_g, qGreen(row[w]));
                max_b = std::max(max_b, qBlue(row[w]));

//                min_r = std::max(min_r, ui->changeMinSlider->value());
//                min_g = std::max(min_g, ui->changeMinSlider->value());
//                min_b = std::max(min_b, ui->changeMinSlider->value());
            }
        }

        for (int h = 0; h < image->height(); ++h)
        {
            QRgb *row = (QRgb *)image->scanLine(h);
            for (int w = 0; w < image->width(); ++w)
            {
                int new_r = 255 * ((qRed(row[w]) - min_r) / (max_r - min_r));
                int new_g = 255 * ((qGreen(row[w]) - min_g) / (max_g - min_g));
                int new_b = 255 * ((qBlue(row[w]) - min_b) / (max_b - min_b));
                contrast_image->setPixel(w, h, qRgb(new_r, new_g, new_b));
            }
        }
        *image = *contrast_image;
}

void SetContrast::on_changeMaxSlider_sliderReleased()
{

}

