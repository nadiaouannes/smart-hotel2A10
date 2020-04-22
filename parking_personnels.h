#ifndef PARKING_PERSONNELS_H
#define PARKING_PERSONNELS_H

#include "vpersonel.h"
#include <QDialog>

namespace Ui {
class parking_personnels;
}

class parking_personnels : public QDialog
{
    Q_OBJECT

public:
    explicit parking_personnels(QWidget *parent = nullptr);
    ~parking_personnels();

private slots:
    void on_ajout_clicked();

    void on_ajouter_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_supp_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_mod_clicked();

    void on_lineEdit_5_textChanged(const QString &arg1);

    void on_pushButton_6_clicked();

    void on_lineEdit_ids_textChanged(const QString &arg1);

    void on_aff_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_pushButton_7_clicked();



private:
    Ui::parking_personnels *ui;
    vpersonel tmpide;
};

#endif // PARKING_PERSONNELS_H
