#ifndef GPROGRAMMES_H
#define GPROGRAMMES_H
#include <QString>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>

class GProgrammes
{
public:
//Constructeurs
    GProgrammes();
    GProgrammes(int,QString,QString,int,QString,QString,int);

//Getters
    int getID(){return ID;}
    QString getnomProg(){return nomProg;}
    QString gettypeProg(){return typeProg;}
    int getDuree(){return Duree;}
    QString getDate(){return Date_Prog;}
    QString getnomPresentateur(){return nomPresentateur;}
    int getNbreinvites(){return Nbreinvites;}

//Setters
    void setID(int ID){this->ID=ID;}
    void setnomProg(QString n){nomProg=n;}
    void settypeProg(QString t){typeProg=t;}
    void setDuree(int Duree){this->Duree=Duree;}
    void setDate(QString d){Date_Prog=d;}
    void setNomPresentateur(QString p){nomPresentateur=p;}
    void setNbreinvites(int Nbreinvites){this->Nbreinvites=Nbreinvites;}

//fonctionnalités de Base
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int,QString,QString,int,QString,QString,int);
    QSqlQueryModel * trier_NOM();
    QSqlQueryModel * trier_INVITES();
    QSqlQueryModel * trier_ID();

    QSqlQueryModel * recherchernom(QString);
    QSqlQueryModel * rechercherid(QString);
    QSqlQueryModel * recherchernomPresentateur(QString);
    int statistique(QString typeProg);


private:
    QString nomProg,typeProg,Date_Prog,nomPresentateur;
    int ID,Nbreinvites,Duree;




};

#endif // GPROGRAMMES_H
