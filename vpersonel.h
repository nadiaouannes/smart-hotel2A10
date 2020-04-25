#ifndef VPERSONEL_H
#define VPERSONEL_H

#include <QMainWindow>
#include <QWidget>
#include<QSqlQueryModel>

class vpersonel
{
private:
    QString id,matricule,marque;

public:
    vpersonel();
    vpersonel(QString,QString,QString);
    QString getmatricule();
    QString getmarque();
    QString getid();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(QString);
};

#endif // VPERSONEL_H







