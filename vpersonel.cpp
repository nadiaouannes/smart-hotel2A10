#include "vpersonel.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
vpersonel::vpersonel()
{
    id="";
    matricule="";
    marque="";

}
vpersonel::vpersonel(QString id,QString matricule,QString marque)
{
    this->id=id;
    this->matricule=matricule;
    this->marque=marque;
}
QString vpersonel::getid(){return id;}
QString vpersonel::getmatricule(){return matricule;}
QString vpersonel::getmarque(){return marque;}


bool vpersonel::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO  ABONNE(ID,MATRICULE,MARQUE) VALUES (:id,:matricule,:marque)");
    query.bindValue(":id",id);
    query.bindValue(":matricule",matricule);
    query.bindValue(":marque",marque);
    return query.exec();
}

bool vpersonel::supprimer(QString id)
{
QSqlQuery query;
    query.prepare("Delete from ABONNE where ID= :id");
    query.bindValue(":id",id);
return    query.exec();
}

QSqlQueryModel * vpersonel::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from ABONNE");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("MATRICULE"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("MARQUE"));


    return model;
}



