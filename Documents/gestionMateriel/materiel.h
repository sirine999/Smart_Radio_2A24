#ifndef MATERIEL_H
#define MATERIEL_H
#include <QString>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include<QSqlQueryModel>
#include<QPrinter>
#include<QPainter>
#include<QtCharts>
#include<QChartView>
class Materiel
{
public:
    Materiel();
    Materiel(int,QString,QString,QString,QString,double);
    Materiel(int,QString);
   int getid();
    QString getnom();
    QString getmarque();
    QString getdepartement();
    QString getheu_date();
    double getprix();
    QString getimage();
    void setid(int);
    void setnom(QString);
    void setmarque(QString);
    void setdepartement(QString);
    void setheu_date(QString);
    void setprix(double);
    void setimage(QString);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int id);
    bool modifier(int id,QString nom,QString marque,QString departement,QString heu_date,double prix);




    QSqlQueryModel * trie_ID();
    QSqlQueryModel * trie_NOM();
    QSqlQueryModel * trie_PRIX();
    QSqlQueryModel* rechercherid(QString);
    QSqlQueryModel* recherchernom(QString);
    QSqlQueryModel* recherchermarque(QString);
    QSqlQueryModel* rechercherdepartement(QString);
    int statistique(QString);
    bool ajouterimage(int,QString);


private:
   int id;
    QString nom,marque,departement,heu_date,image;
    double prix;
};

#endif // MATERIEL_H
