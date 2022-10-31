#include "connection.h"
#include <QDebug>
Connection::Connection()
{
}

bool Connection::createconnection(){
    //config bd
    db = QSqlDatabase::addDatabase("QODBC");
    bool test=false;
    db.setDatabaseName("test");
    db.setUserName("system");
    db.setPassword("mohamed2001");
    if(db.open()){
        test=true;
    }

    return test;


}

void Connection::closeconnection(){
    db.close();
}
