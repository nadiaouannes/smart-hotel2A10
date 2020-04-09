#ifndef RESERVATION_H
#define RESERVATION_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class reservation
{
public:
    reservation();
    reservation(int,QString,QString,int);
    QString get_nom();
    int get_id();
    bool ajouter();
    int get_j();
    QString get_type();
    QSqlQueryModel * afficher();
    bool supprimer(int);
private:
    QString nom,type;
    int id,jours;
};

#endif // RESERVATION_H
