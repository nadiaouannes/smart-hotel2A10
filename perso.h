#ifndef PERSO_H
#define PERSO_H

#include "vpersonel.h"
#include <QDialog>

namespace Ui {
class perso;
}

class perso : public QDialog
{
    Q_OBJECT

public:
    explicit perso(QWidget *parent = nullptr);
    ~perso();

private slots:
    void on_pushButton_clicked();

    void on_ajouter_clicked();

    void on_pushButton_3_clicked();

    void on_lineEdit_ids_textChanged(const QString &arg1);

    void on_pushButton_5_clicked();

    void on_lineEdit_id_textChanged(const QString &arg1);

    void on_lineEdit_textChanged(const QString &arg1);

private:
    Ui::perso *ui;
    vpersonel tmpide;
};

#endif // PERSO_H
