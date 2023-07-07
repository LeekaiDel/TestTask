#include "imageviewer.h"
#include "./ui_imageviewer.h"


ImageViewer::ImageViewer(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::ImageViewer)
{
    ui->setupUi(this);
    ImageViewer::on_actionOpen_triggered();
    timer_update_image = new QTimer(this);
    connect(timer_update_image, &QTimer::timeout, this, &ImageViewer::updateImage);
    timer_update_image->start(100);
}

ImageViewer::~ImageViewer()
{
    delete ui;
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
        std::cout << image.size().width() << "x" << image.size().height() << std::endl;
    }
}
