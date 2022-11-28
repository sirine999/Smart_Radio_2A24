#include "connection.h"
#include <QDebug>

Connection::Connection()
{

}

bool Connection::createconnection()
{
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
bool test=false;
db.setDatabaseName("test");
db.setUserName("Ghassen");//inserer nom de l'utilisateur
db.setPassword("0000");//inserer mot de passe de cet utilisateur

if (db.open())test=true;





    return  test;
}
void Connection::closeConnection(){db.close();}
