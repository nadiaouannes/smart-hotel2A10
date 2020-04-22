#include "perso.h"
#include "ui_perso.h"
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QPixmap>


perso::perso(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::perso)
{
    ui->setupUi(this);
    QPixmap pixx("C:/Users/ASUS/Desktop/QT/fond2.jpg");
    ui->label_pic0->setPixmap(pixx.scaled(935,900,Qt::KeepAspectRatio));

    QPixmap paw("C:/Users/ASUS/Desktop/QT/retour.png");
    ui->label_5->setPixmap(paw.scaled(181,91,Qt::KeepAspectRatio));

    QPixmap p2("C:/Users/ASUS/Desktop/QT/supp.png");
    ui->label_supp2->setPixmap(p2.scaled(181,91,Qt::KeepAspectRatio));

    QPixmap pa("C:/Users/ASUS/Desktop/QT/ajj.png");
    ui->label_add->setPixmap(pa.scaled(181,91,Qt::KeepAspectRatio));

    QPixmap pm2("C:/Users/ASUS/Desktop/QT/mod.png");
    ui->label_mod2->setPixmap(pm2.scaled(181,91,Qt::KeepAspectRatio));
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

void perso::on_pushButton_3_clicked()
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

    ui->label_ids->clear();
    ui->lineEdit->clear();

}

void perso::on_lineEdit_ids_textChanged(const QString &arg1)
{
    QSqlQueryModel *model= new QSqlQueryModel();
            QSqlQuery   *query= new QSqlQuery();

            query->prepare("SELECT * FROM Abonne WHERE ID LIKE'"+arg1+"%'order by nom");//+tri
    query->exec();
        model->setQuery(*query);
    ui->tableView->setModel(model);
}

void perso::on_pushButton_5_clicked()
{
    QString id = ui->lineEdit_id->text();
    QString nom = ui->lineEdit_nom->text();
    QString prenom = ui->lineEdit_prenom->text();

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

    ui->lineEdit_id->clear();
    ui->lineEdit_nom->clear();
    ui->lineEdit_prenom->clear();
    ui->lineEdit->clear();
    ui->lineEdit_ids->clear();
}

void perso::on_lineEdit_id_textChanged(const QString &arg1)
{
    QSqlQueryModel *model= new QSqlQueryModel();
            QSqlQuery   *query= new QSqlQuery();

            query->prepare("SELECT * FROM Abonne WHERE ID LIKE'"+arg1+"%'order by nom");//+tri
    query->exec();
        model->setQuery(*query);
    ui->tableView->setModel(model);
}

void perso::on_lineEdit_textChanged(const QString &arg1)
{
    QSqlQueryModel *model= new QSqlQueryModel();
            QSqlQuery   *query= new QSqlQuery();
    if(ui->comboBox->currentText()=="ID"){
        query->prepare("SELECT * FROM Abonne WHERE ID LIKE'"+arg1+"%'order by nom");//+tri
query->exec();
    model->setQuery(*query);
ui->tableView->setModel(model);
ui->lineEdit_id->setText(arg1);
ui->lineEdit_ids->setText(arg1);

    }
    else {
        if(ui->comboBox->currentText()=="Nom"){
            query->prepare("SELECT * FROM Abonne WHERE NOM LIKE'"+arg1+"%'order by nom");//+tri
    query->exec();
        model->setQuery(*query);
    ui->tableView->setModel(model);
        }
        else {
            query->prepare("SELECT * FROM Abonne WHERE PRENOM LIKE'"+arg1+"%'order by nom");//+tri
    query->exec();
        model->setQuery(*query);
    ui->tableView->setModel(model);
        }
    }
}
