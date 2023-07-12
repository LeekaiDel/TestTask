#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H
#include <iostream>
#include <algorithm>

#include <enterpathwin.h>
#include <rgbsliders.h>
#include <setcontrast.h>

#include <QMainWindow>
#include <QString>
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
    QImage preview_image;
    QTimer *timer_update_image;

    // RGBSliders *rgbsliders_widget;
    SetContrast *setcontrast_widget;
    // Объявляем методы обработки изображений
    QImage *SetGrayScale(QImage origin_img);    // Метод для перевода изображения в ЧБ формат

private slots:
    void on_actionClose_triggered();

    void on_actionOpen_triggered();
    void updateImage();


    void on_buttRGB_clicked();

    void on_buttGrayScale_clicked();

    void on_buttContrast_clicked();

private:
    Ui::ImageViewer *ui;
};
#endif // TEXTEDITOR_H
