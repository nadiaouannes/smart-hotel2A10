#include "reclamation.h"

RECLAMATION::RECLAMATION()
{
      id=0;
      contenu="";
      etat="";
}

RECLAMATION::RECLAMATION(int id,QString contenu,QString etat)
{
    this->id=id;
    this->contenu=contenu;
    this->etat=etat;
}

int RECLAMATION::get_id(){return id;}
QString RECLAMATION::get_contenu(){return contenu;}
QString RECLAMATION::get_etat(){return etat;}

bool RECLAMATION::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO RECLAMATION (ID, CONTENU, ETAT) "
                    "VALUES (:id, :contenu, :etat)");
query.bindValue(":id", res);
query.bindValue(":contenu", contenu);
query.bindValue(":etat", etat);


return    query.exec();
}

QSqlQueryModel * RECLAMATION::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from RECLAMATION");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("contenu "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("etat"));
return model;
}



bool RECLAMATION::modifier(int id,QString contenu,QString etat)
{
    QSqlQuery query;
    QString res= QString::number(id);
    query.prepare("UPDATE RECLAMATION set CONTENU = :contenu, ETAT = :etat  WHere ID = :id");
    query.bindValue(":id",res);
    query.bindValue(":contenu", contenu);
    query.bindValue(":etat", etat);


    return query.exec();
}


bool RECLAMATION::supprimer(int id)
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("Delete from RECLAMATION where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}

QSqlQueryModel *RECLAMATION::recherche(int id)
{

    QSqlQueryModel *model=new QSqlQueryModel;
    QSqlQuery query;
    query.prepare("select * from RECLAMATION where ID = :id");
    query.bindValue(":id",id);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("contenu "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("etat"));
    return model;


}


QSqlQueryModel * RECLAMATION::tri_employee()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from RECLAMATION order by ID");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("contenu "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("etat"));



        return model;
}





