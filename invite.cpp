#include "invite.h"
#include <QDebug>

invite::invite(QString nom,QString prenom,int age,QString mail,int idinv)
{
    this->nom=nom;
    this->prenom=prenom;
    this->age=age;
    this->mail=mail;
    this->idinv=idinv;
}
//hedha constructeur

bool invite::ajouter()
{
    QSqlQuery query;
    QString res = QString(nom);
    QString res1 = QString(prenom);
    QString res2 = QString::number(age);
    QString res3= QString(mail);
    QString res4 = QString::number(idinv);//declaration



    query.prepare("insert into invite (nom,prenom,age,mail,idinv) ""values(:NOM,:PRENOM,:AGE,:MAIL,:IDinv)");// requette sql

   query.bindValue(":NOM",res);
   query.bindValue(":PRENOM",res1);
   query.bindValue(":AGE",res2);
   query.bindValue(":Mail",res3);
   query.bindValue(":IDinv",res4);

   return query.exec();
}

QSqlQueryModel * invite::afficher(QString rech, int ord)
{
QSqlQueryModel * model=new QSqlQueryModel();
model->setQuery("select * from invite where lower(nom) LIKE lower('%" + rech + "%') OR lower(prenom) LIKE lower('%" + rech + "%')OR lower(idinv) LIKE lower('%" + rech + "%')");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));

model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));

model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOM"));

model->setHeaderData(3,Qt::Horizontal,QObject::tr("AGE"));

model->setHeaderData(4,Qt::Horizontal,QObject::tr("MAIL"));
return model;
}

bool invite::supprimer(int idinv)
{
QSqlQuery query;
QString res = QString::number(idinv);
query.prepare("Delete from invite where idinv= :IDinv");
query.bindValue(":idinv",res);
return query.exec();
}




bool invite::modify(int idinv){
    QSqlQuery query;
    query.prepare("UPDATE invite SET NOM=:NOM, PRENOM=:PRENOM, AGE=AGE,MAIL=MAIL WHERE IDinv=:IDinv");
    query.bindValue(":NOM",nom);
    query.bindValue(":PRENOM",prenom);
    query.bindValue(":AGE",age);
    query.bindValue(":MAIL",mail);
    query.bindValue(":IDINV",idinv);
    return query.exec();
}

QSqlQueryModel * invite::TRI(int index)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    switch (index) {
    case 1 :
        model->setQuery("select * from invite ORDER BY IDinv DESC ");

        break;
        case 2:
        model->setQuery("select * from invite ORDER BY IDinv  ");

            break;
            case 3 :
        model->setQuery("select * from invite ORDER BY NOM DESC ");

                break;

                case 4 :
        model->setQuery("select * from invite ORDER BY NOM  ");

                    break;
                    case 5 :
        model->setQuery("select * from invite ORDER BY PRENOM DESC ");

                        break;
                        case 6 :
        model->setQuery("select * from invite ORDER BY PRENOM  ");

                            break;
    default:
        model->setQuery("select * from invite ORDER BY IDinv ");


        }
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRENOM"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("AGE"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("MAIL"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("IDINV"));
     return model;
}
