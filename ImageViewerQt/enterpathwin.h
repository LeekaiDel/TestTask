#ifndef ENTERPATHWIN_H
#define ENTERPATHWIN_H

#include <QMainWindow>
#include <QString>
#include <QImage>

namespace Ui {
class EnterPathWin;
}

class EnterPathWin : public QMainWindow
{
    Q_OBJECT

public:
    explicit EnterPathWin(QWidget *parent = nullptr, QImage *image = nullptr);
    ~EnterPathWin();
    QImage *image_;

private slots:
    void on_ButtCancel_clicked();

    void on_ButtEnter_clicked();

private:
    Ui::EnterPathWin *ui;
};

#endif // ENTERPATHWIN_H
