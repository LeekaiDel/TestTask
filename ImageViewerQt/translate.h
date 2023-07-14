#ifndef TRANSLATE_H
#define TRANSLATE_H

#include <QDialog>
#include <iostream>
#include <cmath>
#include <eigen3/Eigen/Dense>

namespace Ui {
class Translate;
}

class Translate : public QDialog
{
    Q_OBJECT

public:
    explicit Translate(QWidget *parent = nullptr, QImage *origin_image = nullptr, QImage *preview_image = nullptr);
    ~Translate();

    QImage *origin_image_;
    QImage image_;
    QImage *preview_image_;

    QImage *rotated_image;
    QImage *scaled_image;
    
    void scaleImage(float scale_k);

    void rotateImage(float alpha_in_rad);

    Eigen::Vector2d rotateVector(int x, int y, float alpha);
    Eigen::Vector2i calcNewSize(int w, int h, float alpha_in_rad);

private slots:
    void on_scaleSlider_sliderMoved(int position);

    void on_rotateSlider_sliderMoved(int position);
    void on_rotateSlider_sliderReleased();

    void on_buttSaveScale_clicked();
    void on_buttSaveRot_clicked();

    void on_Translate_finished(int result);

private:
    Ui::Translate *ui;
};

#endif // TRANSLATE_H
