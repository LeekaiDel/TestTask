#ifndef GAUSSIANBLUR_H
#define GAUSSIANBLUR_H

#include <iostream>
#include <Eigen/Dense>
#include <QImage>
#include <QRgb>

class GaussianBlur
{
public:
    static Eigen::Matrix<float, 5, 5> gaussian_kernel;
    GaussianBlur();
    // Метод свертки изображения
    static QImage convolutionMethod(QImage origin_image, Eigen::MatrixXf kernel);
};

#endif // GAUSSIANBLUR_H
