#include "fournisseur.h"
#include <QDebug>
#include "connexion.h"

Fournisseur::Fournisseur()
{
    idf=0;
    nom="";
    categorie="";
    numero=0;
    mail="";
}

Fournisseur::Fournisseur(int idf, QString nom, QString categorie, int numero, QString mail)
{
    this->idf=idf;
    this->nom=nom;
    this->categorie=categorie;
    this->numero=numero;
    this->mail=mail;
}
int Fournisseur::get_idf()
{
    return idf;
}

QString Fournisseur::get_nom()
{
    return nom;
}

QString Fournisseur::get_categorie()
{
    return categorie;
}

int Fournisseur::get_numero()
{
    return numero;
}

QString Fournisseur::get_mail()
{
    return mail;
}


bool Fournisseur::ajouter()
{

    QSqlQuery query;

    query.prepare("INSERT INTO FOURNISSEUR (IDF, NOM, CATEGORIE, NUMERO, MAIL) VALUES (:idf, :nom, :categorie, :numero, :mail);");
    query.bindValue(":idf", idf);
    query.bindValue(":nom", nom);
    query.bindValue(":categorie",categorie);
    query.bindValue(":numero",numero);
    query.bindValue(":mail",mail);

    return    query.exec();
}

QSqlQueryModel * Fournisseur::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM FOURNISSEUR;");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("idf"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("categorie"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("numero"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("mail"));
    return model;
}

bool Fournisseur::supprimer(int idf)
{
    QSqlQuery query;

    query.prepare("DELETE FROM FOURNISSEUR WHERE IDF = :idf;");
    query.bindValue(":idf", idf);
    return    query.exec();
}

bool Fournisseur:: modifier( )
{
    QSqlQuery query;


          query.prepare( "UPDATE FOURNISSEUR SET IDF=:idf, NOM=:nom,CATEGORIE=:categorie,NUMERO=:numero,MAIL=:mail WHERE IDF=:idf");

         query.bindValue(":idf",idf);
         query.bindValue(":nom",nom);
         query.bindValue(":categorie",categorie);
         query.bindValue(":numero",numero);
         query.bindValue(":mail",mail);

         return query.exec();
}

QSqlQueryModel * Fournisseur:: recherche(QString f )
{

    QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("SELECT * FROM FOURNISSEUR WHERE NOM ='"+f+"' ;");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("idf"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("categorie"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("numero"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("mail"));

    return model ;
}

QSqlQueryModel * Fournisseur::trier()
{
    QSqlQueryModel * model= new QSqlQueryModel();


    model->setQuery("SELECT * FROM FOURNISSEUR ORDER BY IDF ;");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDF"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("categorie"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("numero"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("mail"));

        return model;
}
