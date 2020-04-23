#include "equipement.h"
#include <QDebug>
#include "connexion.h"

Equipement::Equipement()
{
    ide=0;
    nom="";
    type="";
    nomf="";
    nombre=0;
}

Equipement::Equipement(int ide, QString nom, QString type, QString nomf, int nombre)
{
    this->ide=ide;
    this->nom=nom;
    this->type=type;
    this->nomf=nomf;
    this->nombre=nombre;
}

int Equipement::get_ide()
{
    return ide;
}

QString Equipement::get_nom()
{
    return nom;
}

QString Equipement::get_type()
{
    return type;
}

QString Equipement::get_nomf()
{
    return nomf;
}

int Equipement::get_nombre()
{
    return nombre;
}

bool Equipement::ajouter()
{

    QSqlQuery query;
    QString res= QString::number(ide);
    query.prepare("INSERT INTO EQUIPEMENT (IDE, NOM, TYPE, NOMF, NOMBRE) VALUES (:ide, :nom, :type, :nomf, :nombre);");
    query.bindValue(":ide", res);
    query.bindValue(":nom", nom);
    query.bindValue(":type", type);
    query.bindValue(":nomf",nomf);
    query.bindValue(":nombre",nombre);

    return    query.exec();
}

QSqlQueryModel * Equipement::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM EQUIPEMENT;");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ide"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("nomf"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("nombre"));
    return model;
}

bool Equipement::supprimer(int ide)
{
    QSqlQuery query;
    QString res= QString::number(ide);
    query.prepare("DELETE FROM EQUIPEMENT WHERE IDE = :ide;");
    query.bindValue(":ide", res);
    return    query.exec();
}

bool Equipement:: modifier()
{
    QSqlQuery query;
    QString res=QString::number(ide);

          query.prepare( "UPDATE EQUIPEMENT SET IDE=:ide, NOM=:nom,TYPE=:type,NOMF=:nomf,NOMBRE=:nombre WHERE IDE=:ide");

         query.bindValue(":ide",res);
         query.bindValue(":nom",nom);
         query.bindValue(":type",type);
         query.bindValue(":nomf",nomf);
         query.bindValue(":nombre",nombre);

         return query.exec();


}

QSqlQueryModel * Equipement:: recherche(QString e )
{

    QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("SELECT * FROM EQUIPEMENT WHERE NOM ='"+e+"' ;");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ide"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("type"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("nomf"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("nombre"));

    return model ;
}

QSqlQueryModel * Equipement::trier()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT * FROM EQUIPEMENT ORDER BY IDE ;");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("nomf"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("nombre"));

    return model;
}


