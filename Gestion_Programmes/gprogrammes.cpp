#include "gprogrammes.h"
#include<QDebug>
#include<QObject>
#include <QString>
#include <QMessageBox>

GProgrammes::GProgrammes()
{
    ID=0;
    nomProg="";
    typeProg="";
    Duree=0;
    Date_Prog="";
    nomPresentateur="";
    Nbreinvites=0;
}


GProgrammes::GProgrammes(int ID,QString nomProg,QString typeProg,int Duree,QString Date_Prog,QString nomPresentateur,int Nbreinvites)
{
this->ID=ID;
this->nomProg=nomProg;
this->typeProg=typeProg;
this->Duree=Duree;
this->Date_Prog=Date_Prog;
this->nomPresentateur=nomPresentateur;
this->Nbreinvites=Nbreinvites;
}


bool GProgrammes::ajouter()
{
    QSqlQuery query;
    QString ID_string= QString::number(ID);
    QString Duree_string= QString::number(Duree);
    QString Nbreinvites_string= QString::number(Nbreinvites);
    if(query.exec("select * from GProgrammes where ID='"+ID_string+"'"))
    { int count=0;
        while(query.next())
            count++;
        if (count==0)
       {


//prepare() prend la requète en paramètre pour la préparer à l'éxécution.

    query.prepare("INSERT INTO GProgrammes (ID, nomProg, typeProg, Duree, Date_Prog, nomPresentateur, Nbreinvites)" "VALUES(:ID, :nomProg, :typeProg, :Duree, :Date_Prog, :nomPresentateur, :Nbreinvites)");

// Création des variables liées
    query.bindValue(":ID",ID_string);
    query.bindValue(":nomProg",nomProg);
    query.bindValue(":typeProg",typeProg);
    query.bindValue(":Duree",Duree_string);
    query.bindValue(":Date_Prog",Date_Prog);
    query.bindValue(":nomPresentateur",nomPresentateur);
    query.bindValue(":Nbreinvites",Nbreinvites_string);
    } else
            QMessageBox::critical(nullptr, QObject::tr(" not OK"),
                                           QObject::tr("l'identifiant existe deja .\n"
                                                       "click cancel to exit."),QMessageBox::Cancel);}

    return query.exec(); //exec() envoie la requète pour l'exécuter

}

QSqlQueryModel * GProgrammes::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from GProgrammes");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nomProg"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("typeProg"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Duree"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Date_Prog"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("nomPresentateur"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("Nbreinvites"));
    return model;
}

bool GProgrammes::supprimer(int ID)
{
    QSqlQuery query;
    QString res=QString::number(ID);
    query.prepare("Delete from GProgrammes where ID= :ID");
    query.bindValue(":ID",res);
    return query.exec();
}

bool GProgrammes::modifier(int ID,QString nomProg,QString typeProg,int Duree,QString Date_Prog,QString nomPresentateur,int Nbreinvites)
{
    QSqlQuery query;
    QString ID_string=QString::number(ID);
    QString Nbreinvites_string=QString::number(Nbreinvites);
    QString Duree_string=QString::number(Duree);

          query.prepare("update GProgrammes set nomProg=:nomProg,typeProg=:typeProg,Duree=:Duree,Date_Prog=:Date_Prog,nomPresentateur=:nomPresentateur,Nbreinvites=:Nbreinvites where ID=:ID");
          query.bindValue(":ID", ID_string);
          query.bindValue(":nomProg", nomProg);
          query.bindValue(":typeProg", typeProg);
          query.bindValue(":Duree", Duree_string);
          query.bindValue(":Date_Prog", Date_Prog);
          query.bindValue(":nomPresentateur", nomPresentateur);
          query.bindValue(":Nbreinvites", Nbreinvites_string);
          return query.exec();
}

QSqlQueryModel * GProgrammes::trier_NOM()
{
    QSqlQueryModel * model= new QSqlQueryModel();

          model->setQuery("SELECT * FROM GProgrammes ORDER BY nomProg ");
          model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
          model->setHeaderData(1,Qt::Horizontal,QObject::tr("nomProg"));
          model->setHeaderData(2,Qt::Horizontal,QObject::tr("typeProg"));
          model->setHeaderData(3,Qt::Horizontal,QObject::tr("Duree"));
          model->setHeaderData(4,Qt::Horizontal,QObject::tr("Date_Prog"));
          model->setHeaderData(5,Qt::Horizontal,QObject::tr("nomPresentateur"));
          model->setHeaderData(6,Qt::Horizontal,QObject::tr("Nbreinvites"));


    return model;
}

QSqlQueryModel * GProgrammes::trier_INVITES()
{
    QSqlQueryModel * model= new QSqlQueryModel();

          model->setQuery("SELECT * FROM GProgrammes ORDER BY Nbreinvites ");
          model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
          model->setHeaderData(1,Qt::Horizontal,QObject::tr("nomProg"));
          model->setHeaderData(2,Qt::Horizontal,QObject::tr("typeProg"));
          model->setHeaderData(3,Qt::Horizontal,QObject::tr("Duree"));
          model->setHeaderData(4,Qt::Horizontal,QObject::tr("Date_Prog"));
          model->setHeaderData(5,Qt::Horizontal,QObject::tr("nomPresentateur"));
          model->setHeaderData(6,Qt::Horizontal,QObject::tr("Nbreinvites"));


    return model;
}

QSqlQueryModel * GProgrammes::trier_ID()
{
    QSqlQueryModel * model= new QSqlQueryModel();

          model->setQuery("SELECT * FROM GProgrammes ORDER BY ID ");
          model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
          model->setHeaderData(1,Qt::Horizontal,QObject::tr("nomProg"));
          model->setHeaderData(2,Qt::Horizontal,QObject::tr("typeProg"));
          model->setHeaderData(3,Qt::Horizontal,QObject::tr("Duree"));
          model->setHeaderData(4,Qt::Horizontal,QObject::tr("Date_Prog"));
          model->setHeaderData(5,Qt::Horizontal,QObject::tr("nomPresentateur"));
          model->setHeaderData(6,Qt::Horizontal,QObject::tr("Nbreinvites"));


    return model;
}

QSqlQueryModel* GProgrammes::recherchernom(QString nomProg)
    {

    QSqlQueryModel * model= new QSqlQueryModel();

            model->setQuery("select * from GProgrammes where nomProg ='"+nomProg+"' ");
            model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("nomProg"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("typeProg"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("Duree"));
            model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date_Prog"));
            model->setHeaderData(5, Qt::Horizontal, QObject::tr("nomPresentateur"));
            model->setHeaderData(6, Qt::Horizontal, QObject::tr("Nbreinvites"));

            return model;
    }
QSqlQueryModel* GProgrammes::rechercherid(QString IID)
    {

    QSqlQueryModel * model= new QSqlQueryModel();

            model->setQuery("select * from GProgrammes where ID ='"+IID+"' ");
            model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("nomProg"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("typeProg"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("Duree"));
            model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date_Prog"));
            model->setHeaderData(5, Qt::Horizontal, QObject::tr("nomPresentateur"));
            model->setHeaderData(6, Qt::Horizontal, QObject::tr("Nbreinvites"));

            return model;
    }

QSqlQueryModel* GProgrammes::recherchernomPresentateur(QString nomPresentateur)
    {

    QSqlQueryModel * model= new QSqlQueryModel();

            model->setQuery("select * from GProgrammes where nomPresentateur ='"+nomPresentateur+"' ");
            model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("nomProg"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("typeProg"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("Duree"));
            model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date_Prog"));
            model->setHeaderData(5, Qt::Horizontal, QObject::tr("nomPresentateur"));
            model->setHeaderData(6, Qt::Horizontal, QObject::tr("Nbreinvites"));

            return model;
    }


int GProgrammes::statistique(QString typeProg)
{
    QSqlQuery query;
    query.prepare("select count(*) from GProgrammes where typeProg=:typeProg ");
    query.bindValue(":typeProg",typeProg);
    query.exec();

    int count =-1;

            while(query.next())
                    {
                        count = query.value(0).toInt() ;
                        return count;

                    }

    return count;

}

