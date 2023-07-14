#include "imageviewer.h"
#include "./ui_imageviewer.h"


ImageViewer::ImageViewer(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::ImageViewer)
{
    // Настраиваем окошко приложения
    ui->setupUi(this);
    // Создаем экземпляры классов преобразований изображения
    // rgbsliders_widget = new RGBSliders(this, &image, &preview_image); // Настройка RGB каналов
    // setcontrast_widget = new SetContrast(this, &preview_image); // Настройка контраста

    timer_update_image = new QTimer(this);
    connect(timer_update_image, &QTimer::timeout, this, &ImageViewer::updateImage);
    timer_update_image->start(100);
    ImageViewer::on_actionOpen_triggered();
}

ImageViewer::~ImageViewer()
{
    delete ui;
}

// Метод перевода цветного изображения в черно-белый
QImage *ImageViewer::SetGrayScale(QImage origin_img)
{
    QImage *new_img = new QImage(origin_img.width(), origin_img.height(), QImage::Format_RGB32);
    for(int h = 0; h < new_img->height(); ++h)
    {
        QRgb *row = (QRgb *)origin_img.scanLine(h);
        for(int w = 0; w < new_img->width(); ++w)
        {
            uint average = (qRed(row[w]) + qGreen(row[w]) + qBlue(row[w])) / 3;
            new_img->setPixel(w, h, qRgb(average, average, average));
        }
    }
    return new_img;
}

// Закрытие приложения через меню
void ImageViewer::on_actionClose_triggered()
{
    this->close();
}

// Открытие файла через меню
void ImageViewer::on_actionOpen_triggered()
{
    EnterPathWin *enter_path_window = new EnterPathWin(this, &image, &preview_image);
    enter_path_window->show();
}

// Таймер для обновления изображения
void ImageViewer::updateImage()
{
    if(!image.isNull())
    {
        ui->imageViewer->setPixmap(QPixmap::fromImage(preview_image)); //
    }
}

void ImageViewer::on_buttRGB_clicked()
{
    RGBSliders *rgbsliders_window = new RGBSliders(this, &image, &preview_image); // Настройка RGB каналов;
    rgbsliders_window->show();
}


void ImageViewer::on_buttGrayScale_clicked()
{
    ImageViewer::preview_image = *ImageViewer::SetGrayScale(image);
    ImageViewer::image = ImageViewer::preview_image;
}


void ImageViewer::on_buttContrast_clicked()
{
    SetContrast *setcontrast_window = new SetContrast(this, &image, &preview_image); // Настройка контраста
    setcontrast_window->show();
}


void ImageViewer::on_buttTranslate_clicked()
{
    Translate *translate_window = new Translate(this, &image, &preview_image);
    translate_window->show();
}

