#include "ajouterpersonel.h"
#include "ui_ajouterpersonel.h"
#include "personnel.h"
#include "reclamation.h"
#include "qcustomplot.h"
#include<QMessageBox>
#include<QPixmap>

Ajouterpersonel::Ajouterpersonel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ajouterpersonel)
{
    ui->setupUi(this);
    ui->tableView->setModel(tmpperosonel.afficher());
    QPixmap pix("D:/project/images/back.jpg");
    ui->labelpic3->setPixmap(pix.scaled(971,571,Qt::KeepAspectRatio));
    QPixmap pix1("D:/project/images/back.jpg");
    ui->labelpic4->setPixmap(pix.scaled(971,571,Qt::KeepAspectRatio));
    QPixmap pix2("D:/project/images/back.jpg");


 }

Ajouterpersonel::~Ajouterpersonel()
{
    delete ui;
}

void Ajouterpersonel::on_ajouterper_clicked()
{
       int  id = ui->lineEdit_id->text().toInt();
       QString nom = ui->lineEdit_nom->text();
       QString prenom = ui->lineEdit_prenom->text();
       QString dateinscri = ui->lineEdit_date->text();
       QString poste = ui->lineEdit_poste->text();
       PERSONNEL p(id,nom,prenom,dateinscri,poste);
       bool test=p.ajouter();
       if(test)
       {   ui->tableView->setModel(tmpperosonel.afficher());//refresh
           QMessageBox::information(nullptr, QObject::tr("ajouter personnel"),
                              QObject::tr("ajout successful.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);

       }
              else
                  QMessageBox::information(nullptr, QObject::tr("ajouter personnel"),
                              QObject::tr("ajout failed.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);

}

void Ajouterpersonel::on_modifierper_clicked()
{
       int id =ui->lineEdit_id->text().toInt();
       QString nom = ui->lineEdit_nom->text();
       QString prenom = ui->lineEdit_prenom->text();
       QString dateinscri = ui->lineEdit_date->text();
       QString poste = ui->lineEdit_poste->text();
       PERSONNEL p;
       bool test=p.modifier(id,nom,prenom,dateinscri,poste);
       if(test)
       {   ui->tableView->setModel(tmpperosonel.afficher());//refresh
           QMessageBox::information(nullptr, QObject::tr("modifier personnel"),
                              QObject::tr("modification successful.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);

       }
              else
                  QMessageBox::information(nullptr, QObject::tr("modifier personnel"),
                              QObject::tr("ajout failed.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);

}

void Ajouterpersonel::on_supprimerper_clicked()
{
    int id = ui->lineEdit_idsupp->text().toInt();
    bool test=tmpperosonel.supprimer(id);
    if(test)
    {    ui->tableView->setModel(tmpperosonel.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("supprimer personnel"),
                              QObject::tr("suppression successful.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);

          }
              else
                  QMessageBox::information(nullptr, QObject::tr("supprimer personnel"),
                              QObject::tr("suppression failed.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);

}



void Ajouterpersonel::on_rechercherper_clicked()
{
    int id=ui->lineEdit_rechercheid->text().toInt();
    ui->tableView->setModel(tmpperosonel.recherche(id));
}


void Ajouterpersonel::on_trieper_clicked()
{
     ui->tableView->setModel(tmpperosonel.tri_employee());
}


void Ajouterpersonel::on_ajouterrec_clicked()
{
    int  id = ui->lineEdit_idrec->text().toInt();
    QString contenu = ui->lineEditcontenu->text();
    QString etat = ui->lineEditetat->text();

    RECLAMATION r(id,contenu,etat);
    bool test=r.ajouter();
    if(test)
    {   ui->tableViewrec->setModel(tmpreclamation.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("ajouter reclamation"),
                           QObject::tr("ajout successful.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);

    }
           else
               QMessageBox::information(nullptr, QObject::tr("ajouter reclamation"),
                           QObject::tr("ajout failed.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);

}

void Ajouterpersonel::on_modifierrec_clicked()
{
    int  id = ui->lineEdit_idrec->text().toInt();
    QString contenu = ui->lineEditcontenu->text();
    QString etat = ui->lineEditetat->text();
    RECLAMATION r;
    bool test=r.modifier(id,contenu,etat);
    if(test)
    {   ui->tableViewrec->setModel(tmpreclamation.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("modifier reclamation"),
                           QObject::tr("modification successful.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);

    }
           else
               QMessageBox::information(nullptr, QObject::tr("modifier reclamation"),
                           QObject::tr("ajout failed.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);

}

void Ajouterpersonel::on_suprrimerrec_clicked()
{
    int id = ui->lineEdit_idsupp_2->text().toInt();
    bool test=tmpreclamation.supprimer(id);
    if(test)
    {    ui->tableViewrec->setModel(tmpreclamation.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("supprimer reclamation"),
                              QObject::tr("suppression successful.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);

          }
              else
                  QMessageBox::information(nullptr, QObject::tr("supprimer reclamation"),
                              QObject::tr("suppression failed.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);

}

void Ajouterpersonel::on_recherecherrec_clicked()
{
    int id=ui->lineEdit_recherche2_2->text().toInt();
    ui->tableViewrec->setModel(tmpreclamation.recherche(id));
}

void Ajouterpersonel::on_trierrec_clicked()
{
ui->tableViewrec->setModel(tmpreclamation.tri_employee());
}

void Ajouterpersonel::on_modifierper_3_clicked()
{

}
