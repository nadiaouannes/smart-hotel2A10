#ifndef ETUDIANT_H
#define ETUDIANT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class Client
{public:
    Client();
    Client(int,QString,QString,long,QString,int);
    QString get_nom();
    QString get_prenom();
    int get_id();
    bool ajouter();
    int get_cin();
    QString get_ch();
    int get_j();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    QSqlQueryModel * recherche(QString);
private:
    QString nom,prenom,chambre;
    int id,n_cin,jours;
};

#endif
