#ifndef MENU_H
#define MENU_H
#include <QString>

#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTableView>
#include <QWidget>

class Menu
{
public:
    Menu();
    Menu(int,QString,QString,QString);
    int get_id();
    QString get_entree();
    QString get_suite();
    QString get_dessert();

    bool ajouter();

     bool supprimer(int);
     bool modifier();
        QSqlQueryModel * afficher_tri();
     QSqlQueryModel * afficher();
      QSqlQueryModel * recherche_nom(QString);

private :
 int id;
 QString entree,suite,dessert;
};

#endif // MENU_H
