#ifndef PUB_H
#define PUB_H
#include <qstring.h>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QSqlDatabase>

#include <QtCharts>
#include <QChartView>
#include <QPieSeries>
class Pub
{
public:
    Pub();
    Pub(int,QString,QString,QString,int,QString,QString,QString,QString,QString,QString,QString,QString,int);
    int getid();
    QString getnomE();
    QString getnomP();
    QString gettype();
    int getpass();
    QString gethorraire();
    QString gethorraire1();
    QString gethorraire2();
    QString gethorraire3();
    QString gethorraire4();
    QString gethorraire5();
    QString getduree();
    QString getduree1();

    int getprix();


    void setid(int);
    void setnomE(QString);
    void setnomP(QString);
    void settype(QString);
    void setpass(int);
    void sethorraire(QString);
    void sethorraire1(QString);
    void sethorraire2(QString);
    void sethorraire3(QString);
    void sethorraire4(QString);
    void sethorraire5(QString);
    void setduree(QString);
    void setduree1(QString);
    void setprix(int);

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier();
    void stat(QPieSeries*,QFrame*);
    QSqlQueryModel* tri_id();
    QSqlQueryModel* rechercher(const QString &aux);

private:
    int id_pub,passage;
    QString nom_entreprise,nom_produit,type_produit,horraire,horraire1,horraire2,horraire3,horraire4,horraire5,duree,duree1;
    int prix;

};

#endif // PUB_H
