#ifndef CHOIX_H
#define CHOIX_H

#include <QDialog>

namespace Ui {
class choix;
}

class choix : public QDialog
{
    Q_OBJECT

public:
    explicit choix(QWidget *parent = nullptr);
    ~choix();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::choix *ui;
};

#endif // CHOIX_H
