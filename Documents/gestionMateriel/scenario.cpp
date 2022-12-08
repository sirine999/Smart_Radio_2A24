#include "scenario.h"
#include "ui_scenario.h"
#include<QDebug>
scenario::scenario(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::scenario)
{
    ui->setupUi(this);
//scenario s;
    int ret=A.connect_arduino();
                               switch (ret)
                               {
                               case(0): qDebug() << "arduino  is available and connected to :" <<A.getarduino_port_name();
                                   ui->labela->setText("Arduino  is available and connected");
                                   ui->labela->setStyleSheet("QLabel {color : green; }");
                                   arduino_connected=1;
                               break ;
                               case(1): qDebug() << "arduino  is available and not connected to :" <<A.getarduino_port_name();
                                   if (arduino_connected==0)
                                  { ui->labela->setText("Arduino  is available and not connected");
                                   ui->labela->setStyleSheet("QLabel {color : yellow; }");}
                               break ;
                               case(-1): qDebug() << "arduino  is not available";
                                   ui->labela->setText("Arduino  is not available");
                                   ui->labela->setStyleSheet("QLabel {color : red; }");
                                   arduino_connected=0;
                                   break ;
                                   }

                    QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));
                   ui->table_stock->setModel((*sc).afficher_stock());

    }

scenario::scenario(int id,QString type,QString marque)
{
    this->id=id;
    this->type=type;
    this->marque=marque;
}

void scenario::update_label()
{
    data=A.read_from_arduino();
      /* if(data=="1")
            ui->labelaa->setText("mvt detectee");
       else if(data=="0")
            ui->labelaa->setText("mvt non detectee");*/

   /* data=A.read_from_arduino();
    QString text="";
    for(int i=0;i<data.length();i++)
    {text=text+data[i];}
    if(text.contains("\n"))
      {  text.remove("\n");
        ui->labelaa->setText(text);}*/

    int id=ui->id->text().toInt();
   QString type=ui->type->text();
   QString marque=ui->marque->text();

   if(data=="1")
   { ui->labelaa->setText("mvt detectee");
       scenario s(id,type,marque);

  bool test=s.insert_stock(id,type,marque);
  if(test)
  {
      ui->table_stock->setModel(s.afficher_stock());
          qDebug()<<"insertion";
          ui->id->clear();
          ui->type->clear();
          ui->marque->clear();


  }

     else { qDebug()<<"--error d'insertion";
          bool test2=s.supprimer(id);

       if(test2)
       {
           qDebug()<<"suppression";
            ui->table_stock->setModel(s.afficher_stock());
             ui->id->clear();
       }
       else  qDebug()<<"--error de suppression";}}


   else if(data=="0")
   {ui->labelaa->setText("mvt non detectee");
qDebug()<<"pas de mvt";}


}
bool scenario::insert_stock(int id,QString type,QString marque)
{
    QSqlQuery query;
    QString idd = QString::number(id);
    if(query.exec("select * from stock where id='"+idd+"'"))
    { int count=0;
        while(query.next())
            count++;
        if (count==0)
       {
    query.prepare("INSERT INTO stock (id,type,marque)"
                  "VALUES(:id,:type,:marque)");
    query.bindValue(":id",idd);
    query.bindValue(":type",type);
    query.bindValue(":marque",marque);}}

    return query.exec();
}

QSqlQueryModel * scenario::afficher_stock()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from stock");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("type"));
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("marque"));
    return model;
}

bool scenario::supprimer(int id)
{
    QSqlQuery query;
    QString id_string=QString::number(id);
    if(query.exec("select * from stock where id='"+id_string+"'"))
    { int count=0;
        while(query.next())
            count++;
        if (count!=0)
       {
          query.prepare(" Delete from stock where id=:id");
          query.bindValue(0, id);

        }
       }

    return query.exec();
}

scenario::~scenario()
{
    delete ui;

}


