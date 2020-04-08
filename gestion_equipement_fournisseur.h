#ifndef GESTION_EQUIPEMENT_FOURNISSEUR_H
#define GESTION_EQUIPEMENT_FOURNISSEUR_H

#include <QMainWindow>
#include "equipement.h"
#include "fournisseur.h"

namespace Ui {
class Gestion_equipement_fournisseur;
}

class Gestion_equipement_fournisseur : public QMainWindow
{
    Q_OBJECT

public:
    explicit Gestion_equipement_fournisseur(QWidget *parent = 0);
    ~Gestion_equipement_fournisseur();

private slots:
    void on_pb_ajouter_eq_clicked();

    void on_pb_supp_eq_clicked();

    void on_pb_modifier_eq_clicked();

    void on_pb_recherche_eq_clicked();



    void on_pb_ajouter_f_clicked();

    void on_pb_supp_f_clicked();

    void on_pb_modifier_f_clicked();

private:
    Ui::Gestion_equipement_fournisseur *ui;
    Equipement tmpequipement;
    Fournisseur tmpfournisseur;
};

#endif // GESTION_EQUIPEMENT_FOURNISSEUR_H
