#include "admin.h"
#include<QSqlQuery>
#include<QtDebug>
#include<QDate>
#include<QObject>

Admin::Admin()
{
  id=0;
  login="";
  password="";
  role="";
}
Admin::Admin(QString login,QString password,QString role)
{

    this->login=login;
    this->password=password;
    this->role=role;
}
bool Admin::Login()
{
    QSqlQuery query;
       bool test=false;

           query.prepare("Select login,password,role FROM users where login=:login and password=:password");
            query.bindValue(":login",login);
             query.bindValue(":password",password);
             query.bindValue(":role",role);

             if(query.exec()&&query.next())
       {
                 test=true;

       }
       return test;
}
