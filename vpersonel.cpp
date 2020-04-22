#include "vpersonel.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
vpersonel::vpersonel()
{

}
vpersonel::vpersonel(QString a,QString b,QString c)
{
    id=a;
    nom=b;
    prenom=c;
}
void vpersonel::setid(QString a)
{id=a;}
void vpersonel::setnom(QString b)
{nom=b;}
void vpersonel::setprenom(QString c)
{prenom=c;}
QString vpersonel::getid()
{return id;}
QString vpersonel::getnom()
{return nom;}
QString vpersonel::getprenom()
{return prenom;}
bool vpersonel::ajouter()
{
    QSqlQuery query;
    QString type;
    query.prepare("INSERT INTO  ABONNE(ID,NOM,PRENOM) VALUES (:id,:nom,:prenom)");
    query.bindValue(":id",id);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    return query.exec();
}

bool vpersonel::supprimer()
{
QSqlQuery query;
    query.prepare("Delete from ABONNE where ID= :id");
    query.bindValue(":id",id);
return    query.exec();
}



