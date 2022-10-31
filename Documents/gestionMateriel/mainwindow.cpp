#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include"materiel.h"
#include<QIntValidator>
#include <QString>
#include <QSqlQuery>
#include<QtDebug>
#include<QObject>
#include<QDateTime>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
  ui->le_id->setValidator(new QIntValidator(0,99999999, this));
  ui->tab_materiel->setModel(m.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
  int id=ui->le_id->text().toInt();
 QString nom=ui->le_nom->text();
 QString marque=ui->le_marque->text();
 QString departement=ui->le_departement->text();
 QString heu_date=ui->le_heu_date->text();
 double prix=ui->le_prix->text().toDouble();


 Materiel m(id,nom,marque,departement,heu_date,prix);

bool test=m.ajouter();
if(test)
{
    QMessageBox::information(nullptr, QObject::tr("OK"),
                            QObject::tr("ajout successful.\n"
                                        "click cancel to exit."),QMessageBox::Cancel);
 ui->tab_materiel->setModel(m.afficher());
}
else QMessageBox::critical(nullptr, QObject::tr(" not OK"),
                              QObject::tr("ajout non effectue.\n"
                                          "click cancel to exit."),QMessageBox::Cancel);

}

void MainWindow::on_pb_supprimer_clicked()
{
    Materiel m1; m1.setid(ui->le_id->text().toInt());
    bool test=m1.supprimer(m1.getid());
    QMessageBox msgbox;
    if(test) {msgbox.setText("suppression avec succes");
    ui->tab_materiel->setModel(m1.afficher());}
    else msgbox.setText("echec de suppression");
    msgbox.exec();

}

void MainWindow::on_pb_modif_clicked()
{ Materiel m1;
  int id=ui->le_id->text().toInt();
  QString nom=ui->le_nom->text();
  QString marque=ui->le_marque->text();
  QString departement=ui->le_departement->text();
  QString heu_date=ui->le_heu_date->text();
  double prix=ui->le_prix->text().toDouble();
  Materiel m(id,nom,marque,departement,heu_date,prix);

 bool test=m.modifier(id,nom,marque,departement,heu_date,prix);
 if(test)
 {ui->tab_materiel->setModel(m1.afficher());
     QMessageBox::information(nullptr, QObject::tr("OK"),
                             QObject::tr("modif successful.\n"
                                         "click cancel to exit."),QMessageBox::Cancel);

 }
 else QMessageBox::critical(nullptr, QObject::tr(" not OK"),
                               QObject::tr("modif non effectue.\n"
                                           "click cancel to exit."),QMessageBox::Cancel);
}

void MainWindow::on_pushButton_trie_clicked()
{
    Materiel m;
            QString choix=ui->comboBox_tri->currentText();
            if (choix=="nom")
            {
                ui->tab_materiel->setModel(m.trie_NOM());
                ui->tab_materiel->setModel(m.afficher());
                bool test=m.trie_NOM();
                if (test)
                {

            ui->tab_materiel->setModel(m.trie_NOM());
                    QMessageBox::information(nullptr,QObject::tr("ok"),
                                             QObject::tr("tri Nom effectué \n"
                                                         "Click Cancel to exist ."),QMessageBox::Cancel);

                }
                else
                      QMessageBox::critical(nullptr, QObject::tr("non"),
                                  QObject::tr("tri Nom failed.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
            }
            if (choix=="prix")
            {
                ui->tab_materiel->setModel(m.trie_PRIX());
                ui->tab_materiel->setModel(m.afficher());
                bool test=m.trie_PRIX();
                if (test)
                {

            ui->tab_materiel->setModel(m.trie_PRIX());
                    QMessageBox::information(nullptr,QObject::tr("ok"),
                                             QObject::tr("tri prix effectué \n"
                                                         "Click Cancel to exist ."),QMessageBox::Cancel);

                }
                else
                      QMessageBox::critical(nullptr, QObject::tr("non"),
                                  QObject::tr("tri prix failed.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
            }
}

void MainWindow::on_pushButton_Recherche_clicked()
{Materiel m;
    QString nom=ui->le_rech->text();
    ui->tab_materiel->setModel(m.recherchernom(nom));

}

void MainWindow::on_tab_materiel_activated(const QModelIndex &index)
{

    QSqlQuery query;

    QString val;
            val=ui->tab_materiel->model()->data(index).toString();
    //val=ui->tab_materiel->model()->index(index.row(),index.column()).data().toString();
    query.prepare("select * from materiel where id='"+val+"' or nom='"+val+"' or marque='"+val+"' or departement='"+val+"' or heu_date='"+val+"' or prix='"+val+"' ");
    if(query.exec())
 {  while(query.next()){
    ui->le_id->setText(query.value(0).toString());
    ui->le_nom->setText(query.value(1).toString());
    ui->le_marque->setText(query.value(2).toString());
    ui->le_departement->setText(query.value(3).toString());
    ui->le_heu_date->setDateTime(query.value(4).toDateTime());
    ui->le_prix->setText(query.value(5).toString());

     }}
 else
      QMessageBox::critical(this,tr("error"),query.lastError().text());
}
