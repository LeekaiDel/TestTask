#include "gaussianblur.h"

Eigen::Matrix<float, 5, 5> GaussianBlur::gaussian_kernel {  {0.000789, 0.006581, 0.013347, 0.006581, 0.000789}, 
                                                            {0.006581, 0.054901, 0.111345, 0.054901, 0.006581}, 
                                                            {0.013347, 0.111345, 0.225821, 0.111345, 0.013347}, 
                                                            {0.006581, 0.054901, 0.111345, 0.054901, 0.006581}, 
                                                            {0.000789, 0.006581, 0.013347, 0.006581, 0.000789} };

// Метод свертки изображения
QImage GaussianBlur::convolutionMethod(QImage origin_image, Eigen::MatrixXf kernel)
{
//    std::cout << "IMAGE SIZE: " << origin_image.width() << "x" << origin_image.height() << std::endl;
    QImage convolution_result(origin_image.width(), origin_image.height(), QImage::Format_RGB32);

    int x_kernel_offset = kernel.cols() / 2;
    int y_kernel_offset = kernel.rows() / 2;

    for(int x = 0; x < origin_image.width(); x++)
    {
        for(int y = 0; y < origin_image.height(); y++)
        {
            // Перебираем элементы попадающие в ячейки ядра
            QRgb new_pixel;

            int red = 0;
            int green = 0;
            int blue = 0;

            for(int ker_x = -x_kernel_offset; ker_x <= x_kernel_offset; ++ker_x)
            {
                for(int ker_y = -y_kernel_offset; ker_y <= y_kernel_offset; ++ker_y)
                {
                    int x_offset = x + ker_x;
                    int y_offset = y + ker_y;

                    QRgb pixel = qRgb(0, 0, 0);
                    if(x_offset >= 0 && y_offset >= 0 && x_offset < origin_image.width() && y_offset < origin_image.height())
                    {
                        pixel = origin_image.pixel(x_offset, y_offset);
                    }

                    red = red + qRed(pixel) * kernel(ker_x + x_kernel_offset, ker_y + y_kernel_offset);
                    green = green + qGreen(pixel) * kernel(ker_x + x_kernel_offset, ker_y + y_kernel_offset);
                    blue = blue + qBlue(pixel) * kernel(ker_x + x_kernel_offset, ker_y + y_kernel_offset);
                }
            }
            new_pixel = qRgb(red, green, blue);
            convolution_result.setPixel(x, y, new_pixel);
        }
    }
    return convolution_result;
}

GaussianBlur::GaussianBlur()
{

}
