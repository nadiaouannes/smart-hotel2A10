#include "reservation.h"
#include <QDebug>
#include "connexion.h"
reservation::reservation()
{
    id=0;
    nom="";
    type="";
    jours=0;
}

reservation::reservation(int id,QString nom,QString type,int jours)
{
  this->id=id;
  this->nom=nom;
  this->type=type;
  this->jours=jours;
}
QString reservation::get_nom(){return  nom;}
QString reservation::get_type(){return type;}
int reservation::get_id(){return  id;}
int reservation::get_j(){return  jours;}

bool reservation::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO reservation (ID, NOM, TYPE,JOURS) "
                    "VALUES (:id, :nom, :type, :jours)");
query.bindValue(":id", res);
query.bindValue(":nom", nom);
query.bindValue(":type", type);
query.bindValue(":jours", jours);



return    query.exec();
}

QSqlQueryModel * reservation::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from reservation");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("type"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("jours"));
    return model;
}

bool reservation::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from reservation where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}

QSqlQueryModel * reservation::recherche(QString nom)
{

    QSqlQueryModel *model=new QSqlQueryModel;
    QSqlQuery query;
    query.prepare("select * from reservation where nom = :nom");
    query.bindValue(":nom",nom);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("jours"));
    return model;
}

