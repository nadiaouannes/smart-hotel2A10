#include "stocke.h"
#include <QDebug>
#include "connexion.h"

Stocke::Stocke()
{
    ids=0;
    produit="";
    prix=0;
    quantite=0;
}
Stocke::Stocke(int ids,QString produit,int prix,int quantite)
{
    this->ids=ids;
    this->produit=produit;
    this->prix=prix;
    this->quantite=quantite;

}

int Stocke::get_ids()
{
    return ids;
}

QString Stocke::get_produit()
{
    return produit;
}

int Stocke::get_prix()
{
    return prix;
}
int Stocke::get_quantite()
{
    return quantite;
}



bool Stocke::ajouter()
{

    QSqlQuery query;
    QString res= QString::number(ids);
    query.prepare("INSERT INTO STOCKE (IDS, PRODUIT, prix, quantite) VALUES (:ids, :produit, :prix, :quantite);");
    query.bindValue(":ids", res);
    query.bindValue(":produit", produit);
     query.bindValue(":prix", prix);
      query.bindValue(":quantite", quantite);




    return    query.exec();
}






QSqlQueryModel * Stocke::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from STOCKE");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ids"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("produit"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prix"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("quantite"));


    return model;
}







bool Stocke::supprimer(int ids)
{
    QSqlQuery query;
    QString res= QString::number(ids);
    query.prepare("Delete from stocke where ids = :ids;");
    query.bindValue(":ids", res);
    return    query.exec();
}






bool Stocke::modifier()
{   QSqlQuery query;
    QString res=QString::number(ids);
    query.prepare( "UPDATE STOCKE SET IDS=:ids, PRODUIT=:produit, PRIX=:prix, QUANTITE=:quantite WHERE IDS=:ids");
    query.bindValue(":ids",res);
    query.bindValue(":produit",produit);
    query.bindValue(":prix",prix);
    query.bindValue(":quantite",quantite);




 return query.exec();
}



QSqlQueryModel * Stocke::tri()
 {QSqlQueryModel * model= new QSqlQueryModel();

 model->setQuery("select * from STOCKE order by ids");
 model->setHeaderData(0, Qt::Horizontal, QObject::tr("ids"));
 model->setHeaderData(1, Qt::Horizontal, QObject::tr("produit"));
 model->setHeaderData(2, Qt::Horizontal, QObject::tr("prix"));
 model->setHeaderData(3, Qt::Horizontal, QObject::tr("quantite"));




     return model;
 }


QSqlQueryModel *Stocke::cherch_produit(QString p)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select *  from STOCKE where PRODUIT='"+p+"'");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ids"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("produit"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prix"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("quantite"));



    return model;
}

