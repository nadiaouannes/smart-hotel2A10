#include "connexion.h"

Connexion::Connexion()
{

}

bool Connexion::ouvrirConnexion()
{
    bool test=false;
    db=QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("test-db");
    db.setUserName("nadia");//inserer nom de l'utilisateur
    db.setPassword("nadia");//inserer mot de passe de cet utilisateur


    if (db.open()) test = true;


    return test;

}
void Connexion::fermerConnexion()
{
    db.close();
}
