#ifndef RGBSLIDERS_H
#define RGBSLIDERS_H

#include <QDialog>
#include <QImage>
#include <QDebug>
#include <iostream>
#include <QString>
#include <algorithm>
namespace Ui {
class RGBSliders;
}

class RGBSliders : public QDialog
{
    Q_OBJECT

public:
    explicit RGBSliders(QWidget *parent = nullptr, QImage *origin_image = nullptr, QImage *preview_image = nullptr);
    ~RGBSliders();
    QImage *origin_image_;
    QImage *preview_image_;

    int last_slider_r_pose = 0;
    int last_slider_g_pose = 0;
    int last_slider_b_pose = 0;
    
    int slider_r_pose = 0;
    int slider_g_pose = 0;
    int slider_b_pose = 0;

    void setRgbChannels();
    
private slots:
    void on_sliderR_sliderMoved(int position);

    void on_sliderG_sliderMoved(int position);

    void on_sliderB_sliderMoved(int position);

    void on_RGBSliders_finished(int result);

private:
    Ui::RGBSliders *ui;
};

#endif // RGBSLIDERS_H
