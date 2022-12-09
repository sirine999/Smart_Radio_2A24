#include "pub.h"
#include "mainwindow.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QString>
#include <QMessageBox>


Pub::Pub()
{
    id_pub=0;nom_produit=" ";nom_entreprise=" ";type_produit=" ";passage=0;horraire= " ";horraire1=" ";horraire2= " ";horraire3="";horraire4= " ";horraire5="";duree=" ";duree1=" ";prix=0;
}



Pub::Pub(int id_pub,QString nom_produit,QString nom_entreprise,QString type_produit,int passage,QString horraire,QString horraire1,QString horraire2,QString horraire3,QString horraire4,QString horraire5,QString duree,QString duree1,int prix)
{
this->id_pub=id_pub;
this->nom_produit=nom_produit;
this->nom_entreprise=nom_entreprise;
this->type_produit=type_produit;
this->passage=passage;
this->horraire=horraire;
this->horraire1=horraire1;
this->horraire2=horraire2;
this->horraire3=horraire3;
this->horraire4=horraire4;
this->horraire5=horraire5;
this->duree=duree;
this->duree1=duree1;
this->prix=prix;

}
int Pub::getid(){return id_pub;}
QString Pub::getnomE(){return nom_produit;}
QString Pub::getnomP(){return nom_entreprise;}
QString Pub::gettype(){return type_produit;}
int Pub::getpass(){return passage;}
QString Pub::gethorraire(){return horraire;}
QString Pub::gethorraire1(){return horraire1;}
QString Pub::gethorraire2(){return horraire2;}
QString Pub::gethorraire3(){return horraire3;}
QString Pub::gethorraire4(){return horraire4;}
QString Pub::gethorraire5(){return horraire5;}
QString Pub::getduree(){return duree;}
QString Pub::getduree1(){return duree1;}
int Pub::getprix(){return prix;}


void Pub::setid(int id_pub){this ->id_pub=id_pub;}
void Pub::setnomE(QString nom_produit){this ->nom_produit=nom_produit;}
void Pub::setnomP(QString nom_entreprise){this ->nom_entreprise=nom_entreprise;}
void Pub::settype(QString type_produit){this ->type_produit=type_produit;}
void Pub::setpass(int passage){this ->passage=passage;}
void Pub::sethorraire(QString  horraire){this ->horraire=horraire;}
void Pub::sethorraire1(QString  horraire1){this ->horraire1=horraire1;}
void Pub::sethorraire2(QString  horraire2){this ->horraire2=horraire2;}
void Pub::sethorraire3(QString  horraire3){this ->horraire3=horraire3;}
void Pub::sethorraire4(QString  horraire4){this ->horraire4=horraire4;}
void Pub::sethorraire5(QString  horraire5){this ->horraire5=horraire5;}
void Pub::setduree(QString  duree){this ->duree=duree;}
void Pub::setduree1(QString  duree1){this ->duree1=duree1;}
void Pub::setprix(int prix){this ->prix=prix;}

bool Pub::ajouter()
{

QSqlQuery query;
QString res=QString::number(id_pub);
QString reso=QString::number(passage);
QString resi=QString::number(prix);

     query.prepare("INSERT INTO TABLE1 (id_pub,nom_produit,nom_entreprise,type_produit,passage,horraire,horraire1,horraire2,horraire3,horraire4,horraire5,duree,duree1,prix) "
                   "VALUES (:id,:nomp,:nome,:type,:pass,:horraire,:horraire1,:horraire2,:horraire3,:horraire4,:horraire5,:duree,:duree1,:prix)");


     query.bindValue(":id", res);
     query.bindValue(":nomp", nom_produit);
     query.bindValue(":nome", nom_entreprise);
     query.bindValue(":type", type_produit);
     query.bindValue(":pass", reso);
     query.bindValue(":horraire", horraire);
     query.bindValue(":horraire1", horraire1);
     query.bindValue(":horraire2", horraire2);
     query.bindValue(":horraire3", horraire3);
     query.bindValue(":horraire4", horraire4);
     query.bindValue(":horraire5", horraire5);
     query.bindValue(":duree", duree);
     query.bindValue(":duree1", duree1);
     query.bindValue(":prix", resi);


    return query.exec();


}
bool Pub::supprimer(int id_pub)
{
    QSqlQuery query;
    QString res=QString::number(id_pub);
    if(query.exec("Select * from table1 where id_pub='"+res+"'"))
    {
        int count=0;
        while(query.next())
            count++;

    if(count!=0)
    {
    query.prepare("Delete from TABLE1 where id_pub=:id_pub");
    query.bindValue(":id_pub", res);
    }
    else
        QMessageBox::critical(nullptr,QObject::tr(" NOT OK"),
                                  QObject::tr("Identifiant non existant\n""Click Cancel to exit."),QMessageBox::Cancel);
    }
    return query.exec();
}
QSqlQueryModel * Pub::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from TABLE1");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_pub"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom_produit"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("nom_entreprise"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("type_produit"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("passage"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("horraire"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("horraire1"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("horraire2"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("horraire3"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("horraire4"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("horraire5"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("duree"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("duree1"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("prix"));

return model;
}
bool Pub::modifier()
{
    QString res=QString::number(id_pub);
    QString reso=QString::number(passage);
    QString resi=QString::number(prix);

    QSqlQuery query;
    query.prepare("UPDATE TABLE1 SET id_pub= :id, nom_produit= :nomp, nom_entreprise= :nome, type_produit= :type,passage= :pass,horraire= :horraire,horraire1= :horraire1,horraire2= :horraire2,horraire3= :horraire3,horraire4= :horraire4,horraire5= :horraire5,duree= :duree ,duree1= :duree1 ,prix= :prix");

    query.bindValue(":id", res);
    query.bindValue(":nomp", nom_produit);
    query.bindValue(":nome", nom_entreprise);
    query.bindValue(":type", type_produit);
    query.bindValue(":pass", resi);
    query.bindValue(":horraire", horraire);
    query.bindValue(":horraire1", horraire1);
    query.bindValue(":horraire2", horraire2);
    query.bindValue(":horraire3", horraire3);
    query.bindValue(":horraire4", horraire4);
    query.bindValue(":horraire5", horraire5);
    query.bindValue(":duree", duree);
    query.bindValue(":duree1", duree1);
    query.bindValue(":prix", reso);
    return query.exec();

}

QSqlQueryModel *Pub::tri_id()
 {
     QSqlQueryModel * model=new QSqlQueryModel();

     model->setQuery("select * from  TABLE1 ORDER BY id_pub");

     model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_pub"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom_produit"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("nom_entreprise"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("type_produit"));
     model->setHeaderData(4,Qt::Horizontal,QObject::tr("passage"));
     model->setHeaderData(5,Qt::Horizontal,QObject::tr("horraire"));
     model->setHeaderData(5,Qt::Horizontal,QObject::tr("horraire1"));
     model->setHeaderData(5,Qt::Horizontal,QObject::tr("horraire2"));
     model->setHeaderData(5,Qt::Horizontal,QObject::tr("horraire3"));
     model->setHeaderData(5,Qt::Horizontal,QObject::tr("horraire4"));
     model->setHeaderData(5,Qt::Horizontal,QObject::tr("horraire5"));
     model->setHeaderData(6,Qt::Horizontal,QObject::tr("duree"));
     model->setHeaderData(6,Qt::Horizontal,QObject::tr("duree1"));
     model->setHeaderData(7,Qt::Horizontal,QObject::tr("prix"));
return model;
 }
QSqlQueryModel* Pub::rechercher (const QString &aux)

{
    QSqlQueryModel* model = new QSqlQueryModel();

    model->setQuery("select * from facture where ((id_pub||nom_produit||nom_entreprise||type_produit||passage||horraire||horraire1||horraire2||horraire3||horraire4||horraire5||duree||duree1||prix) LIKE '%"+aux+"%')");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_pub"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom_produit"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("nom_entreprise"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("type_produit"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("passage"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("horraire"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("horraire1"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("horraire2"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("horraire3"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("horraire4"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("horraire5"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("duree"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("duree1"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("prix"));

    return model;

}
void Pub::stat(QPieSeries *series,QFrame *horizontalFrame)
{
series->clear();

    QSqlQuery q("select type_produit,count(*) from TABLE1 group by type_produit");


     while(q.next())
     {qDebug()<<q.value(0).toString();
         series->append(q.value(0).toString()+": "+q.value(1).toString(),q.value(1).toInt());}
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Statistiques");
    chart->setBackgroundBrush(Qt::transparent);
    QChartView *chartview = new QChartView(chart);
    chartview->setRenderHint(QPainter::Antialiasing);
    chartview->setParent(horizontalFrame);
    chartview->resize(400,300);

    chart->setAnimationOptions(QChart::AllAnimations);
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignRight);
    series->setLabelsVisible(true);

}
