#ifndef EQUIPEMENT_H
#define EQUIPEMENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTableView>
#include <QWidget>

class Equipement
{public:
    Equipement();
    Equipement(int , QString , QString , QString , int );
    int get_ide();
    QString get_nom();
    QString get_type();
    QString get_nomf();
    int get_nombre();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int );
    bool modifier( );
    QSqlQueryModel * recherche(QString );
    QSqlQueryModel * trier();
    QSqlQueryModel statistic();
private:
    QString nom,type,nomf;
    int nombre,ide;
};

#endif // EQUIPEMENT_H
