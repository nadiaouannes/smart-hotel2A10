#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Fournisseur
{
public:

    Fournisseur();
    Fournisseur(int , QString , QString , int , QString );
    int get_idf();
    QString get_nom();
    QString get_categorie();
    int get_numero();
    QString get_mail();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int );
    bool modifier();
    QSqlQueryModel * recherche(QString );
    QSqlQueryModel * trier( );

private:
    QString nom,categorie,mail;
    int idf,numero;
};

#endif // FOURNISSEUR_H
