#ifndef SETCONTRAST_H
#define SETCONTRAST_H

#include <QDialog>
#include <QWidget>
#include <QImage>
#include <iostream>

namespace Ui {
class SetContrast;
}

class SetContrast : public QDialog
{
    Q_OBJECT

public:
    explicit SetContrast(QWidget *parent = nullptr, QImage *origin_image = nullptr, QImage *preview_image = nullptr);
    ~SetContrast();
    QImage *origin_image_;
    QImage *preview_image_;
    
    int min = 0;
    int max = 0;

    int min_r = 0;
    int min_g = 0;
    int min_b = 0;

    int max_r = 255;
    int max_g = 255;
    int max_b = 255;
    
    void setContrast();

private slots:
    void on_changeMinSlider_sliderMoved(int position);
 
    void on_changeMaxSlider_sliderMoved(int position);

    void on_SetContrast_finished(int result);

private:
    Ui::SetContrast *ui;
};

#endif // SETCONTRAST_H
