#ifndef SUBTRACTION_H
#define SUBTRACTION_H

#include <QDialog>

namespace Ui {
class subtraction;
}

class subtraction : public QDialog
{
    Q_OBJECT

public:
    explicit subtraction(QWidget *parent = nullptr);
    ~subtraction();

private:
    Ui::subtraction *ui;

private slots:
    void on_pushbutton1_clicked();
};

#endif // SUBTRACTION_H
