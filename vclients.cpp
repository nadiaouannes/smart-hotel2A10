#include "vclients.h"
#include <QDebug>

vclients::vclients()
{
marque="";
couleur="";
matricule="";
type="";
}

vclients::vclients(QString couleur,QString marque,QString matricule,QString type)
{
    this->couleur=couleur;
    this->marque=marque;
    this->matricule=matricule;
    this->type=type;
}
QString vclients::get_couleur(){return couleur;}
QString vclients::get_matricule(){return matricule;}
QString vclients::get_marque(){return marque;}
QString vclients::get_type(){return type;}




bool vclients::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO  VEHICULE(MATRICULE,MARQUE,COULEUR,type) VALUES (:matricule,:marque,:couleur,:type)");
    query.bindValue(":couleur",couleur);
    query.bindValue(":marque",marque);
    query.bindValue(":matricule",matricule);
    query.bindValue(":type",type);

    return query.exec();

  }


bool vclients::supprimer(QString matricule)
{
QSqlQuery query;

    query.prepare("Delete from VEHICULE where matricule = :matricule");
    query.bindValue(":matricule",matricule);
return    query.exec();


}
 QSqlQueryModel * vclients::afficher()
 {
     QSqlQueryModel * model= new QSqlQueryModel();
 model->setQuery("select * from VEHICULE");
 model->setHeaderData(0, Qt::Horizontal, QObject::tr("MATRICULE"));
 model->setHeaderData(1, Qt::Horizontal, QObject::tr("MARQUE"));
 model->setHeaderData(2, Qt::Horizontal, QObject::tr("COULEUR"));
 model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));

     return model;
 }


