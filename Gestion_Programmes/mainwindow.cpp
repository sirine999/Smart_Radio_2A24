#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlQuery>
#include <QMessageBox>
#include "gprogrammes.h"
#include "connection.h"
#include <QDebug>
#include <QPrinter>
#include <QPainter>
#include<QtCharts>
#include<QChartView>
#include <QPieSeries>
#include <QPieSlice>
#include <QImage>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    int ret=A.connect_arduino(); // lancer la connexion à arduino
    switch(ret){
    case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
        break;
    case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
       break;
    case(-1):qDebug() << "arduino is not available";
    }
     QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
     //le slot update_label suite à la reception du signal readyRead (reception des données).
    ui->TableauAffichage->setModel(Etmp.afficher());
    /* statistiques*/


              int ID=0;
              QString nomProg="";
              QString typeProg="";
              int Duree=0;
              QString Date_Prog="";
              QString nomPresentateur="";
              int Nbreinvites=0;

              GProgrammes GP(ID,nomProg,typeProg,Duree,Date_Prog,nomPresentateur,Nbreinvites);



                  QPieSeries *series = new QPieSeries();
                  series->setHoleSize(0.35);


                  int nbr=GP.statistique("sportive");
                  int nbrr=GP.statistique("educative");
                  int nbrrr=GP.statistique("musicale");
                  int nb=GP.statistique("culturelle");
                  int total=nbr+nbrr+nbrrr+nb;

                  QString a=QString("sportive "+QString::number((nbr*100)/total,'f',2)+"%" );
                  QString b=QString("educative "+QString::number((nbrr*100)/total,'f',2)+"%" );
                  QString c=QString("musicale "+QString::number((nbrrr*100)/total,'f',2)+"%" );
                  QString d=QString("culturelle "+QString::number((nb*100)/total,'f',2)+"%" );
                  QPieSlice *slice = series->append(d,nb);
                  slice->setExploded();
                  slice->setLabelVisible();
                  series->append(a,nbr);
                  series->append(b, nbrr);
                  series->append(c, nbrrr);

                  QChart *chart = new QChart();
                  chart->addSeries(series);
                  chart->setAnimationOptions(QChart::SeriesAnimations);
                  chart->setTitle("Statistiques suivant le type du programme");
                  chart->setTheme(QChart::ChartThemeBlueIcy);


                  QChartView *chartview = new QChartView(chart);
                  chartview->setRenderHint(QPainter::Antialiasing);

                  chartview->setParent(ui->horizontalFrame);

              //for email tab
              connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMail()));
              connect(ui->browseBtn, SIGNAL(clicked()), this, SLOT(browse()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update_label()
{
    data=A.read_from_arduino();

    if(data=="1")

        ui->label_3->setText("ON"); // si les données reçues de arduino via la liaison série sont égales à 1
    // alors afficher ON

    else if (data=="0")

        ui->label_3->setText("OFF");   // si les données reçues de arduino via la liaison série sont égales à 0
     //alors afficher ON
}
void MainWindow::on_ajouter_clicked()
{


    //Récupération des informations saisies dans les 3 champs
    int ID=ui->ID->text().toInt();
    QString nomProg=ui->nomProg->text();
    QString typeProg=ui->typeProg->text();
    int Duree=ui->Duree->text().toInt();
    QString Date_Prog=ui->Date_Prog->text();
    QString nomPresentateur=ui->nomPresentateur->text();
    int Nbreinvites=ui->Nbreinvites->text().toInt();

    GProgrammes GP(ID,nomProg,typeProg,Duree,Date_Prog,nomPresentateur,Nbreinvites);
    bool test=GP.ajouter();

    if(test)
    {
        //Refresh (Actualiser)
        A.write_to_arduino("1"); //envoyer 1 à arduino
        ui->TableauAffichage->setModel(Etmp.afficher());
        QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Ajout effectué\n""Click Cancel to exit."), QMessageBox::Cancel);


    }
    else
    {
         A.write_to_arduino("0"); //envoyer 1 à arduino
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("Ajout non effectué.\n""Click Cancel to exit."), QMessageBox::Cancel);
    }
    // historique
            QFile file("C:/Users/Ghassen/OneDrive/Documents/Gestion_Programmes/Gestion_Programmes/historique.txt");
            if(!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
                return;
            QTextStream cout(&file);
            QSqlQuery query;
            QString ID_string= QString::number(ID);
            QString d_info = QDateTime::currentDateTime().toString();
            QString message2=d_info+" - Un Programme a été ajouté avec la référence ID  "+ID_string+"\n";
            cout<<message2;


}

void MainWindow::on_Supprimer_clicked()
{
    int ID=ui->ID->text().toInt();
    bool test=Etmp.supprimer(ID);

    if(test)
    {
        //Refresh (Actualiser)
        ui->TableauAffichage->setModel(Etmp.afficher());
        QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Suppression effectuée. \n""Click Cancel to Exit."),QMessageBox::Cancel);
        QFile file("C:/Users/Ghassen/OneDrive/Documents/Gestion_Programmes/Gestion_Programmes/historique.txt");
                if(!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
                    return;
                QTextStream cout(&file);
                QSqlQuery query;
                QString ID_string= QString::number(ID);
                QString d_info = QDateTime::currentDateTime().toString();
                QString message2=d_info+" - Un Programme a été supprimé avec la référence ID  "+ID_string+"\n";
                cout<<message2;
    }
    else
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("Suppression non effectué.\n""Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_Modifier_clicked()
{
    GProgrammes P1;
      int ID=ui->ID->text().toInt();
      QString nomProg=ui->nomProg->text();
      QString typeProg=ui->typeProg->text();
      int Duree=ui->Duree->text().toInt();
      QString Date_Prog=ui->Date_Prog->text();
      QString nomPresentateur=ui->nomPresentateur->text();
      int Nbreinvites=ui->Nbreinvites->text().toInt();
      GProgrammes P(ID,nomProg,typeProg,Duree,Date_Prog,nomPresentateur,Nbreinvites);

     bool test=P.modifier(ID,nomProg,typeProg,Duree,Date_Prog,nomPresentateur,Nbreinvites);
     if(test)
     {ui->TableauAffichage->setModel(P1.afficher());
         QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("modif successful.\n"
                                             "click cancel to exit."),QMessageBox::Cancel);
         QFile file("C:/Users/Ghassen/OneDrive/Documents/Gestion_Programmes/Gestion_Programmes/historique.txt");
                 if(!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
                     return;
                 QTextStream cout(&file);
                 QSqlQuery query;
                 QString ID_string= QString::number(ID);
                 QString d_info = QDateTime::currentDateTime().toString();
                 QString message2=d_info+" - Un Programme a été modifié avec la référence ID  "+ID_string+"\n";
                 cout<<message2;

     }
     else QMessageBox::critical(nullptr, QObject::tr(" not OK"),
                                   QObject::tr("modif non effectue.\n"
                                               "click cancel to exit."),QMessageBox::Cancel);
}





void MainWindow::on_TableauAffichage_activated(const QModelIndex &index)
{

    QSqlQuery query;

    QString val;
            val=ui->TableauAffichage->model()->data(index).toString();
    //val=ui->TableauAffichage->model()->index(index.row(),index.column()).data().toString();
    query.prepare("select * from GProgrammes where ID='"+val+"' or nomProg='"+val+"' or typeProg='"+val+"' or Duree='"+val+"' or Date_Prog='"+val+"' or nomPresentateur='"+val+"' or Nbreinvites='"+val+"' ");
    if(query.exec())
 {  while(query.next()){
            ui->ID->setText(query.value(0).toString());
            ui->nomProg->setText(query.value(1).toString());
            ui->typeProg->setText(query.value(2).toString());
            ui->Duree->setValue(query.value(3).toFloat());
            ui->Date_Prog->setDate(query.value(4).toDate());
            ui->nomPresentateur->setText(query.value(5).toString());
            ui->Nbreinvites->setValue(query.value(6).toInt());
     }}
 else
      QMessageBox::critical(this,tr("error"),query.lastError().text());
}



void MainWindow::on_Trier_clicked()
{
    GProgrammes p;
                QString choix=ui->comboBox_tri->currentText();
                if (choix=="nomProg")
                {
                    ui->TableauAffichage->setModel(p.trier_NOM());
                    ui->TableauAffichage->setModel(p.afficher());
                    bool test=p.trier_NOM();
                    if (test)
                    {

                ui->TableauAffichage->setModel(p.trier_NOM());
                        QMessageBox::information(nullptr,QObject::tr("ok"),
                                                 QObject::tr("tri NomProg effectué \n"
                                                             "Click Cancel to exist ."),QMessageBox::Cancel);

                    }
                    else
                          QMessageBox::critical(nullptr, QObject::tr("non"),
                                      QObject::tr("tri NomProg failed.\n"
                                                  "Click Cancel to exit."), QMessageBox::Cancel);
                }
                if (choix=="Nbreinvites")
                {
                    ui->TableauAffichage->setModel(p.trier_INVITES());
                    ui->TableauAffichage->setModel(p.afficher());
                    bool test=p.trier_INVITES();
                    if (test)
                    {

                ui->TableauAffichage->setModel(p.trier_INVITES());
                        QMessageBox::information(nullptr,QObject::tr("ok"),
                                                 QObject::tr("tri invites effectué \n"
                                                             "Click Cancel to exist ."),QMessageBox::Cancel);

                    }
                    else
                          QMessageBox::critical(nullptr, QObject::tr("non"),
                                      QObject::tr("tri invites failed.\n"
                                                  "Click Cancel to exit."), QMessageBox::Cancel);
                }
                if (choix=="ID")
                {
                    ui->TableauAffichage->setModel(p.trier_ID());
                    ui->TableauAffichage->setModel(p.afficher());
                    bool test=p.trier_ID();
                    if (test)
                    {

                ui->TableauAffichage->setModel(p.trier_ID());
                        QMessageBox::information(nullptr,QObject::tr("ok"),
                                                 QObject::tr("tri id effectué \n"
                                                             "Click Cancel to exist ."),QMessageBox::Cancel);

                    }
                    else
                          QMessageBox::critical(nullptr, QObject::tr("non"),
                                      QObject::tr("tri id failed.\n"
                                                  "Click Cancel to exit."), QMessageBox::Cancel);
                }
}


void MainWindow::on_Rechercher_clicked()
{
    GProgrammes p;


               QString choix=ui->comboBox_recherche->currentText();

               if (choix=="ID")
               {
                   QString ID=ui->Le_rech->text();
                   ui->TableauAffichage->setModel(p.rechercherid(ID));
               }
               if (choix=="nomProg")
               {
                   QString nomProg=ui->Le_rech->text();
                   ui->TableauAffichage->setModel(p.recherchernom(nomProg));
               }
               if (choix=="nomPresentateur")
               {
                   QString nomPresentateur=ui->Le_rech->text();
                   ui->TableauAffichage->setModel(p.recherchernomPresentateur(nomPresentateur));
               }

}



int MainWindow::on_ImporterPDF_clicked()
{
    QPrinter printer;
                  printer.setOutputFormat(QPrinter::PdfFormat);
                  printer.setOutputFileName("Gestion_des_programmes.pdf");
                  QPainter painter;
                  QImage imagen(":/image/imagen.jpg");
                  if (! painter.begin(&printer)) { // failed to open file
                      qWarning("failed to open file, is it writable?");
                      return 1;
                  }
                      QString ID=ui->ID->text();
                      QString nomProg=ui->nomProg->text();
                      QString typeProg=ui->typeProg->text();
                      QString Duree=ui->Duree->text();
                      QString Date_Prog=ui->Date_Prog->text();
                      QString nomPresentateur=ui->nomPresentateur->text();
                      QString Nbreinvites=ui->Nbreinvites->text();
                      painter.drawImage(-40,-40,imagen);
                      painter.drawText(400,50,"gestion des programmes");
                      painter.drawText(10,100,"Identifiant:");
                      painter.drawText(80,100,ID);
                      painter.drawText(10,150,"nomProg:");
                      painter.drawText(80,150,nomProg);
                      painter.drawText(10,200,"typeProg:");
                      painter.drawText(80,200,typeProg);
                      painter.drawText(10,250,"Duree:");
                      painter.drawText(150,250,Duree);
                      painter.drawText(10,300,"Date_Prog:");
                      painter.drawText(150,300,Date_Prog);
                      painter.drawText(10,350,"nomPresentateur:");
                      painter.drawText(150,350,nomPresentateur);
                      painter.drawText(10,400,"Nbreinvites:");
                      painter.drawText(150,400,Nbreinvites);
                      painter.end();

}



//mailing
void  MainWindow::browse()
{
    files.clear();

    QFileDialog dialog(this);
    dialog.setDirectory(QDir::homePath());
    dialog.setFileMode(QFileDialog::ExistingFiles);

    if (dialog.exec())
        files = dialog.selectedFiles();

    QString fileListString;
    foreach(QString file, files)
        fileListString.append( "\"" + QFileInfo(file).fileName() + "\" " );

    ui->file->setText( fileListString );

}
void   MainWindow::sendMail()
{
    Smtp* smtp = new Smtp("ghassen.achour@esprit.tn",ui->mail_pass->text(), "smtp.gmail.com");
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    if( !files.isEmpty() )
        smtp->sendMail("ghassen.achour@esprit.tn", ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText(), files );
    else
        smtp->sendMail("ghassen.achour@esprit.tn", ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText());
}


void   MainWindow::mailSent(QString status)
{

    if(status == "Message sent")
        QMessageBox::warning( nullptr, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
    ui->rcpt->clear();
    ui->subject->clear();
    ui->file->clear();
    ui->msg->clear();
    ui->mail_pass->clear();
}



void MainWindow::on_HISTORIQUE_clicked()
{
    QString filename="C:/Users/Ghassen/OneDrive/Documents/Gestion_Programmes/Gestion_Programmes/historique.txt";
    QFile file(filename);
    if(!file.exists()){
        qDebug() << "NO exist "<<filename;
    }else{
        qDebug() << filename<<" ...";
    }
    QString line;
    ui->Histo->clear();
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream stream(&file);
        while (!stream.atEnd()){
            line = stream.readLine();
            ui->Histo->setText(ui->Histo->toPlainText()+line+"\n");
            qDebug() << "linea: "<<line;
        }
    }
    file.close();
}



void MainWindow::on_Quitter_clicked()
{
    close();
}

void MainWindow::on_Quitter_2_clicked()
{
    close();
}

void MainWindow::on_Quitter_3_clicked()
{
    close();
}

void MainWindow::on_Quitter_4_clicked()
{
    close();
}
