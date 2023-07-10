#ifndef RGBSLIDERS_H
#define RGBSLIDERS_H

#include <QDialog>
#include <QImage>
#include <QDebug>
#include <iostream>
#include <QString>

namespace Ui {
class RGBSliders;
}

class RGBSliders : public QDialog
{
    Q_OBJECT

public:
    explicit RGBSliders(QWidget *parent = nullptr, QImage *image = nullptr);
    ~RGBSliders();
    QImage *image_;
    int r_slider_pose = 0;
    int g_slider_pose = 0;
    int b_slider_pose = 0;

private slots:
    void on_sliderR_sliderMoved(int position);

    void on_sliderG_sliderMoved(int position);

    void on_sliderB_sliderMoved(int position);

private:
    Ui::RGBSliders *ui;
};

#endif // RGBSLIDERS_H
