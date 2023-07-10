#include "imageviewer.h"
#include "./ui_imageviewer.h"


ImageViewer::ImageViewer(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::ImageViewer)
{
    // Настраиваем окошко приложения
    ui->setupUi(this);
//    QSize fix_size;
//    fix_size.setWidth(640);
//    fix_size.setHeight(480);
//    this->setFixedSize(fix_size);
    // Создаем экземпляры классов преобразований изображения
    rgbsliders = new RGBSliders(this, &image); // Настройка RGB каналов

    timer_update_image = new QTimer(this);
    connect(timer_update_image, &QTimer::timeout, this, &ImageViewer::updateImage);
    timer_update_image->start(100);
    ImageViewer::on_actionOpen_triggered();
}

ImageViewer::~ImageViewer()
{
    delete ui;
}

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


void ImageViewer::on_actionClose_triggered()
{
    this->close();
}


void ImageViewer::on_actionOpen_triggered()
{
    EnterPathWin *enter_path_window = new EnterPathWin(this, &image);
    enter_path_window->show();
}

void ImageViewer::updateImage()
{
    if(!image.isNull())
    {
//        QImage image_scaled = image.scaled(ui->centralwidget->size().width(), ui->centralwidget->size().height() - ui->buttonBar->size().height(), Qt::IgnoreAspectRatio);
        ui->imageViewer->setPixmap(QPixmap::fromImage(image)); //
//        std::cout << image.size().width() << "x" << image.size().height() << std::endl;
    }
}

void ImageViewer::on_buttRGB_clicked()
{
    rgbsliders->show();
}


void ImageViewer::on_buttGrayScale_clicked()
{
    ImageViewer::image = *ImageViewer::SetGrayScale(image);
}

