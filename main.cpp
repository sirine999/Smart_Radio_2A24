#include "mainwindow.h"
#include "connection.h"
#include <QMessageBox>
#include <QApplication>
#include "login.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connection c;
    bool test=c.createconnection();
    MainWindow w;
    Login L;
    if(test)
    {

        QMessageBox::information(nullptr, QObject::tr("database is open"),
                                 QObject::tr("Connection successfully !"),
                                 QMessageBox::Cancel);
        L.show();
    }else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                                 QObject::tr("Connection failed !"),
                                 QMessageBox::Cancel);

    return a.exec();
}
