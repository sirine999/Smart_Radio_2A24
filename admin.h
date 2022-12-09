#ifndef ADMIN_H
#define ADMIN_H
#include<QString>
#include<QSqlQueryModel>
#include <QThread>

class Admin
{
public:
    Admin();
    Admin(QString,QString,QString);
    bool Login();


private:
    int id;
    QString login,password,role;
};

#endif // ADMIN_H
