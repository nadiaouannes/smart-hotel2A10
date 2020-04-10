#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("mohsen");
db.setUserName("mohsen");//inserer nom de l'utilisateur
db.setPassword("mohsen");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
