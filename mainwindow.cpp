#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "menu.h"
#include "connexion.h"
#include "QMessageBox"
#include "stocke.h"
#include "QPixmap"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include<QSqlError>
#include<QPainter>
#include<QPdfWriter>
#include<QPaintEvent>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/pic");
    ui->label_pic->setPixmap(pix.scaled(1920,1050,Qt::KeepAspectRatio));
    QPixmap pix1("C:/Users/pic");
    ui->label_pic_2->setPixmap(pix.scaled(1920,1050,Qt::KeepAspectRatio));



    ui->tabmenu->setModel(tmpmenu->afficher());
     ui->tabstocke->setModel(tmpstocke->afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}





void MainWindow::on_pb_ajouter_m_clicked()
{
    int id = ui->lineEdit_id->text().toInt();
    QString entree= ui->lineEdit_entree->text();
    QString suite = ui->lineEdit_suite->text();
    QString dessert = ui->lineEdit_dessert->text();


    Menu m(id,entree,suite,dessert);

    bool test=m.ajouter();

    if(test)
  {

        ui->tabmenu->setModel(tmpmenu->afficher());//refresh
  QMessageBox::information(nullptr, QObject::tr("Ajouter menu"),
                    QObject::tr("menu ajouté.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

  }
    else
        QMessageBox::critical(nullptr, QObject::tr("Ajouter un menu"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    ui->lineEdit_ids->clear();
    ui->lineEdit_produit->clear();
    ui->lineEdit_prix->clear();
    ui->lineEdit_quantite->clear();

}









void MainWindow::on_pb_ajouter_s_clicked()
{
    int ids = ui->lineEdit_ids->text().toInt();
    QString produit= ui->lineEdit_produit->text();
    int prix = ui->lineEdit_prix->text().toInt();
    int quantite = ui->lineEdit_quantite->text().toInt();



    Stocke s(ids,produit,prix,quantite);

    bool test=s.ajouter();

    if(test)
  {

        ui->tabstocke->setModel(tmpstocke->afficher());//refresh
  QMessageBox::information(nullptr, QObject::tr("Ajouter stocke"),
                    QObject::tr("stocke ajouté.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

  }
    else
        QMessageBox::critical(nullptr, QObject::tr("Ajouter un stocke"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    ui->lineEdit_ids->clear();
    ui->lineEdit_produit->clear();
    ui->lineEdit_prix->clear();
    ui->lineEdit_quantite->clear();
}









void MainWindow::on_pb_supprimer_m_clicked()
{
    int id = ui -> lineEdit_id->text().toInt();
    bool test=tmpmenu->supprimer(id);
    if(test)
    { ui->tabmenu->setModel(tmpmenu->afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer menu"),
                          QObject::tr("menu supprimer.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);

        }
          else
              QMessageBox::critical(nullptr, QObject::tr("supprimer un menu"),
                          QObject::tr("Erreur !.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);

    ui->lineEdit_ids->clear();
    ui->lineEdit_produit->clear();
    ui->lineEdit_prix->clear();
    ui->lineEdit_quantite->clear();

}







void MainWindow::on_pb_supprimer_s_clicked()
{
    int ids = ui -> lineEdit_ids->text().toInt();
    bool test=tmpstocke->supprimer(ids);
    if(test)
    { ui->tabstocke->setModel(tmpstocke->afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer stocke"),
                          QObject::tr("stocke supprimer.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);

        }
          else
              QMessageBox::critical(nullptr, QObject::tr("supprimer un stocke"),
                          QObject::tr("Erreur !.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);

    ui->lineEdit_ids->clear();
    ui->lineEdit_produit->clear();
    ui->lineEdit_prix->clear();
    ui->lineEdit_quantite->clear();
}








void MainWindow::on_pb_modifier_m_clicked()
{
    int id = ui->lineEdit_id->text().toInt();

            QString entree = ui->lineEdit_entree->text();
            QString suite = ui->lineEdit_suite->text();
            QString dessert = ui->lineEdit_dessert->text();

            Menu men (id,entree,suite,dessert);

            QSqlQuery query;

            bool test=men.modifier();
            if(test)
            {

ui->tabmenu->setModel(tmpmenu->afficher());//refresh
                QMessageBox::information(nullptr, QObject::tr("Modifier menu"),
                            QObject::tr("Menu Modifier.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

            }
            else
            {
                QMessageBox::critical(nullptr, QObject::tr("Supprimer menu"),
                            QObject::tr("Erreur !.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
            }

            ui->lineEdit_id->clear();
            ui->lineEdit_entree->clear();
            ui->lineEdit_suite->clear();
            ui->lineEdit_dessert->clear();




    }












void MainWindow::on_pb_modifier_s_clicked()
{
           int ids = ui->lineEdit_ids->text().toInt();

            QString produit = ui->lineEdit_produit->text();
             int prix = ui->lineEdit_prix->text().toInt();
              int quantite = ui->lineEdit_quantite->text().toInt();


            Stocke stoc (ids,produit,prix,quantite);

            QSqlQuery query;

            bool test=stoc.modifier();
            if(test)
            {

ui->tabstocke->setModel(tmpstocke->afficher());//refresh
                QMessageBox::information(nullptr, QObject::tr("Modifier stocke"),
                            QObject::tr("Stocke Modifier.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

            }
            else
            {
                QMessageBox::critical(nullptr, QObject::tr("Supprimer stocke"),
                            QObject::tr("Erreur !.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
            }

            ui->lineEdit_ids->clear();
            ui->lineEdit_produit->clear();
            ui->lineEdit_prix->clear();
            ui->lineEdit_quantite->clear();




}


void MainWindow::on_pushButton_trie_m_clicked()
{
    ui->tabmenu->setModel(tmpmenu->afficher_tri());

}

void MainWindow::on_pushButton_trie_s_clicked()
{
    ui->tabstocke->setModel(tmpstocke->tri());
}

void MainWindow::on_pb_rech_m_clicked()
{
    QString entree = ui->lineEdit_rech_m->text();
           ui->tabmenu->setModel(tmpmenu->recherche_nom(entree));
}











void MainWindow::on_pb_rech_s_clicked()
{
    QString produit = ui->lineEdit_rech_s->text();
           ui->tabstocke->setModel(tmpstocke->recherche_p(produit));
}

void MainWindow::on_pushButton_clicked()
{
    this->close();
}

void MainWindow::on_pushButton_2_clicked()
{
    this->close();
}

void MainWindow::on_pb_pdf_m_clicked()
{
    //QDateTime datecreation = date.currentDateTime();
        //QString afficheDC = "Date de Creation PDF : " + datecreation.toString() ;
               QPdfWriter pdf("C:/Users/HP-PC/Desktop/menu.pdf");
               QPainter painter(&pdf);
              int i = 4000;
                   painter.setPen(Qt::blue);
                   painter.setFont(QFont("Arial", 30));
                   painter.drawText(1100,1200,"Liste De menu");
                   painter.setPen(Qt::black);
                   painter.setFont(QFont("Arial", 15));
                  // painter.drawText(1100,2000,afficheDC);
                   painter.drawRect(100,100,7300,2600);
                   //painter.drawPixmap(QRect(7600,70,2000,2600),QPixmap("C:/Users/RH/Desktop/projecpp/image/logopdf.png"));
                   painter.drawRect(0,3000,9600,500);
                   painter.setFont(QFont("Arial", 9));
                   painter.drawText(200,3300,"ID");
                   painter.drawText(1300,3300,"ENTREE");
                   painter.drawText(2100,3300,"SUITE");
                   painter.drawText(3200,3300,"DESSERT");

                   QSqlQuery query;
                   query.prepare("select * from MENU");
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
                   int reponse = QMessageBox::question(this, "Génerer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
                       if (reponse == QMessageBox::Yes)
                       {

                           painter.end();
                       }
                       if (reponse == QMessageBox::No)
                       {
                            painter.end();
                       }
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->tabmenu->setModel(tmpmenu->afficher());
}
