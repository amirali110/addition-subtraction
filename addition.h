#ifndef ADDITION_H
#define ADDITION_H

#include <QDialog>

namespace Ui {
class addition;
}

class addition : public QDialog
{
    Q_OBJECT

public:
    explicit addition(QWidget *parent = nullptr);
    ~addition();

private:
    Ui::addition *ui;

private slots:
    void on_pushButton1_clicked();
};

#endif // ADDITION_H
