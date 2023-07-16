#ifndef SAVERESULT_H
#define SAVERESULT_H

#include <QDialog>
#include <QImage>

namespace Ui {
class SaveResult;
}

class SaveResult : public QDialog
{
    Q_OBJECT

public:
    explicit SaveResult(QWidget *parent = nullptr, QImage *image = nullptr);
    QImage *image_;
    ~SaveResult();

private slots:
    void on_buttCancel_clicked();

    void on_buttSave_clicked();

private:
    Ui::SaveResult *ui;
};

#endif // SAVERESULT_H
