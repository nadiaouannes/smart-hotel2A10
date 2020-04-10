#include "personnel.h"


PERSONNEL::PERSONNEL()
{ id=0;
  nom="";
  dateinscri="";
  prenom="";
  poste="";
}

PERSONNEL::PERSONNEL(int id,QString nom,QString prenom,QString dateinscri,QString poste )
{
 this->id=id;
 this->nom=nom;
 this->prenom=prenom;
 this->dateinscri=dateinscri;
 this->poste=poste;
}

int PERSONNEL::get_id(){return id;}
QString PERSONNEL::get_nom(){return nom;}
QString PERSONNEL::get_prenom(){return prenom;}
QString PERSONNEL::get_date(){return dateinscri;}
QString PERSONNEL::get_poste(){return poste;}

bool PERSONNEL::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO PERSONEL (ID, NOM, PRENOM , DATEINSCRI , POSTE ) "
                    "VALUES (:id, :nom, :prenom, :dateinscri, :poste)");
query.bindValue(":id", res);
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);
query.bindValue(":dateinscri", dateinscri);
query.bindValue(":poste", poste);

return    query.exec();
}

QSqlQueryModel * PERSONNEL::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from PERSONEL");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("date_inscri"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("poste"));
return model;
}

bool PERSONNEL::supprimer(int id)
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("Delete from PERSONEL where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}

bool PERSONNEL::modifier(int id, QString nom, QString prenom, QString dateinscri,QString poste)
{
    QSqlQuery query;
    QString res= QString::number(id);
    query.prepare("UPDATE PERSONEL set NOM = :nom, PRENOM = :prenom, DATEINSCRI = :dateinscri, POSTE = :poste  WHere ID = :id");
    query.bindValue(":id",res);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":dateinscri",dateinscri);
    query.bindValue(":poste",poste);

    return query.exec();
}


QSqlQueryModel *PERSONNEL::recherche(int id)
{

    QSqlQueryModel *model=new QSqlQueryModel;
    QSqlQuery query;
    query.prepare("select * from PERSONEL where ID = :id");
    query.bindValue(":id",id);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_inscri"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("poste"));
    return model;


}


QSqlQueryModel * PERSONNEL::tri_employee()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from PERSONEL order by ID");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_inscri"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("poste"));


        return model;
}
















