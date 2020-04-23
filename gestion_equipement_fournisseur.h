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

    void on_pb_modif_eq_clicked();

    void on_pb_recherche_eq_clicked();



    void on_pb_actualiser_eq_clicked();

    void on_pb_trie_eq_clicked();

    void on_pb_ajout_f_clicked();

    void on_pb_actualiser_f_clicked();

    void on_pb_supp_f_clicked();

    void on_pb_modif_f_clicked();

    void on_pb_recherche_f_clicked();

    void on_pb_trie_f_clicked();

    void on_pb_pdf_eq_clicked();

    void on_pb_pdf_f_clicked();

    void on_pb_stat_eq_clicked();

    void on_tabequipement_activated(const QModelIndex &index);

    void on_tabfournisseur_activated(const QModelIndex &index);

private:
    Ui::Gestion_equipement_fournisseur *ui;
    Equipement *tmpequipement;
    Fournisseur *tmpfournisseur;
};

#endif // GESTION_EQUIPEMENT_FOURNISSEUR_H
