#ifndef VCLIENTS_H
#define VCLIENTS_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>



class vclients
{
public:
    vclients();
    vclients(QString,QString,QString);
    QString get_matricule();
     QString get_couleur();
    QString get_marque();
    void Refresh();
    bool ajouter(int);
    QSqlQueryModel *afficher();
    bool supprimer(QString);

private:
    QString matricule,marque,couleur;
};

#endif // VCLIENTS_H
