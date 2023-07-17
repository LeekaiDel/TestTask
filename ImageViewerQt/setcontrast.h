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
    
    int offset = 0;

    int min = 255;
    int max = 0;

    
    void setContrast();
    
    int cutBrightnessVal(int val);

private slots:
    void on_SetContrast_finished(int result);

    void on_changeOffsetSlider_sliderMoved(int position);

private:
    Ui::SetContrast *ui;
};

#endif // SETCONTRAST_H
