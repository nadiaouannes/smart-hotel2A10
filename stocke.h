#ifndef STOCKE_H
#define STOCKE_H
#include <QSqlQueryModel>
#include <QTableView>
#include <QWidget>
#include <QString>
#include <QSqlQuery>



class Stocke
{
public:
    Stocke();
    Stocke(int , QString , int , int);
    int get_ids();
    QString get_produit();
    int get_prix();
    int get_quantite();


    bool ajouter();
     QSqlQueryModel * afficher();
     bool supprimer(int);
     bool modifier();
     QSqlQueryModel * tri();
     QSqlQueryModel * recherche_p(QString);

private :
 int ids,prix,quantite;
 QString produit;


};

#endif // STOCKE_H
