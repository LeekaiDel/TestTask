#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <enterpathwin.h>
#include <rgbsliders.h>
#include <QMainWindow>
#include <QString>
#include <iostream>
#include <QTimer>
#include <QImage>
#include <QPixmap>
#include <QLabel>
#include <QVBoxLayout>
#include <QSize>
#include <QRgb>
#include <QColor>

QT_BEGIN_NAMESPACE
namespace Ui { class ImageViewer; }
QT_END_NAMESPACE

class ImageViewer : public QMainWindow
{
    Q_OBJECT

public:
    ImageViewer(QWidget *parent = nullptr);
    ~ImageViewer();

    QImage image;
    QTimer *timer_update_image;

    RGBSliders *rgbsliders;
    // Объявляем методы обработки изображений
    QImage *SetGrayScale(QImage origin_img);    // Метод для перевода изображения в ЧБ формат

private slots:
    void on_actionClose_triggered();

    void on_actionOpen_triggered();
    void updateImage();


    void on_buttRGB_clicked();

    void on_buttGrayScale_clicked();

private:
    Ui::ImageViewer *ui;
};
#endif // TEXTEDITOR_H
