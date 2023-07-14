#include "translate.h"
#include "ui_translate.h"

Translate::Translate(QWidget *parent, QImage *origin_image, QImage *preview_image) :
    QDialog(parent),
    ui(new Ui::Translate)
{
    origin_image_ = origin_image;
    image_ = *origin_image;
    preview_image_ = preview_image;
    ui->setupUi(this);   
}

Translate::~Translate()
{
    delete ui;
}

void Translate::scaleImage(float scale_k)
{

    int n_w = 0;
    int n_h = 0;

    n_w = int(image_.width() * scale_k);
    n_h = int(image_.height() * scale_k);

    if (n_w != 0 && n_h != 0)
    {
        scaled_image = new QImage(n_w, n_h, QImage::Format_RGB32);
         for(int h = 0; h < image_.height(); ++h)
         {
             QRgb *row = (QRgb *)image_.scanLine(h);
             for(int w = 0; w < image_.width(); ++w)
             {
                 int w_s = w * scale_k;
                 int h_s = h * scale_k;
                 if (w_s < n_w && h_s < n_h)
                 {
                    scaled_image->setPixel(w_s, h_s, row[w]);
                 }
             }
         }
         *preview_image_ = *scaled_image;
    }
}

// Поворот вектора
Eigen::Vector2d Translate::rotateVector(int x, int y, float alpha)
{
    Eigen::Matrix<double, 2, 2> rot_mat { {cos(alpha), -sin(alpha)},
                                          {sin(alpha), cos(alpha)} };

    Eigen::Vector2d origin_vector {double(x), double(y)};
    Eigen::Vector2d final_vector = origin_vector.transpose() * rot_mat;
    return final_vector;
}

// Вычисляем новый размер изображения
Eigen::Vector2i Translate::calcNewSize(int w, int h, float alpha_in_rad)
{
    int new_width = w * abs(cos(alpha_in_rad)) + h * abs(sin(alpha_in_rad)); 
    int new_height = w * abs(sin(alpha_in_rad)) + h * abs(cos(alpha_in_rad));
    
    Eigen::Vector2i new_size {new_width, new_height};
    return new_size;
}

// Поворачиваем изображение
void Translate::rotateImage(float alpha_in_rad)
{
    // Находим размер повернутого изображения
    Eigen::Vector2i new_size_image = Translate::calcNewSize(image_.width(), image_.height(), alpha_in_rad);
    rotated_image = new QImage(new_size_image[0], new_size_image[1], QImage::Format_RGB32);

    for(int x = 0; x < new_size_image[0]; ++x)
    {
        for(int y = 0; y < new_size_image[1]; ++y)
        {
            // Смещаем ось вращения на итоговом изображении
            Eigen::Vector2d offset_origin_pixel_pose = Translate::rotateVector(x - rotated_image->width() / 2, y - rotated_image->height() / 2, alpha_in_rad);
            // Смещаем пиксель от центра исходного изображения
            int ox = offset_origin_pixel_pose[0] + image_.width() / 2; 
            int oy = offset_origin_pixel_pose[1] + image_.height() / 2; 

            if(ox >= 0 && ox <=  image_.width() && oy >= 0 && oy <=  image_.height())
            {
                rotated_image->setPixel(x, y, image_.pixel(ox, oy));
            }
        }
    }

    *preview_image_ = *rotated_image;
    // translated_image_ = *rotated_image;
}

// Выполняем скалирование изображения в процессе смещения ползунка и отображаем значение в labelValue
void Translate::on_scaleSlider_sliderMoved(int position)
{
    float scale_k = abs(1 + float(position) / 100.0);
    ui->scaleValueLabel->setText(QString::fromStdString(std::to_string(position)));
    if(!origin_image_->isNull())
    {
        Translate::scaleImage(scale_k);
    }
}

//  Отображаем значение вращения в labelValue
void Translate::on_rotateSlider_sliderMoved(int position)
{
    ui->rotateValueLabel->setText(QString::fromStdString(std::to_string(position)));
}

// Выполняем вращение изображения после отпускания ползунка
void Translate::on_rotateSlider_sliderReleased()
{
    double rot_alpha = M_PI * ui->rotateSlider->value() / 180;
    if(!origin_image_->isNull())
    {
        Translate::rotateImage(rot_alpha);
    }
}

void Translate::on_buttSaveScale_clicked()
{
    image_ = *scaled_image;
}

void Translate::on_buttSaveRot_clicked()
{
    image_ = *rotated_image;
}

void Translate::on_Translate_finished(int result)
{
    *origin_image_ = image_;
}



