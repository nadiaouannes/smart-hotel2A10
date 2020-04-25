

#include "parking_clients.h"
#include "ui_parking_clients.h"
#include "choix.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlQueryModel>
#include<QMediaPlayer>
#include<QPixmap>
#include<QtWidgets>

#include "vclients.h"


parking_clients::parking_clients(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::parking_clients)
{
    ui->setupUi(this);

    QPixmap pix("C:/Users/ASUS/Desktop/QT/camion.png");
    ui->label_camion->setPixmap(pix.scaled(221,221,Qt::KeepAspectRatio));

    QPixmap pi("C:/Users/ASUS/Desktop/QT/taxi.jpg");
    ui->label_taxi->setPixmap(pi.scaled(221,221,Qt::KeepAspectRatio));

    QPixmap p("C:/Users/ASUS/Desktop/QT/voiture.jpg");
    ui->label_voiture->setPixmap(p.scaled(221,221,Qt::KeepAspectRatio));

    QPixmap pixa("C:/Users/ASUS/Desktop/QT/ajj.png");
    ui->label_aj->setPixmap(pixa.scaled(221,221,Qt::KeepAspectRatio));

    QPixmap paaa("C:/Users/ASUS/Desktop/QT/supp.png");
    ui->label_supp->setPixmap(paaa.scaled(221,221,Qt::KeepAspectRatio));



    QPixmap paw("C:/Users/ASUS/Desktop/QT/retour.png");
    ui->label_10->setPixmap(paw.scaled(181,91,Qt::KeepAspectRatio));



    QPixmap pixx("C:/Users/ASUS/Desktop/QT/fond2.jpg");
    ui->label_pic0->setPixmap(pixx.scaled(935,725,Qt::KeepAspectRatio));



    QPixmap pm("C:/Users/ASUS/Desktop/QT/mod.png");
    ui->label_mod->setPixmap(pm.scaled(230,130,Qt::KeepAspectRatio));



    QPixmap paf("C:/Users/ASUS/Desktop/QT/aff.png");
    ui->label_aff->setPixmap(paf.scaled(240,140,Qt::KeepAspectRatio));







}

parking_clients::~parking_clients()
{
    delete ui;
}
int parking_clients::getChoixzone()
{
    return choixzone;
}
void parking_clients::setChoixzone(int a)
{
    choixzone=a;
}
int parking_clients::getChoix()
{
    return choix;
}
void parking_clients::setChoix(int a)
{
    choix=a;
}
void   parking_clients::Refresh(int choixzone)
{
   QSqlQueryModel *model= new QSqlQueryModel();
        QSqlQuery   *query= new QSqlQuery();
        QString type;
        if(choixzone==1)
        {
            type="voiture";
        }
        else if(choixzone==2)
        {
            type="taxi";
        }
        else if(choixzone==3)
        {
            type="camion";
        }
                 query->prepare("SELECT * FROM VEHICULE WHERE TYPE=:type");
                 query->bindValue(":type",type);
            query->exec();
                model->setQuery(*query);
            ui->tableView->setModel(model);
}

void parking_clients::on_pushButton_11_clicked()
{

    close();

}

void parking_clients::on_pushButton_clicked()//ajouter
{
    QString couleur = ui->lineEdit->text();
    QString marque= ui->lineEdit_2->text();
    QString matricule= ui->lineEdit_3->text();
vclients e(couleur,marque,matricule);




    bool test=e.ajouter(choixzone);
    if(test)
    {parking_clients::Refresh(choixzone);//refresh
    QMessageBox::information(nullptr, QObject::tr("ajouter vehicule"),
                          QObject::tr("vehicule ajouté./n"
                             "click cancel to exit."),QMessageBox::Cancel);
    }

    else
        QMessageBox::critical(nullptr, QObject::tr("ajouter vehicule"),
                              QObject::tr("Erreur !./n"
                                 "click cancel to exit."),QMessageBox::Cancel);
}

void parking_clients::on_pushButton_2_clicked()
{




    ui->stackedWidget->setCurrentIndex(0);
}

void parking_clients::on_pushButton_3_clicked()//supprimer
{

    QString matricule = ui->lineEdit_4->text();
    bool test=tmpvehicule.supprimer(matricule);
    if(test)
    {parking_clients::Refresh(choixzone);//refresh
        ui->lineEdit_4->clear();
        QMessageBox::information(nullptr, QObject::tr("Supprimer une véhicule"),
                    QObject::tr("véhicule supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une véhicule"),
                    QObject::tr("Erreur !.\n"
                     "Click Cancel to exit."), QMessageBox::Cancel);
}

void parking_clients::on_pushButton_5_clicked()
{


    ui->stackedWidget->setCurrentIndex(0);
}

void parking_clients::on_pushButton_4_clicked()//modifier
{




    QString matricule = ui->lineEdit_8->text();
    QString nouvmatricule = ui->lineEdit_5->text();
    QString couleur = ui->lineEdit_7->text();
    QString marque = ui->lineEdit_6->text();

    QSqlQuery query;
    query.prepare("UPDATE VEHICULE SET MATRICULE=:nouvmatricule,MARQUE=:marque,COULEUR=:couleur where MATRICULE = :matricule");
    query.bindValue(":couleur",couleur);
    query.bindValue(":marque",marque);
    query.bindValue(":matricule",matricule);
    query.bindValue(":nouvmatricule",nouvmatricule);
    bool test = query.exec();
    if(test)
    {

        parking_clients::Refresh(choixzone);

        QMessageBox::information(nullptr, QObject::tr("Modifier véhicule"),
                    QObject::tr("véhicule Modifier.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Supprimer véhicule"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    ui->lineEdit_8->clear();
    ui->lineEdit_7->clear();
    ui->lineEdit_6->clear();
    ui->lineEdit_5->clear();


}

void parking_clients::on_ADD_clicked()
{



    setChoix(1);
    ui->stackedWidget->setCurrentIndex(5);

}

void parking_clients::on_DELETE_clicked()
{



    setChoix(2);
    ui->stackedWidget->setCurrentIndex(5);

}

void parking_clients::on_EDIT_clicked()
{



    setChoix(3);
    ui->stackedWidget->setCurrentIndex(5);

}

void parking_clients::on_SHOW_clicked()
{



    setChoix(4);
    ui->stackedWidget->setCurrentIndex(5);
}

void parking_clients::on_pushButton_6_clicked()
{



    ui->stackedWidget->setCurrentIndex(0);
}

void parking_clients::on_pushButton_7_clicked()
{



    ui->stackedWidget->setCurrentIndex(0);
}

void parking_clients::on_pushButton_8_clicked()
{



     setChoixzone(1);
     parking_clients::Refresh(choixzone);
     ui->stackedWidget->setCurrentIndex(choix);
}

void parking_clients::on_pushButton_9_clicked()
{



    setChoixzone(2);
    parking_clients::Refresh(choixzone);
    ui->stackedWidget->setCurrentIndex(choix);
}

void parking_clients::on_pushButton_10_clicked()
{



    setChoixzone(3);
    parking_clients::Refresh(choixzone);
    ui->stackedWidget->setCurrentIndex(choix);
}



void parking_clients::on_lineEdit_10_textChanged(const QString &arg1)//filtre
{

    QSqlQueryModel *model= new QSqlQueryModel();
            QSqlQuery   *query= new QSqlQuery();
            QString type;
            if(choixzone==1)
            {
                type="voiture";
            }
            else if(choixzone==2)
            {
                type="taxi";
            }
            else if(choixzone==3)
            {
                type="camion";
            }
            query->prepare("SELECT * FROM VEHICULE WHERE TYPE=:type AND MATRICULE LIKE'"+arg1+"%'order by marque");//+tri
            query->bindValue(":type",type);
    query->exec();
        model->setQuery(*query);
    ui->tableView->setModel(model);
}





