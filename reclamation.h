#ifndef RECLAMATION_H
#define RECLAMATION_H
#include <QString>
#include<QSqlQuery>
#include<QSqlQueryModel>



class RECLAMATION
{
private:
    int id;
    QString contenu,etat;


public:
    RECLAMATION();
    RECLAMATION(int,QString,QString);
           int get_id();
           QString get_contenu();
           QString get_etat();
           bool ajouter();
           bool modifier(int,QString,QString);
           bool supprimer(int);
           QSqlQueryModel * afficher();
           QSqlQueryModel * recherche(int);

           QSqlQueryModel * tri_employee();
};

#endif // RECLAMATION_H
