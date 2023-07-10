#include "rgbsliders.h"
#include "ui_rgbsliders.h"

RGBSliders::RGBSliders(QWidget *parent, QImage *image) :
    QDialog(parent),
    ui(new Ui::RGBSliders)
{
    image_ = image;
    ui->setupUi(this);
    this->setWindowTitle("RGB Sliders");
    ui->labelValueR->setText(QString::fromStdString(std::to_string(ui->sliderR->value())));
    ui->labelValueG->setText(QString::fromStdString(std::to_string(ui->sliderG->value())));
    ui->labelValueB->setText(QString::fromStdString(std::to_string(ui->sliderB->value())));

}

RGBSliders::~RGBSliders()
{
    delete ui;
}

void RGBSliders::on_sliderR_sliderMoved(int position)
{
    RGBSliders::r_slider_pose = position;
    ui->labelValueR->setText(QString::fromStdString(std::to_string(position)));
    std::cout << "r_slider_pose: " << RGBSliders::r_slider_pose << std::endl;
}

void RGBSliders::on_sliderG_sliderMoved(int position)
{
    RGBSliders::g_slider_pose = position;
    ui->labelValueG->setText(QString::fromStdString(std::to_string(position)));
    std::cout << "g_slider_pose: " << RGBSliders::g_slider_pose << std::endl;

}

void RGBSliders::on_sliderB_sliderMoved(int position)
{
    RGBSliders::b_slider_pose = position;
    ui->labelValueB->setText(QString::fromStdString(std::to_string(position)));
    std::cout << "b_slider_pose: " << RGBSliders::b_slider_pose << std::endl;
}

