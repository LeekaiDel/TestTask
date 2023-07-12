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
    explicit SetContrast(QWidget *parent = nullptr, QImage *origin_image = nullptr);
    ~SetContrast();
    QImage *image;
    uint min;
    uint max;
private slots:
    void on_changeMinSlider_sliderReleased();

    void on_changeMaxSlider_sliderReleased();

private:
    Ui::SetContrast *ui;
};

#endif // SETCONTRAST_H
