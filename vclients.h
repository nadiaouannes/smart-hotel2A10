#ifndef VCLIENTS_H
#define VCLIENTS_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>



class vclients
{
public:
    vclients();
    vclients(QString,QString,QString,QString);
    QString get_matricule();
     QString get_couleur();
    QString get_marque();
    QString get_type();
    void Refresh();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(QString);


private:
    QString matricule,marque,couleur,type;
};

#endif // VCLIENTS_H
