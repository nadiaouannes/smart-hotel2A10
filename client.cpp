#include "client.h"
#include "ui_client.h"
#include <QMessageBox>
#include <QPixmap>
#include<QSqlError>
#include<QPainter>
#include<QPdfWriter>
#include<QtWidgets>

client::client(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::client)
{
    ui->setupUi(this);
    //QPixmap pixx("C:/Users/ASUS/Desktop/QT/fond2.jpg");
   // ui->label_pic0->setPixmap(pixx.scaled(935,900,Qt::KeepAspectRatio));

    QPixmap paw("C:/Users/ASUS/Desktop/QT/retour.png");
    ui->label_5->setPixmap(paw.scaled(181,91,Qt::KeepAspectRatio));



    ui->tableView->setModel(tmpvehicule.afficher());
}

client::~client()
{
    delete ui;
}

void client::on_pushButton_clicked()
{
     close();
}

void client::on_ajouter_clicked()
{
    QString couleur = ui->lineEdit->text();
    QString marque= ui->lineEdit_2->text();
    QString matricule= ui->lineEdit_3->text();
    QString type= ui->comboBox->currentText();
vclients e(couleur,marque,matricule,type);




    bool test=e.ajouter();
    if(test)
    {
         ui->lineEdit->clear();
         ui->lineEdit_2->clear();
         ui->lineEdit_3->clear();
         ui->comboBox->setCurrentIndex(0);

        ui->tableView->setModel(tmpvehicule.afficher());//refresh
        QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
        notifyIcon->show();
        notifyIcon->setIcon(QIcon("icone.png"));

        notifyIcon->showMessage("GESTION PARKING  CLIENTS ","véhicule Ajouté",QSystemTrayIcon::Information,15000);

    QMessageBox::information(nullptr, QObject::tr("ajouter vehicule"),
                          QObject::tr("vehicule ajouté./n"
                             "click cancel to exit."),QMessageBox::Cancel);
    }

    else
        QMessageBox::critical(nullptr, QObject::tr("ajouter vehicule"),
                              QObject::tr("Erreur !./n"
                                 "click cancel to exit."),QMessageBox::Cancel);
}

void client::on_pushButton_3_clicked()
{
    QString matricule = ui->lineEdit_4->text();
    bool test=tmpvehicule.supprimer(matricule);
    if(test)
    {ui->tableView->setModel(tmpvehicule.afficher());//refresh
        ui->lineEdit_4->clear();
        QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
        notifyIcon->show();
        notifyIcon->setIcon(QIcon("icone.png"));

        notifyIcon->showMessage("GESTION PARKING  CLIENTS ","véhicule supprimé",QSystemTrayIcon::Information,15000);

        QMessageBox::information(nullptr, QObject::tr("Supprimer une véhicule"),
                    QObject::tr("véhicule supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une véhicule"),
                    QObject::tr("Erreur !.\n"
                     "Click Cancel to exit."), QMessageBox::Cancel);
}

void client::on_tableView_activated(const QModelIndex &index)
{
    QString val=ui->tableView->model()->data(index).toString();
       QSqlQuery qry;
       qry.prepare("select * from VEHICULE where MATRICULE='"+val+"'");
       if(qry.exec())
       {
           while(qry.next())
           {
               ui->lineEdit_4->setText(qry.value(0).toString());
               ui->lineEdit_3->setText(qry.value(0).toString());
               ui->lineEdit_2->setText(qry.value(1).toString());
               ui->lineEdit->setText(qry.value(2).toString());
               ui->comboBox->setCurrentText(qry.value(3).toString());

           }

       }
       else
       {
           QMessageBox::critical(this,tr("error::"),qry.lastError().text());
       }
}

void client::on_pushButton_5_clicked()
{

    QString couleur = ui->lineEdit->text();
    QString marque= ui->lineEdit_2->text();
    QString matricule= ui->lineEdit_3->text();
    QString type= ui->comboBox->currentText();

    QSqlQuery query;
    query.prepare("UPDATE VEHICULE SET MATRICULE='"+matricule+"',MARQUE='"+marque+"',COULEUR='"+couleur+"',TYPE='"+type+"' where MATRICULE = '"+matricule+"'");
    bool test = query.exec();
    if(test)
    {

       ui->tableView->setModel(tmpvehicule.afficher());
       ui->lineEdit->clear();
       ui->lineEdit_2->clear();
       ui->lineEdit_3->clear();
       ui->comboBox->setCurrentIndex(0);
       ui->lineEdit_4->clear();
       QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
       notifyIcon->show();
       notifyIcon->setIcon(QIcon("icone.png"));

       notifyIcon->showMessage("GESTION PARKING  CLIENTS ","véhicule Modifié",QSystemTrayIcon::Information,15000);

        QMessageBox::information(nullptr, QObject::tr("Modifier véhicule"),
                    QObject::tr("véhicule Modifieé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);



    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Modifier véhicule"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void client::on_lineEdit_5_textChanged(const QString &arg1)
{
    QSqlQueryModel *model= new QSqlQueryModel();
            QSqlQuery   *query= new QSqlQuery();
    if(ui->comboBox_2->currentText()=="Couleur"){
        query->prepare("SELECT * FROM VEHICULE WHERE COULEUR LIKE'"+arg1+"%'order by matricule");//+tri
query->exec();
    model->setQuery(*query);
ui->tableView->setModel(model);


    }
    else {
        if(ui->comboBox_2->currentText()=="Marque"){
            query->prepare("SELECT * FROM VEHICULE WHERE MARQUE LIKE'"+arg1+"%'order by matricule");//+tri
    query->exec();
        model->setQuery(*query);
    ui->tableView->setModel(model);
        }
        else {
            if(ui->comboBox_2->currentText()=="Matricule"){
            query->prepare("SELECT * FROM VEHICULE WHERE MATRICULE LIKE'"+arg1+"%'order by matricule");//+tri
    query->exec();
        model->setQuery(*query);
    ui->tableView->setModel(model);
            }

        }

    }
}

void client::on_pushButton_2_clicked()
{
    //QDateTime datecreation = date.currentDateTime();
            //QString afficheDC = "Date de Creation PDF : " + datecreation.toString() ;
                   QPdfWriter pdf("C:/Users/ASUS/Desktop/QT/client.pdf");
                   QPainter painter(&pdf);
                  int i = 4000;
                       painter.setPen(Qt::blue);
                       painter.setFont(QFont("Arial", 30));
                       painter.drawText(1100,1200,"Liste Des Vehicule Client");
                       painter.setPen(Qt::black);
                       painter.setFont(QFont("Arial", 15));
                      // painter.drawText(1100,2000,afficheDC);
                       painter.drawRect(100,100,7300,2600);
                       //painter.drawPixmap(QRect(7600,70,2000,2600),QPixmap("C:/Users/RH/Desktop/projecpp/image/logopdf.png"));
                       painter.drawRect(0,3000,9600,500);
                       painter.setFont(QFont("Arial", 9));
                       painter.drawText(200,3300,"Matricule");
                       painter.drawText(1300,3300,"Marque");
                       painter.drawText(2100,3300,"Couleur");
                       painter.drawText(3200,3300,"Type");

                       QSqlQuery query;
                       query.prepare("select * from VEHICULE");
                       query.exec();
                       while (query.next())
                       {
                           painter.drawText(200,i,query.value(0).toString());
                           painter.drawText(1300,i,query.value(1).toString());
                           painter.drawText(2200,i,query.value(2).toString());
                           painter.drawText(3200,i,query.value(3).toString());

                          i = i + 500;
                       }
                       int reponse = QMessageBox::question(this, "Génerer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
                           if (reponse == QMessageBox::Yes)
                           {
                               QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
                               notifyIcon->show();
                               notifyIcon->setIcon(QIcon("icone.png"));

                               notifyIcon->showMessage("GESTION PARKING CLIENTS ","Liste vehicule prete à imprimer",QSystemTrayIcon::Information,15000);

                               painter.end();
                           }
                           if (reponse == QMessageBox::No)
                           {
                                painter.end();
                           }
}

void client::on_pushButton_4_clicked()
{
    QSqlQueryModel *model= new QSqlQueryModel();
            QSqlQuery   *query= new QSqlQuery();
    if(ui->comboBox_3->currentText()=="Couleur"){
        query->prepare("SELECT * FROM VEHICULE order by COULEUR");//+tri
query->exec();
    model->setQuery(*query);
ui->tableView->setModel(model);




    }
    else {
        if(ui->comboBox_3->currentText()=="Marque"){
            query->prepare("SELECT * FROM VEHICULE order by MARQUE");//+tri
    query->exec();
        model->setQuery(*query);
    ui->tableView->setModel(model);
        }
        else {
            if(ui->comboBox_3->currentText()=="Matricule"){
            query->prepare("SELECT * FROM VEHICULE order by matricule");//+tri
    query->exec();
        model->setQuery(*query);
    ui->tableView->setModel(model);
            }

        }

    }
}

void client::on_pushButton_6_clicked()
{
    ui->comboBox->setCurrentIndex(0);
    ui->comboBox_2->setCurrentIndex(0);
    ui->comboBox_3->setCurrentIndex(0);
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
    ui->tableView->setModel(tmpvehicule.afficher());

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
    notifyIcon->show();
    notifyIcon->setIcon(QIcon("icone.png"));

    notifyIcon->showMessage("GESTION PARKING  CLIENTS ","system actualisé",QSystemTrayIcon::Information,15000);
}
