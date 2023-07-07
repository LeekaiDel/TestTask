#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <QMainWindow>
#include <enterpathwin.h>
#include <QString>
#include <iostream>
#include <QTimer>
#include <QImage>
#include <QPixmap>
#include <QLabel>
#include <QVBoxLayout>

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
    QTimer *timer_update_image;

private slots:
    void on_actionClose_triggered();

    void on_actionOpen_triggered();
    void updateImage();

private:
    Ui::ImageViewer *ui;
};
#endif // TEXTEDITOR_H
