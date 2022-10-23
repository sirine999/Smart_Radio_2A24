#ifndef INVITE_H
#define INVITE_H
#include <QString>
#include<QSqlQuery>
#include<QSqlQueryModel>


class invite
{
 int age,idinv;
 QString nom,prenom,mail;
public:
 QString date_achat;
 invite(){}
 invite(QString,int,QString,QString,int);
 QString get(){return nom;}
 int getAge(){return age;}
 QString getPrenom(){return prenom;}
 QString getMail(){return mail;}
 int getIdinv(){return idinv;}

 void setNom(QString id){this->nom=id;}
 void setAge(int nb){this->age=nb;}
 void setPrenom(QString nm){prenom=nm;}
 void setMail(QString de){mail=de;}
 void setIDinv(int id){this->idinv=id;}
 bool ajouter();


 QSqlQueryModel * afficher(QString, int);
 bool supprimer(int);
 bool modify(int);

 QSqlQueryModel * TRI(int index);

};

#endif // INVITE_H
