#ifndef MATERIEL_H
#define MATERIEL_H
#include <QString>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include<QSqlQueryModel>
class Materiel
{
public:
    Materiel();
    Materiel(int,QString,QString,QString,QString,double);
   int getid();
    QString getnom();
    QString getmarque();
    QString getdepartement();
    QString getheu_date();
    double getprix();
    void setid(int);
    void setnom(QString);
    void setmarque(QString);
    void setdepartement(QString);
    void setheu_date(QString);
    void setprix(double);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int id);
    bool modifier(int id,QString nom,QString marque,QString departement,QString heu_date,double prix);
   // bool selection();




    QSqlQueryModel * trie_NOM();
    QSqlQueryModel * trie_PRIX();
    QSqlQueryModel* recherchernom(QString);

private:
   int id;
    QString nom,marque,departement,heu_date;
    double prix;
};

#endif // MATERIEL_H
