#include "gestion_equipement_fournisseur.h"
#include "ui_gestion_equipement_fournisseur.h"
#include <QPixmap>
#include "equipement.h"
#include <QMessageBox>
#include "connexion.h"
#include "fournisseur.h"

Gestion_equipement_fournisseur::Gestion_equipement_fournisseur(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Gestion_equipement_fournisseur)
{
    ui->setupUi(this);
    QPixmap pix("C:/qt_pic/qt.jpg");
    ui->label_pic->setPixmap(pix);
    ui->label_pic_2->setPixmap(pix);
    ui->tabequipement->setModel(tmpequipement.afficher());
    ui->tabfournisseur->setModel(tmpfournisseur.afficher());
}

Gestion_equipement_fournisseur::~Gestion_equipement_fournisseur()
{
    delete ui;
}

void Gestion_equipement_fournisseur::on_pb_ajouter_eq_clicked()
{
    int ide = ui->lineEdit_ide->text().toInt();
    QString nom= ui->lineEdit_nome->text();
    QString type= ui->lineEdit_type->text();
    QString nomf= ui->lineEdit_nomf->text();
    int nombre= ui->spinBox_nb->text().toInt();

    Equipement e(ide,nom,type,nomf,nombre);

    bool test=e.ajouter();

    if(test)
  {

        ui->tabequipement->setModel(tmpequipement.afficher());//refresh
  QMessageBox::information(nullptr, QObject::tr("Ajouter un equipement"),
                    QObject::tr("Equipement ajouté.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

  }
    else
        QMessageBox::critical(nullptr, QObject::tr("Ajouter un equipement"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void Gestion_equipement_fournisseur::on_pb_supp_eq_clicked()
{
    int ide = ui->lineEdit_supp_modif_eq->text().toInt();

    bool test=tmpequipement.supprimer(ide);

    if(test)
    {
        ui->tabequipement->setModel(tmpequipement.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un equipement"),
                    QObject::tr("Equipement supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un equipement"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void Gestion_equipement_fournisseur::on_pb_modifier_eq_clicked()
{
    int ide= ui->lineEdit_supp_modif_eq->text().toInt();
    QString nom = ui->lineEdit_nome->text();
    QString type = ui->lineEdit_type->text();
    QString nomf = ui->lineEdit_nomf->text();
    int nombre = ui->spinBox_nb->text().toInt();


    bool test= tmpequipement.modifier(ide,nom,type,nomf,nombre);
    if(test)
    {
       ui->tabequipement->setModel(tmpequipement.afficher());
       QMessageBox::information(nullptr, QObject::tr("Modifier un equipement"),
                   QObject::tr("Equipement modifie.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Modifier un equipement"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void Gestion_equipement_fournisseur::on_pb_recherche_eq_clicked()
{
        QString nom = ui->lineEdit_recherche_eq->text();
        ui->tabequipement->setModel(tmpequipement.recherche(nom));
}


void Gestion_equipement_fournisseur::on_pb_ajouter_f_clicked()
{
    int idf = ui->lineEdit_idf->text().toInt();
    QString nom= ui->lineEdit_nomff->text();
    QString categorie= ui->lineEdit_cat->text();
    int numero= ui->lineEdit_num->text().toInt();
    QString mail= ui->lineEdit_mail->text();

    Fournisseur f(idf,nom,categorie,numero,mail);

    bool test=f.ajouter();

    if(test)
  {

        ui->tabfournisseur->setModel(tmpfournisseur.afficher());//refresh
  QMessageBox::information(nullptr, QObject::tr("Ajouter un fournisseur"),
                    QObject::tr("fournisseur ajouté.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

  }
    else
        QMessageBox::critical(nullptr, QObject::tr("Ajouter un fournisseur"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void Gestion_equipement_fournisseur::on_pb_supp_f_clicked()
{
    int idf = ui->lineEdit_supp_modif_f->text().toInt();

    bool test=tmpfournisseur.supprimer(idf);

    if(test)
    {
        ui->tabfournisseur->setModel(tmpfournisseur.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un fournisseur"),
                    QObject::tr("Fournisseur supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un equipement"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void Gestion_equipement_fournisseur::on_pb_modifier_f_clicked()
{
    int idf= ui->lineEdit_supp_modif_f->text().toInt();
    QString nom = ui->lineEdit_nomff->text();
    QString categorie = ui->lineEdit_cat->text();
    int numero = ui->lineEdit_num->text().toInt();
    QString mail = ui->lineEdit_mail->text();


    bool test= tmpfournisseur.modifier(idf,nom,categorie,numero,mail);
    if(test)
    {
       ui->tabfournisseur->setModel(tmpfournisseur.afficher());
       QMessageBox::information(nullptr, QObject::tr("Modifier un fournisseur"),
                   QObject::tr("Fournisseur modifie.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Modifier un fournisseur"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}
