#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <QString>
#include <QSqlQueryModel>
#include <QObject>
#include <QDebug>
#include <QSqlQuery>

class Employee
{
public:
    Employee();
    Employee(int,QString,QString,QString,QString,QString,int);
   //getters
    int getId(){return id ;}
    QString getNom(){return nom;}
    QString getPrenom(){return prenom;}
    QString getAdresse(){return adresse;}
    QString getMail(){return mail;}
    QString getGenre(){return genre;}
    int getSalaire(){return salaire;}

    //setters
    void setId(int id){this->id=id;}
    void setNom(QString nom){this->nom=nom;}
    void setPrenom(QString prenom){this->prenom=prenom;}
    void setAdresse(QString adresse){this->adresse=adresse;}
    void setMail(QString mail){this->mail=mail;}
    void setGenre(QString genre){this->genre=genre;}
    void setSalaire(int salaire){this->salaire=salaire;}



    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier();
    QSqlQueryModel * getAllId();
    Employee* reademploye (QString val);
    QSqlQueryModel * afficher_choix(QString choix);
    QSqlQueryModel *afficher_id(QString ch);
    QSqlQueryModel *afficher_nom(QString ch);
    QSqlQueryModel *afficher_salaire(QString ch);

    int statistique1();
    int statistique2();

private:
    int id;
    QString nom,prenom,adresse,mail,genre;
    int salaire;
};

#endif // EMPLOYEE_H
