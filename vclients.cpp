#include "vclients.h"
#include <QDebug>

vclients::vclients()
{
marque="";
couleur="";
matricule="";
}

vclients::vclients(QString couleur,QString marque,QString matricule)
{
    this->couleur=couleur;
    this->marque=marque;
    this->matricule=matricule;
}
QString vclients::get_couleur(){return couleur;}
QString vclients::get_matricule(){return matricule;}
QString vclients::get_marque(){return marque;}


bool vclients::ajouter(int choixzone)
{
    QSqlQuery query;
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


