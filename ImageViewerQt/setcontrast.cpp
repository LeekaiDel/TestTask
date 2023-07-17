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
           // Получаем компоненту Y из формата YUV
           int y = 0.2126 * qRed(row[w]) + 0.7152 * qGreen(row[w]) + 0.0722 * qBlue(row[w]);

           min = std::min(min, y);
           max = std::max(max, y);
           // Делаем смещение краев гистограммы для растягивания
           min = std::max(min, offset);
           max = std::min(max, 255 - offset);
       }
    }
    // std::cout << "min: " << min << "max: " << max << std::endl;

    for (int h = 0; h < preview_image_->height(); ++h)
    {
        QRgb *row = (QRgb *)origin_image_->scanLine(h);
        for (int w = 0; w < preview_image_->width(); ++w)
        {
            if (min != max)
            {
                // Переводим в формат YUV
                int y = 0.2126 * qRed(row[w]) + 0.7152 * qGreen(row[w]) + 0.0722 * qBlue(row[w]);
                int u = -0.0999 * qRed(row[w]) - 0.3360 * qGreen(row[w]) + 0.4360 * qBlue(row[w]);
                int v = 0.6150 * qRed(row[w]) - 0.5586 * qGreen(row[w]) - 0.0563 * qBlue(row[w]);
                // Растягиваем компоненту Y
                int new_y = ((y - min) * 255) / (max - min);
                // Переводим обратно в RGB
                int new_r = new_y + 1.2803 * v;
                int new_g = new_y - 0.2148 * u - 0.3805 * v;
                int new_b = new_y + 2.1279 * u;

                new_r = SetContrast::cutBrightnessVal(new_r);
                new_g = SetContrast::cutBrightnessVal(new_g);
                new_b = SetContrast::cutBrightnessVal(new_b);

                preview_image_->setPixel(w, h, qRgb(new_r, new_g, new_b));
            }
        }
    }
}

int SetContrast::cutBrightnessVal(int val)
{
    if(val > 255) return 255;

    else if(val < 0) return 0;
    
    else return val;
}

void SetContrast::on_SetContrast_finished(int result)
{
    *origin_image_ = *preview_image_;
}

void SetContrast::on_changeOffsetSlider_sliderMoved(int position)
{
    offset = position;
    ui->labelValue->setText(QString::fromStdString(std::to_string(position)));
    SetContrast::setContrast();
}

