#include "perso.h"
#include "ui_perso.h"
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QPixmap>
#include<QSqlError>
#include<QPainter>
#include<QPdfWriter>
#include<QtWidgets>



perso::perso(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::perso)
{
    ui->setupUi(this);
   // QPixmap pixx("C:/Users/ASUS/Desktop/QT/fond3.png");
  //  ui->label_pic0->setPixmap(pixx);

    QPixmap paw("C:/Users/ASUS/Desktop/QT/retour.png");
    ui->label_5->setPixmap(paw.scaled(181,91,Qt::KeepAspectRatio));



    ui->tableView->setModel(tmpide.afficher());
}

perso::~perso()
{
    delete ui;
}

void perso::on_pushButton_clicked()
{
     close();
}

void perso::on_ajouter_clicked()
{
    QString id = ui->lineEdit_id->text();
    QString matricule= ui->lineEdit_matricule->text();
    QString marque= ui->lineEdit_marque->text();
vpersonel e(id,matricule,marque);

    bool test=e.ajouter();
    if(test)
    {ui->tableView->setModel(tmpide.afficher());

        QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
        notifyIcon->show();
        notifyIcon->setIcon(QIcon("icone.png"));

        notifyIcon->showMessage("GESTION PARKING  PERSONNELS ","vehicule ajouté",QSystemTrayIcon::Information,15000);

    QMessageBox::information(nullptr, QObject::tr("ajouter vehicule"),
                          QObject::tr("vehicule ajouté./n"
                             "click cancel to exit."),QMessageBox::Cancel);
    ui->lineEdit_id->clear();
    ui->lineEdit_matricule->clear();
    ui->lineEdit_marque->clear();

    }

    else
        QMessageBox::critical(nullptr, QObject::tr("ajouter vehicule"),
                              QObject::tr("Erreur !./n"
                                 "click cancel to exit."),QMessageBox::Cancel);
}

void perso::on_pushButton_3_clicked()
{
    QString id = ui->lineEdit_ids->text();
    bool test=tmpide.supprimer(id);
    if(test)
    {ui->lineEdit_ids->clear();
        ui->lineEdit_id->clear();
        ui->lineEdit_matricule->clear();
        ui->lineEdit_marque->clear();
        ui->tableView->setModel(tmpide.afficher());

        QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
        notifyIcon->show();
        notifyIcon->setIcon(QIcon("icone.png"));

        notifyIcon->showMessage("GESTION PARKING  PERSONNELS ","véhicule supprimé",QSystemTrayIcon::Information,15000);

        QMessageBox::information(nullptr, QObject::tr("Supprimer une véhicule"),
                    QObject::tr("véhicule supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une véhicule"),
                    QObject::tr("Erreur !.\n"
                     "Click Cancel to exit."), QMessageBox::Cancel);


    ui->lineEdit->clear();

}



void perso::on_pushButton_5_clicked()
{
    QString id = ui->lineEdit_id->text();
    QString matricule = ui->lineEdit_matricule->text();
    QString marque = ui->lineEdit_marque->text();

    QSqlQuery query;
    query.prepare("UPDATE ABONNE SET ID ='"+id+"',MATRICULE = '"+matricule+"',MARQUE = '"+marque+"' where ID = '"+id+"'");
;
    bool test = query.exec();
    if(test)
    {
ui->tableView->setModel(tmpide.afficher());
        ui->lineEdit_id->clear();
        ui->lineEdit_matricule->clear();
        ui->lineEdit_marque->clear();
        ui->lineEdit_ids->clear();

        QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
        notifyIcon->show();
        notifyIcon->setIcon(QIcon("icone.png"));

        notifyIcon->showMessage("GESTION PARKING  PERSONNELS ","véhicule Modifié",QSystemTrayIcon::Information,15000);

        QMessageBox::information(nullptr, QObject::tr("Modifier vehicule"),
                    QObject::tr("véhicule Modifié.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("modifier abonné"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }


}



void perso::on_lineEdit_textChanged(const QString &arg1)
{
    QSqlQueryModel *model= new QSqlQueryModel();
            QSqlQuery   *query= new QSqlQuery();
    if(ui->comboBox->currentText()=="ID"){
        query->prepare("SELECT * FROM Abonne WHERE ID LIKE'"+arg1+"%'");//+tri
query->exec();
    model->setQuery(*query);
ui->tableView->setModel(model);

    }
    else {
        if(ui->comboBox->currentText()=="Matricule"){
            query->prepare("SELECT * FROM Abonne WHERE MATRICULE LIKE'"+arg1+"%'");//+tri
    query->exec();
        model->setQuery(*query);
    ui->tableView->setModel(model);
        }
        else {if(ui->comboBox->currentText()=="Marque"){
            query->prepare("SELECT * FROM Abonne WHERE MARQUE LIKE'"+arg1+"%'");//+tri
    query->exec();
        model->setQuery(*query);
    ui->tableView->setModel(model);
            }
        }
    }
}



void perso::on_tableView_activated(const QModelIndex &index)
{
    QString val=ui->tableView->model()->data(index).toString();
       QSqlQuery qry;
       qry.prepare("select * from Abonne where ID='"+val+"'");
       if(qry.exec())
       {
           while(qry.next())
           {
               ui->lineEdit_id->setText(qry.value(0).toString());
               ui->lineEdit_ids->setText(qry.value(0).toString());
               ui->lineEdit_matricule->setText(qry.value(1).toString());
               ui->lineEdit_marque->setText(qry.value(2).toString());

           }

       }
       else
       {
           QMessageBox::critical(this,tr("error::"),qry.lastError().text());
       }
}

void perso::on_pushButton_2_clicked()
{
    //QDateTime datecreation = date.currentDateTime();
            //QString afficheDC = "Date de Creation PDF : " + datecreation.toString() ;
                   QPdfWriter pdf("C:/Users/ASUS/Desktop/QT/personels.pdf");
                   QPainter painter(&pdf);
                  int i = 4000;
                       painter.setPen(Qt::blue);
                       painter.setFont(QFont("Arial", 30));
                       painter.drawText(1100,1200,"Personels abonnes");
                       painter.setPen(Qt::black);
                       painter.setFont(QFont("Arial", 15));
                      // painter.drawText(1100,2000,afficheDC);
                       painter.drawRect(100,100,7300,2600);
                       //painter.drawPixmap(QRect(7600,70,2000,2600),QPixmap("C:/Users/RH/Desktop/projecpp/image/logopdf.png"));
                       painter.drawRect(0,3000,9600,500);
                       painter.setFont(QFont("Arial", 9));
                       painter.drawText(200,3300,"ID");
                       painter.drawText(1300,3300,"Matricule");
                       painter.drawText(2100,3300,"Marque");


                       QSqlQuery query;
                       query.prepare("select * from Abonne");
                       query.exec();
                       while (query.next())
                       {
                           painter.drawText(200,i,query.value(0).toString());
                           painter.drawText(1300,i,query.value(1).toString());
                           painter.drawText(2200,i,query.value(2).toString());


                          i = i + 500;
                       }
                       int reponse = QMessageBox::question(this, "Génerer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
                           if (reponse == QMessageBox::Yes)
                           {
                               QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
                               notifyIcon->show();
                               notifyIcon->setIcon(QIcon("icone.png"));

                               notifyIcon->showMessage("GESTION PARKING  PERSONNELS ","liste  véhicule prete à imprimer",QSystemTrayIcon::Information,15000);
                               painter.end();
                           }
                           if (reponse == QMessageBox::No)
                           {
                                painter.end();
                           }
}

void perso::on_pushButton_4_clicked()
{
    QSqlQueryModel *model= new QSqlQueryModel();
            QSqlQuery   *query= new QSqlQuery();
    if(ui->comboBox_2->currentText()=="ID"){
        query->prepare("SELECT * FROM Abonne order by ID");//+tri
query->exec();
    model->setQuery(*query);
ui->tableView->setModel(model);

    }
    else {
        if(ui->comboBox_2->currentText()=="Matricule"){
            query->prepare("SELECT * FROM Abonne order by matricule");//+tri
    query->exec();
        model->setQuery(*query);
    ui->tableView->setModel(model);
        }
        else {if(ui->comboBox_2->currentText()=="Marque"){
            query->prepare("SELECT * FROM Abonne order by marque");//+tri
    query->exec();
        model->setQuery(*query);
    ui->tableView->setModel(model);
        }
        }
    }
}

void perso::on_pushButton_6_clicked()
{
    ui->tableView->setModel(tmpide.afficher());
    ui->comboBox->setCurrentIndex(0);
    ui->comboBox_2->setCurrentIndex(0);
    ui->lineEdit_id->clear();
    ui->lineEdit_ids->clear();
    ui->lineEdit_matricule->clear();
    ui->lineEdit_marque->clear();
    ui->lineEdit->clear();
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
    notifyIcon->show();
    notifyIcon->setIcon(QIcon("icone.png"));

    notifyIcon->showMessage("GESTION PARKING  PERSONNELS ","system actualisé",QSystemTrayIcon::Information,15000);
}
