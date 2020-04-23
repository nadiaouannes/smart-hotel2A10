#include "client.h"
#include <QDebug>
#include "connexion.h"
Client::Client()
{
id=0;
nom="";
prenom="";
n_cin=0;
chambre="";
jours=0;
}
Client::Client(int id,QString nom,QString prenom,long n_cin,QString chambre,int jours)
{
  this->id=id;
  this->nom=nom;
  this->prenom=prenom;
  this->n_cin=n_cin;
  this->chambre=chambre;
  this->jours=jours;
}
QString Client::get_nom(){return  nom;}
QString Client::get_prenom(){return prenom;}
int Client::get_id(){return  id;}
int Client::get_cin(){return  n_cin;}
QString Client::get_ch(){return  chambre;}
int Client::get_j(){return  jours;}

bool Client::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO etudiant (ID, NOM, PRENOM,n_cin,CHAMBRE,JOURS) "
                    "VALUES (:id, :nom, :prenom, :n_cin, :chambre, :jours)");
query.bindValue(":id", res);
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);
query.bindValue(":n_cin", n_cin);
query.bindValue(":chambre", chambre);
query.bindValue(":jours", jours);



return    query.exec();
}

QSqlQueryModel * Client::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from etudiant");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("n_cin"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("chambre"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("jours"));
    return model;
}

bool Client::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from etudiant where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}
QSqlQueryModel * Client::recherche(QString nom)
{

    QSqlQueryModel *model=new QSqlQueryModel;
    QSqlQuery query;
    query.prepare("select * from etudiant where nom = :nom");
    query.bindValue(":nom",nom);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("n_cin"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("chambre"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("jours"));
    return model;
}

