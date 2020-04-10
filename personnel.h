#ifndef PERSONNEL_H
#define PERSONNEL_H
#include <QString>
#include<QSqlQuery>
#include<QSqlQueryModel>


class PERSONNEL
{
public:
    PERSONNEL();
    PERSONNEL(int,QString,QString,QString,QString);
    int get_id();
    QString get_nom();
    QString get_prenom();
    QString get_date();
    QString get_poste();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int,QString,QString,QString,QString);
    QSqlQueryModel * recherche(int);
    QSqlQueryModel * tri_employee();

private:
    int id;
    QString nom,prenom,poste,dateinscri;




};

#endif // PERSONNEL_H
