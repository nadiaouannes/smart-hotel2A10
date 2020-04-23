#include "gestion_equipement_fournisseur.h"
#include "ui_gestion_equipement_fournisseur.h"
#include <QPixmap>
#include "equipement.h"
#include <QMessageBox>
#include <QComboBox>
#include "connexion.h"
#include "fournisseur.h"
#include <QPainter>
#include <QPdfWriter>
#include <QSqlError>


Gestion_equipement_fournisseur::Gestion_equipement_fournisseur(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Gestion_equipement_fournisseur)
{
    ui->setupUi(this);
    QPixmap pix("C:/qt_pic/qt1.png");
    ui->label_pic_eq->setPixmap(pix);
    ui->label_pic_f->setPixmap(pix);

    ui->tabequipement->setModel(tmpequipement->afficher());
    ui->tabfournisseur->setModel(tmpfournisseur->afficher());
    ui->comboBox_type_eq->addItem("Menuiserie");
    ui->comboBox_type_eq->addItem("Sanitaire");
    ui->comboBox_type_eq->addItem("Jardinage");
    ui->comboBox_cat_f->addItem("sanitaire");
    ui->comboBox_cat_f->addItem("Jardinage");
    ui->comboBox_cat_f->addItem("Menuiserie");

}

Gestion_equipement_fournisseur::~Gestion_equipement_fournisseur()
{
    delete ui;
}

/*Equipement*/

void Gestion_equipement_fournisseur::on_pb_ajouter_eq_clicked()
{
    int ide = ui->lineEdit_ide->text().toInt();
    QString nom= ui->lineEdit_nome->text();
    QString type= ui->comboBox_type_eq->currentText();
    QString nomf= ui->lineEdit_nomf->text();
    int nombre= ui->spinBox_nb_eq->text().toInt();

    Equipement e(ide,nom,type,nomf,nombre);

    bool test=e.ajouter();

    if(test)
  {

        ui->tabequipement->setModel(tmpequipement->afficher());//refresh
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

     int ide = ui->lineEdit_supp_eq->text().toInt();

    bool test=tmpequipement->supprimer(ide);

    if(test)
    {
        ui->tabequipement->setModel(tmpequipement->afficher());
               QString str = " Vous voulez vraiment supprimer \n le produit ayant pour identifiant :";
                             int ret = QMessageBox::question(this, tr("Equipement"),str,QMessageBox::Ok|QMessageBox::Cancel);

                             switch (ret)
                             {
                               case QMessageBox::Ok:
                                   if (tmpequipement->supprimer(ide))
                                       QMessageBox ::information(0, qApp->tr("Suppression"),
                                       qApp->tr("Equipement supprime"), QMessageBox::Ok);


                                 break;
                               case QMessageBox::Cancel:

                                   break;
                               default:
                                   // should never be reached
                                   break;
                             }
    }
           else

{
                         QMessageBox::critical(0, qApp->tr("Suppression"),
                             qApp->tr("Equipement introuvable "), QMessageBox::Cancel);

}


}





void Gestion_equipement_fournisseur::on_pb_recherche_eq_clicked()
{
    QString nom = ui->lineEdit_recherche_eq->text();
    ui->tabequipement->setModel(tmpequipement->recherche(nom));
}

void Gestion_equipement_fournisseur::on_pb_actualiser_eq_clicked()
{
     ui->tabequipement->setModel(tmpequipement->afficher());
}

void Gestion_equipement_fournisseur::on_pb_trie_eq_clicked()
{
    ui->tabequipement->setModel(tmpequipement->trier());
}

void Gestion_equipement_fournisseur::on_pb_pdf_eq_clicked()
{
    //QDateTime datecreation = date.currentDateTime();
        //QString afficheDC = "Date de Creation PDF : " + datecreation.toString() ;
               QPdfWriter pdf("C:/Users/Nadia/Desktop/Equipement.pdf"); //hedha badlouh ca depend win thobou tsobou le fichier pdf
               QPainter painter(&pdf);
              int i = 4000;
                   painter.setPen(Qt::blue);
                   painter.setFont(QFont("Arial", 30));
                   painter.drawText(1100,1200,"Les equipements");
                   painter.setPen(Qt::black);
                   painter.setFont(QFont("Arial", 15));
                  // painter.drawText(1100,2000,afficheDC);
                   painter.drawRect(100,100,7300,2600);
                   //painter.drawPixmap(QRect(7600,70,2000,2600),QPixmap("C:/Users/RH/Desktop/projecpp/image/logopdf.png"));
                   painter.drawRect(0,3000,9600,500);
                   painter.setFont(QFont("Arial", 9));
                   painter.drawText(200,3300,"IDE");
                   painter.drawText(1300,3300,"NOM");
                   painter.drawText(2100,3300,"TYPE");
                   painter.drawText(3200,3300,"NOM FOURNISSEUR");
                   painter.drawText(5300,3300,"NOMBRE");

                   QSqlQuery query;
                   query.prepare("select * from EQUIPEMENT");
                   query.exec();
                   while (query.next())
                   {
                       painter.drawText(200,i,query.value(0).toString());
                       painter.drawText(1300,i,query.value(1).toString());
                       painter.drawText(2200,i,query.value(2).toString());
                       painter.drawText(3200,i,query.value(3).toString());
                       painter.drawText(4500,i,query.value(4).toString());
                       painter.drawText(7700,i,query.value(5).toString());
                      i = i + 500;
                   }
                   int reponse = QMessageBox::question(this, "Enregistrement du fichier pdf", "Enregistrer le pdf des equipements dans le Desktop ?", QMessageBox::Yes |  QMessageBox::No);
                       if (reponse == QMessageBox::Yes)
                       {

                           painter.end();
                       }
                       if (reponse == QMessageBox::No)
                       {
                            painter.end();
                       }

}

void Gestion_equipement_fournisseur::on_tabequipement_activated(const QModelIndex &index)
{
    QString val=ui->tabequipement->model()->data(index).toString();
        QSqlQuery query;
        query.prepare("SELECT * FROM EQUIPEMENT WHERE IDE='"+val+"'");
        if(query.exec())
        {
            while(query.next())
            {
                ui->lineEdit_ide->setText(query.value(0).toString());
                ui->lineEdit_nome->setText(query.value(1).toString());
                //ui->comboBox_type_eq->setText(query.value(2).toString());
                ui->lineEdit_nomf->setText(query.value(3).toString());
               // ui->spinBox_nb_eq->setText(query.value(4).toString());
            }

        }
        else
        {
            QMessageBox::critical(this,tr("error::"),query.lastError().text());
        }
}


void Gestion_equipement_fournisseur::on_pb_modif_eq_clicked()
{
        int ide = ui->comboBox_modif_eq->currentText().toInt();

        QString nom= ui->lineEdit_nome->text();
        QString type= ui->comboBox_type_eq->currentText();
        QString nomf = ui->lineEdit_nomf->text();
        int nombre= ui->spinBox_nb_eq->text().toInt();

        Equipement e(ide,nom,type,nomf,nombre);

        bool test=e.modifier();

        if(test)
      {

            ui->tabequipement->setModel(tmpequipement->afficher());//refresh
      QMessageBox::information(nullptr, QObject::tr("Modifier un equipement"),
                        QObject::tr("equipement modifiè .\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

      }
        else
            QMessageBox::critical(nullptr, QObject::tr("Modifier un equipement"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
}


/*Fournisseur*/


void Gestion_equipement_fournisseur::on_pb_ajout_f_clicked()
{
    int idf = ui->lineEdit_idf->text().toInt();
    QString nom= ui->lineEdit_nomff->text();
    QString categorie=ui->comboBox_cat_f->currentText();
    int numero= ui->lineEdit_tel->text().toInt();
    QString mail= ui->lineEdit_mail->text();

    Fournisseur f(idf,nom,categorie,numero,mail);

    bool test=f.ajouter();

    if(test)
  {

        ui->tabfournisseur->setModel(tmpfournisseur->afficher());//refresh
  QMessageBox::information(nullptr, QObject::tr("Ajouter un fournisseur"),
                    QObject::tr("fournisseur ajouté.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

  }
    else
    {QMessageBox::critical(nullptr, QObject::tr("Ajouter un fournisseur"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    ui->lineEdit_ide->clear();
    ui->lineEdit_nome->clear();
    ui->lineEdit_nomf->clear();
    ui->spinBox_nb_eq->clear();


}

void Gestion_equipement_fournisseur::on_pb_actualiser_f_clicked()
{
    ui->tabfournisseur->setModel(tmpfournisseur->afficher());
}

void Gestion_equipement_fournisseur::on_pb_supp_f_clicked()
{

    int idf = ui->lineEdit_supp_f->text().toInt();

    bool test=tmpfournisseur->supprimer(idf);

    if(test)
    {
        ui->tabfournisseur->setModel(tmpfournisseur->afficher());
               QString str = " Vous voulez vraiment supprimer \n le fournisseur ayant pour identifiant :";
                             int ret = QMessageBox::question(this, tr("Fournisseur"),str,QMessageBox::Ok|QMessageBox::Cancel);

                             switch (ret)
                             {
                               case QMessageBox::Ok:
                                   if (tmpfournisseur->supprimer(idf))
                                       QMessageBox ::information(0, qApp->tr("Suppression"),
                                       qApp->tr("Fournisseur supprime"), QMessageBox::Ok);


                                 break;
                               case QMessageBox::Cancel:

                                   break;
                               default:
                                   // should never be reached
                                   break;
                             }
    }
           else

{
                         QMessageBox::critical(0, qApp->tr("Suppression"),
                             qApp->tr("Fournisseur introuvable "), QMessageBox::Cancel);
    }


}

void Gestion_equipement_fournisseur::on_pb_modif_f_clicked()
{
    int idf = ui->lineEdit_idf->text().toInt();
        QString nom= ui->lineEdit_nomff->text();
        QString categorie= ui->comboBox_cat_f->currentText();
        int numero= ui->lineEdit_tel->text().toInt();
        QString mail= ui->lineEdit_mail->text();

        Fournisseur f(idf,nom,categorie,numero,mail);

        bool test=f.modifier();

        if(test)
      {

            ui->tabfournisseur->setModel(tmpfournisseur->afficher());//refresh
      QMessageBox::information(nullptr, QObject::tr("Modifier un fournisseur"),
                        QObject::tr("Fournisseur modifiè .\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

      }
        else
            QMessageBox::critical(nullptr, QObject::tr("Modifier un fournisseur"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
}

void Gestion_equipement_fournisseur::on_pb_recherche_f_clicked()
{
    QString nom = ui->lineEdit_recherche_f->text();
    ui->tabfournisseur->setModel(tmpfournisseur->recherche(nom));
}

void Gestion_equipement_fournisseur::on_pb_trie_f_clicked()
{
    ui->tabfournisseur->setModel(tmpfournisseur->trier());
}




void Gestion_equipement_fournisseur::on_pb_pdf_f_clicked()
{
    //QDateTime datecreation = date.currentDateTime();
        //QString afficheDC = "Date de Creation PDF : " + datecreation.toString() ;
               QPdfWriter pdf("C:/Users/Nadia/Desktop/Fournisseur.pdf"); //hedha badlouh ca depend win thobou tsobou le fichier pdf
               QPainter painter(&pdf);
              int i = 4000;
                   painter.setPen(Qt::blue);
                   painter.setFont(QFont("Arial", 30));
                   painter.drawText(1100,1200,"Les fournisseurs");
                   painter.setPen(Qt::black);
                   painter.setFont(QFont("Arial", 15));
                  // painter.drawText(1100,2000,afficheDC);
                   painter.drawRect(100,100,7300,2600);
                   //painter.drawPixmap(QRect(7600,70,2000,2600),QPixmap("C:/Users/RH/Desktop/projecpp/image/logopdf.png"));
                   painter.drawRect(0,3000,9600,500);
                   painter.setFont(QFont("Arial", 9));
                   painter.drawText(200,3300,"IDF");
                   painter.drawText(1300,3300,"NOM");
                   painter.drawText(2100,3300,"categorie");
                   painter.drawText(3200,3300,"NUMERO");
                   painter.drawText(5300,3300,"MAIL");

                   QSqlQuery query;
                   query.prepare("select * from FOURNISSEUR");
                   query.exec();
                   while (query.next())
                   {
                       painter.drawText(200,i,query.value(0).toString());
                       painter.drawText(1300,i,query.value(1).toString());
                       painter.drawText(2200,i,query.value(2).toString());
                       painter.drawText(3200,i,query.value(3).toString());
                       painter.drawText(4500,i,query.value(4).toString());
                       painter.drawText(7700,i,query.value(5).toString());
                      i = i + 500;
                   }
                   int reponse = QMessageBox::question(this, "Enregistrement du fichier pdf", "Enregistrer le pdf des fournisseurs dans le Desktop ?", QMessageBox::Yes |  QMessageBox::No);
                       if (reponse == QMessageBox::Yes)
                       {

                           painter.end();
                       }
                       if (reponse == QMessageBox::No)
                       {
                            painter.end();
                       }
}




void Gestion_equipement_fournisseur::on_tabfournisseur_activated(const QModelIndex &index)
{
    QString val=ui->tabfournisseur->model()->data(index).toString();
        QSqlQuery query;
        query.prepare("SELECT * FROM FOURNISSEUR WHERE IDF='"+val+"'");
        if(query.exec())
        {
            while(query.next())
            {
                ui->lineEdit_idf->setText(query.value(0).toString());
                ui->lineEdit_nomff->setText(query.value(1).toString());
                //ui->comboBox_type_eq->setText(query.value(2).toString());
                ui->lineEdit_tel->setText(query.value(2).toString());
                ui->lineEdit_mail->setText(query.value(3).toString());
            }

        }
        else
        {
            QMessageBox::critical(this,tr("error::"),query.lastError().text());
        }
}

