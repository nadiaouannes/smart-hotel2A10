#include "menu.h"
#include <QDebug>
#include "connexion.h"

Menu::Menu()
{
    id=0;
    entree="";
   suite="";
   dessert="";
}

Menu::Menu(int id,QString entree,QString suite,QString dessert)
{
    this->id=id;
    this->entree=entree;
    this->suite=suite;
    this->dessert=dessert;
}

int Menu::get_id()
{
    return id;
}

QString Menu::get_entree()
{
    return entree;
}

QString Menu::get_suite()
{
    return suite;
}
QString Menu::get_dessert()
{
    return dessert;
}





bool Menu::ajouter()
{

    QSqlQuery query;
    QString res= QString::number(id);
    query.prepare("INSERT INTO MENU (ID, ENTREE,SUITE,DESSERT) VALUES (:id, :entree, :suite, :dessert);");
    query.bindValue(":id", res);
    query.bindValue(":entree", entree);
    query.bindValue(":suite", suite);
    query.bindValue(":dessert", dessert);


    return    query.exec();
}








QSqlQueryModel * Menu::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from MENU");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("entree"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("suite"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("dessert"));

    return model;
}





bool Menu::supprimer(int id)
{
    QSqlQuery query;
    QString res= QString::number(id);
    query.prepare("Delete from menu where id = :id;");
    query.bindValue(":id", res);
    return    query.exec();
}




bool Menu::modifier()
{   QSqlQuery query;
    QString res=QString::number(id);
    query.prepare( "UPDATE MENU SET ID=:id, ENTREE=:entree,SUITE=:suite,DESSERT=:dessert WHERE ID=:id");
    query.bindValue(":id",res);
    query.bindValue(":entree",entree);
    query.bindValue(":suite",suite);
    query.bindValue(":dessert",dessert);


 return query.exec();
}





QSqlQueryModel * Menu::afficher_tri()
 {QSqlQueryModel * model= new QSqlQueryModel();

 model->setQuery("select * from MENU order by id");
 model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
 model->setHeaderData(1, Qt::Horizontal, QObject::tr("entree"));
 model->setHeaderData(2, Qt::Horizontal, QObject::tr("suite"));
  model->setHeaderData(3, Qt::Horizontal, QObject::tr("dessert"));



     return model;
 }




QSqlQueryModel *Menu::recherche_nom(QString e)
 {
     QSqlQueryModel * model= new QSqlQueryModel();
     model->setQuery("select * from MENU where ENTREE='"+e+"'");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("entree"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("suite"));
      model->setHeaderData(3, Qt::Horizontal, QObject::tr("dessert"));




     return model;
 }



