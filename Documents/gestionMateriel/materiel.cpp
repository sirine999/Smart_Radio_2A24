#include "materiel.h"
#include <QSqlQuery>
#include<QtDebug>
#include<QObject>
#include <QMessageBox>
Materiel::Materiel()
{
id=0;
nom="";
marque="";
departement="";
heu_date="";
prix=0;
}
Materiel::Materiel(int id,QString nom,QString marque,QString departement,QString heu_date,double prix)
{
    this->id=id; this->nom=nom; this->marque=marque; this->departement=departement; this->heu_date=heu_date; this->prix=prix;
}
int Materiel::getid(){return id;}
QString Materiel::getnom(){return nom;}
QString Materiel::getmarque(){return marque;}
QString Materiel::getdepartement(){return departement;}
QString Materiel::getheu_date(){return heu_date;}
double Materiel::getprix(){return prix;}
void Materiel::setid(int id){this->id=id;}
void Materiel::setnom(QString nom){this->nom=nom;}
void Materiel::setmarque(QString marque){this->marque=marque;}
void Materiel::setdepartement(QString departement){this->departement=departement;}
void Materiel::setheu_date(QString heu_date){this->heu_date=heu_date;}
void Materiel::setprix(double prix){this->prix=prix;}

bool Materiel::ajouter()
{
 QSqlQuery query;
 QString id_string=QString::number(id);
 QString prix_string=QString::number(prix);
 if(query.exec("select * from materiel where id='"+id_string+"'"))
 { int count=0;
     while(query.next())
         count++;
     if (count==0)
    {
       query.prepare("INSERT INTO materiel (id,nom,marque,departement,heu_date,prix) "
                     "VALUES (:id, :nom, :marque, :departement, :heu_date, :prix)");
       query.bindValue(":id", id_string);
       query.bindValue(":nom", nom);
       query.bindValue(":marque", marque);
       query.bindValue(":departement", departement);
       query.bindValue(":heu_date", heu_date);
       query.bindValue(":prix", prix_string);
     } else
         QMessageBox::critical(nullptr, QObject::tr(" not OK"),
                                        QObject::tr("l'identifiant existe deja .\n"
                                                    "click cancel to exit."),QMessageBox::Cancel);}
       return query.exec();



}

bool Materiel::supprimer(int id)
{
    QSqlQuery query;
    QString id_string=QString::number(id);
    if(query.exec("select * from materiel where id='"+id_string+"'"))
    { int count=0;
        while(query.next())
            count++;
        if (count!=0)
       {
          query.prepare(" Delete from materiel where id=:id");
          query.bindValue(0, id);

        }
        else  QMessageBox::critical(nullptr, QObject::tr(" not OK"),
                                    QObject::tr("l'identifiant n'existe pas .\n"
                                                "click cancel to exit."),QMessageBox::Cancel);
    }

    return query.exec();
}

QSqlQueryModel* Materiel::afficher()
{
 QSqlQueryModel* model=new QSqlQueryModel();

       model->setQuery("SELECT* FROM materiel");
       model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("Marque"));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("Departement"));
       model->setHeaderData(4, Qt::Horizontal, QObject::tr("Heure et date"));
       model->setHeaderData(5, Qt::Horizontal, QObject::tr("Prix"));


  return model;}


bool Materiel::modifier(int id,QString nom,QString marque,QString departement,QString heu_date,double prix)
{
    QSqlQuery query;
    QString id_string=QString::number(id);
    QString prix_string=QString::number(prix);
    if(query.exec("select * from materiel where id='"+id_string+"'"))
    { int count=0;
        while(query.next())
            count++;
        if (count!=0)
       {
          query.prepare("update materiel set nom=:nom,marque=:marque,departement=:departement,heu_date=:heu_date,prix=:prix where id=:id");
          query.bindValue(":id", id_string);
          query.bindValue(":nom", nom);
          query.bindValue(":marque", marque);
          query.bindValue(":departement", departement);
          query.bindValue(":heu_date", heu_date);
          query.bindValue(":prix", prix_string);}

          else
              QMessageBox::critical(nullptr, QObject::tr(" not OK"),
                                            QObject::tr("l'identifiant n'existe pas .\n"
                                                        "click cancel to exit."),QMessageBox::Cancel);
          }
  return query.exec();
}
QSqlQueryModel * Materiel::trie_NOM()
{
    QSqlQueryModel * model= new QSqlQueryModel();

          model->setQuery("SELECT * FROM materiel ORDER BY nom ");
          model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
          model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
          model->setHeaderData(2,Qt::Horizontal,QObject::tr("marque"));
          model->setHeaderData(3,Qt::Horizontal,QObject::tr("departement"));
          model->setHeaderData(4,Qt::Horizontal,QObject::tr("heu_date"));
          model->setHeaderData(5,Qt::Horizontal,QObject::tr("prix"));

    return model;
}
QSqlQueryModel * Materiel::trie_PRIX()
{
    QSqlQueryModel * model= new QSqlQueryModel();

          model->setQuery("SELECT * FROM materiel ORDER BY prix ");
          model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
          model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
          model->setHeaderData(2,Qt::Horizontal,QObject::tr("marque"));
          model->setHeaderData(3,Qt::Horizontal,QObject::tr("departement"));
          model->setHeaderData(4,Qt::Horizontal,QObject::tr("heu_date"));
          model->setHeaderData(5,Qt::Horizontal,QObject::tr("prix"));

    return model;
}
QSqlQueryModel* Materiel::recherchernom(QString nom)
    {

    QSqlQueryModel * model= new QSqlQueryModel();

            model->setQuery("select * from materiel where nom ='"+nom+"' ");
            model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("marque"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("departement"));
            model->setHeaderData(4, Qt::Horizontal, QObject::tr("heu_date"));
            model->setHeaderData(5, Qt::Horizontal, QObject::tr("prix"));

            return model;
    }
