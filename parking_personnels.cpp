#include "parking_personnels.h"
#include "ui_parking_personnels.h"
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QPixmap>

parking_personnels::parking_personnels(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::parking_personnels)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/ASUS/Desktop/QT/ajj.png");
    ui->label_aj->setPixmap(pix.scaled(221,221,Qt::KeepAspectRatio));

    QPixmap p("C:/Users/ASUS/Desktop/QT/supp.png");
    ui->label_supp->setPixmap(p.scaled(221,221,Qt::KeepAspectRatio));

    QPixmap pa("C:/Users/ASUS/Desktop/QT/ajj.png");
    ui->label_add->setPixmap(pa.scaled(181,91,Qt::KeepAspectRatio));

    QPixmap paw("C:/Users/ASUS/Desktop/QT/retour.png");
    ui->label_5->setPixmap(paw.scaled(181,91,Qt::KeepAspectRatio));

    QPixmap pr("C:/Users/ASUS/Desktop/QT/retour.png");
    ui->label_retour->setPixmap(pr.scaled(181,91,Qt::KeepAspectRatio));

    QPixmap pixx("C:/Users/ASUS/Desktop/QT/fond2.jpg");
    ui->label_pic0->setPixmap(pixx.scaled(935,725,Qt::KeepAspectRatio));

    QPixmap pixxx("C:/Users/ASUS/Desktop/QT/fond2.jpg");
    ui->label_pic1->setPixmap(pixxx.scaled(935,725,Qt::KeepAspectRatio));

    QPixmap pixxxx("C:/Users/ASUS/Desktop/QT/fond2.jpg");
    ui->label_pic2->setPixmap(pixxxx.scaled(935,725,Qt::KeepAspectRatio));

    QPixmap pixxxxx("C:/Users/ASUS/Desktop/QT/fond2.jpg");
    ui->label_pic3->setPixmap(pixxxxx.scaled(935,725,Qt::KeepAspectRatio));

    QPixmap pixxxxxx("C:/Users/ASUS/Desktop/QT/fond2.jpg");
    ui->label_pic4->setPixmap(pixxxxxx.scaled(935,725,Qt::KeepAspectRatio));

    QPixmap p2("C:/Users/ASUS/Desktop/QT/supp.png");
    ui->label_supp2->setPixmap(p2.scaled(221,221,Qt::KeepAspectRatio));

    QPixmap prr("C:/Users/ASUS/Desktop/QT/retour.png");
    ui->label_retour1->setPixmap(prr.scaled(181,91,Qt::KeepAspectRatio));

    QPixmap pm("C:/Users/ASUS/Desktop/QT/mod.png");
    ui->label_mod->setPixmap(pm.scaled(230,130,Qt::KeepAspectRatio));

    QPixmap pm2("C:/Users/ASUS/Desktop/QT/mod.png");
    ui->label_mod2->setPixmap(pm2.scaled(230,130,Qt::KeepAspectRatio));

    QPixmap paf("C:/Users/ASUS/Desktop/QT/aff.png");
    ui->label_aff->setPixmap(paf.scaled(240,140,Qt::KeepAspectRatio));

    QPixmap prrr("C:/Users/ASUS/Desktop/QT/retour.png");
    ui->label_retour2->setPixmap(prrr.scaled(181,91,Qt::KeepAspectRatio));

    QPixmap prrrr("C:/Users/ASUS/Desktop/QT/retour.png");
    ui->label_retour3->setPixmap(prrrr.scaled(181,91,Qt::KeepAspectRatio));





    ui->stackedWidget->setCurrentIndex(0);
}

parking_personnels::~parking_personnels()
{
    delete ui;
}
void parking_personnels::on_ajout_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void parking_personnels::on_ajouter_clicked()
{
    QString id = ui->lineEdit_id->text();
    QString nom= ui->lineEdit_nom->text();
    QString prenom= ui->lineEdit_prenom->text();
vpersonel e(id,nom,prenom);

    bool test=e.ajouter();
    if(test)
    {
    QMessageBox::information(nullptr, QObject::tr("ajouter vehicule"),
                          QObject::tr("vehicule ajouté./n"
                             "click cancel to exit."),QMessageBox::Cancel);
    ui->lineEdit_id->clear();
    ui->lineEdit_nom->clear();
    ui->lineEdit_prenom->clear();

    }

    else
        QMessageBox::critical(nullptr, QObject::tr("ajouter vehicule"),
                              QObject::tr("Erreur !./n"
                                 "click cancel to exit."),QMessageBox::Cancel);
}



void parking_personnels::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void parking_personnels::on_pushButton_clicked()
{
    close();
}

void parking_personnels::on_pushButton_3_clicked()
{
    QString id = ui->lineEdit_ids->text();
    bool test=tmpide.supprimer();
    if(test)
    {ui->lineEdit_ids->clear();
        QMessageBox::information(nullptr, QObject::tr("Supprimer une véhicule"),
                    QObject::tr("véhicule supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une véhicule"),
                    QObject::tr("Erreur !.\n"
                     "Click Cancel to exit."), QMessageBox::Cancel);
}


void parking_personnels::on_supp_clicked()
{
    QSqlQueryModel *model= new QSqlQueryModel();
            QSqlQuery   *query= new QSqlQuery();

            query->prepare("SELECT * FROM ABONNE order by nom");//+tri
    query->exec();
        model->setQuery(*query);
    ui->tableView->setModel(model);
    ui->stackedWidget->setCurrentIndex(2);

}

void parking_personnels::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void parking_personnels::on_pushButton_5_clicked()
{
    QString id = ui->lineEdit_5->text();
    QString nom = ui->lineEdit_6->text();
    QString prenom = ui->lineEdit_7->text();

    QSqlQuery query;
    query.prepare("UPDATE ABONNE SET ID =:id,NOM = :nom,PRENOM = :prenom where ID = :id");
    query.bindValue(":id",id);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    bool test = query.exec();
    if(test)
    {


        QMessageBox::information(nullptr, QObject::tr("Modifier abonné"),
                    QObject::tr("véhicule Modifier.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("modifier abonné"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }

    ui->lineEdit_7->clear();
    ui->lineEdit_6->clear();
    ui->lineEdit_5->clear();
}

void parking_personnels::on_mod_clicked()
{
    QSqlQueryModel *model= new QSqlQueryModel();
            QSqlQuery   *query= new QSqlQuery();

            query->prepare("SELECT * FROM ABONNE order by nom");//+tri
    query->exec();
        model->setQuery(*query);
    ui->tableView_3->setModel(model);
    ui->stackedWidget->setCurrentIndex(3);

}



void parking_personnels::on_lineEdit_5_textChanged(const QString &arg1)
{
    QSqlQueryModel *model= new QSqlQueryModel();
            QSqlQuery   *query= new QSqlQuery();

            query->prepare("SELECT * FROM Abonne WHERE ID LIKE'"+arg1+"%'order by nom");//+tri
    query->exec();
        model->setQuery(*query);
    ui->tableView_3->setModel(model);
}

void parking_personnels::on_pushButton_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void parking_personnels::on_lineEdit_ids_textChanged(const QString &arg1)
{
    QSqlQueryModel *model= new QSqlQueryModel();
            QSqlQuery   *query= new QSqlQuery();

            query->prepare("SELECT * FROM Abonne WHERE ID LIKE'"+arg1+"%'order by nom");//+tri
    query->exec();
        model->setQuery(*query);
    ui->tableView->setModel(model);
}

void parking_personnels::on_aff_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
    QSqlQueryModel *model= new QSqlQueryModel();
            QSqlQuery   *query= new QSqlQuery();

            query->prepare("SELECT * FROM Abonne order by nom");//+tri
    query->exec();
        model->setQuery(*query);
    ui->tableView_2->setModel(model);


}


void parking_personnels::on_lineEdit_textChanged(const QString &arg1)
{
    QSqlQueryModel *model= new QSqlQueryModel();
            QSqlQuery   *query= new QSqlQuery();
    if(ui->comboBox->currentText()=="ID"){
        query->prepare("SELECT * FROM Abonne WHERE ID LIKE'"+arg1+"%'order by nom");//+tri
query->exec();
    model->setQuery(*query);
ui->tableView_2->setModel(model);

    }
    else {
        if(ui->comboBox->currentText()=="Nom"){
            query->prepare("SELECT * FROM Abonne WHERE NOM LIKE'"+arg1+"%'order by nom");//+tri
    query->exec();
        model->setQuery(*query);
    ui->tableView_2->setModel(model);
        }
        else {
            query->prepare("SELECT * FROM Abonne WHERE PRENOM LIKE'"+arg1+"%'order by nom");//+tri
    query->exec();
        model->setQuery(*query);
    ui->tableView_2->setModel(model);
        }
    }
}

void parking_personnels::on_pushButton_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

