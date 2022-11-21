#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QDialog>
#include <QMessageBox>
#include"materiel.h"
#include<QIntValidator>
#include"qrcode.h"
#include<qrcode.h>
#include <QUrl>
#include <QPixmap>
#include <QImage>
#include"calculer.h"
using namespace qrcodegen;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/21698/Documents/gestionMateriel/logo");
      ui->image->setPixmap(pix.scaled(100,100,Qt::KeepAspectRatio));
  ui->le_id->setValidator(new QIntValidator(0,99999999, this));
  ui->progressBar->setValue(0);
  ui->tab_materiel->setModel(m.afficher());
  /* statistiques*/


        int id=0;
        QString nom="";
        QString marque="";
        QString departement="";
        QString heu_date="";
        double prix=0;

        Materiel m(id,nom,marque,departement,heu_date,prix);



            QPieSeries *series = new QPieSeries();
            series->setHoleSize(0.35);


            int nbr=m.statistique("maintenance");
            int nbrr=m.statistique("IT");
            int nbrrr=m.statistique("acceuil");
            int nb=m.statistique("administration");
            int total=nbr+nbrr+nbrrr+nb;

            QString a=QString("maintenance "+QString::number((nbr*100)/total,'f',2)+"%" );
            QString b=QString("IT "+QString::number((nbrr*100)/total,'f',2)+"%" );
            QString c=QString("acceuil "+QString::number((nbrrr*100)/total,'f',2)+"%" );
            QString d=QString("administration "+QString::number((nb*100)/total,'f',2)+"%" );
            QPieSlice *slice = series->append(d,nb);
            slice->setExploded();
            slice->setLabelVisible();
            series->append(a,nbr);
            series->append(b, nbrr);
            series->append(c, nbrrr);

            QChart *chart = new QChart();
            chart->addSeries(series);
            chart->setAnimationOptions(QChart::SeriesAnimations);
            chart->setTitle("statistiques par departement");
            chart->setTheme(QChart::ChartThemeBlueIcy);


            QChartView *chartview = new QChartView(chart);
            chartview->setRenderHint(QPainter::Antialiasing);

            chartview->setParent(ui->horizontalFrame);





}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::stat()
{
    /* statistiques*/


          int id=0;
          QString nom="";
          QString marque="";
          QString departement="";
          QString heu_date="";
          double prix=0;

          Materiel m(id,nom,marque,departement,heu_date,prix);



              QPieSeries *series = new QPieSeries();
              series->setHoleSize(0.35);


              int nbr=m.statistique("maintenance");
              int nbrr=m.statistique("IT");
              int nbrrr=m.statistique("acceuil");
              int nb=m.statistique("administration");
              int total=nbr+nbrr+nbrrr+nb;

              QString a=QString("maintenance "+QString::number((nbr*100)/total,'f',2)+"%" );
              QString b=QString("IT "+QString::number((nbrr*100)/total,'f',2)+"%" );
              QString c=QString("acceuil "+QString::number((nbrrr*100)/total,'f',2)+"%" );
              QString d=QString("administration "+QString::number((nb*100)/total,'f',2)+"%" );
              QPieSlice *slice = series->append(d,nb);
              slice->setExploded();
              slice->setLabelVisible();
              series->append(a,nbr);
              series->append(b, nbrr);
              series->append(c, nbrrr);

              QChart *chart = new QChart();
              chart->addSeries(series);
              chart->setAnimationOptions(QChart::SeriesAnimations);
              chart->setTitle("statistiques par departement");
              chart->setTheme(QChart::ChartThemeBlueIcy);


              QChartView *chartview = new QChartView(chart);
              chartview->setRenderHint(QPainter::Antialiasing);

              chartview->setParent(ui->horizontalFrame);

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
 stat();
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
    ui->tab_materiel->setModel(m1.afficher());
    stat();}
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
     stat();
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
                //ui->tab_materiel->setModel(m.trie_NOM());
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
            if (choix=="id")
            {
                ui->tab_materiel->setModel(m.trie_ID());
                ui->tab_materiel->setModel(m.afficher());
                bool test=m.trie_ID();
                if (test)
                {

               ui->tab_materiel->setModel(m.trie_ID());
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

void MainWindow::on_pushButton_Recherche_clicked()
{Materiel m;


           QString choix=ui->comboBox_chercher->currentText();

           if (choix=="id")
           {
               QString id=ui->le_rech->text();
               ui->tab_materiel->setModel(m.rechercherid(id));
           }
           if (choix=="nom")
           {
               QString nom=ui->le_rech->text();
               ui->tab_materiel->setModel(m.recherchernom(nom));
           }
           if (choix=="departement")
           {
               QString departement=ui->le_rech->text();
               ui->tab_materiel->setModel(m.rechercherdepartement(departement));
           }
           if (choix=="marque")
           {
               QString marque=ui->le_rech->text();
               ui->tab_materiel->setModel(m.recherchermarque(marque));
           }

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
    ui->label_image->setText(query.value(6).toString());

     }}
 else
      QMessageBox::critical(this,tr("error"),query.lastError().text());


}

int MainWindow::on_pdf_clicked()
{

    QPdfWriter fichierMateriel_pdf("listemateriel.pdf");

       QPainter painter(&fichierMateriel_pdf);
       int i = 4000;
       QImage img("C:/Users/21698/Documents/gestionMateriel/logo");
                 QPoint imageCoordinates(200,150);
              painter.drawImage(imageCoordinates,img);
              painter.setPen(Qt::blue);
              painter.setFont(QFont("Time New Roman", 25));
              painter.drawText(3000,1400,"Liste des materiaux");
              painter.setPen(Qt::black);
              painter.setFont(QFont("Time New Roman", 15));
              painter.drawRect(100,100,9400,2500);
              painter.drawRect(100,3000,9400,500);
              painter.setFont(QFont("Time New Roman", 9));
              painter.drawText(400,3300,"ID");
              painter.drawText(2000,3300,"Nom");
              painter.drawText(3400,3300,"Marque");
              painter.drawText(4700,3300,"Departement");
              painter.drawText(6200,3300,"Heu_Date");
              painter.drawText(7600,3300,"Prix");
              painter.drawRect(100,3000,9400,9000);

              QSqlQuery query;
              query.prepare("select * from materiel");
              query.exec();
              while (query.next())
              {
                  painter.drawText(400,i,query.value(0).toString());
                  painter.drawText(2000,i,query.value(1).toString());
                  painter.drawText(3400,i,query.value(2).toString());
                  painter.drawText(4700,i,query.value(3).toString());
                  painter.drawText(6200,i,query.value(4).toString());
                  painter.drawText(7600,i,query.value(5).toString());


                 i = i + 350;
              }
              int reponse = QMessageBox::question(this, "Génerer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
                  if (reponse == QMessageBox::Yes)
                  {
                      QDesktopServices::openUrl(QUrl::fromLocalFile("C:\\Users\\21698\\Documents\\build-gestionMateriel-Desktop_Qt_5_9_9_MinGW_32bit-Debug\\listemateriel.pdf"));

                      painter.end();
                  }
                  if (reponse == QMessageBox::No)
                  {
                      painter.end();
                  }


}

int MainWindow::on_pb_pdf1_clicked()
{
    QPrinter printer;
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName("materiel.pdf");
        QPainter painter;
        if (! painter.begin(&printer)) { // failed to open file
            qWarning("failed to open file, is it writable?");
            return 1;
        }

       QString id=ui->le_id->text();
       QString nom=ui->le_nom->text();
       QString marque=ui->le_marque->text();
       QString departement=ui->le_departement->text();
       QString prix=ui->le_prix->text();
       QString heu_date=ui->le_heu_date->text();
       painter.setFont(QFont("Time New Roman", 25));
       painter.drawText(400,100,"MATERIEL");
       painter.setPen(Qt::black);
       //painter.drawText(400,10,"gestion radio");
       //painter.setFont(QFont("Time New Roman", 15));
       //painter.drawRect(100,100,9400,2500);
       // painter.drawRect(100,3000,9400,500);
       painter.setFont(QFont("Time New Roman", 9));
       painter.drawText(10,300,"Identifiant:");
       painter.drawText(150,300,id);
       painter.drawText(10,350,"Nom:");
       painter.drawText(150,350,nom);
       painter.drawText(10,400,"Departement:");
       painter.drawText(150,400,departement);
       painter.drawText(10,450,"Marque:");
       painter.drawText(150,450,marque);
       painter.drawText(10,500,"Prix :");
       painter.drawText(150,500,prix);
       painter.drawText(10,550,"Date et heure:");
       painter.drawText(150,550,heu_date);
       QImage img("C:/Users/21698/Documents/gestionMateriel/logo");
       QPoint imageCoordinates(200,150);
       painter.drawImage(imageCoordinates,img);

              int reponse = QMessageBox::question(this, "Génerer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
                  if (reponse == QMessageBox::Yes)
                  {
                      QDesktopServices::openUrl(QUrl::fromLocalFile("C:\\Users\\21698\\Documents\\build-gestionMateriel-Desktop_Qt_5_9_9_MinGW_32bit-Debug\\materiel.pdf"));

                      painter.end();
                  }
                  if (reponse == QMessageBox::No)
                  {
                      painter.end();
                  }
                  painter.end();


}

void MainWindow::on_pb_qr_clicked()
{
    int tab=ui->tab_materiel->currentIndex().row();
            QVariant idd=ui->tab_materiel->model()->data(ui->tab_materiel->model()->index(tab,0));
            QString id= idd.toString();
            QSqlQuery qry;
            qry.prepare("select * from materiel where id=:id");
            qry.bindValue(":id",id);
            qry.exec();
            QString nom,marque,departement,heu_date,code;

            while(qry.next()){
                nom=qry.value(1).toString();
                marque=qry.value(2).toString();
                departement=qry.value(3).toString();
                heu_date=qry.value(4).toString();

            }
             //code=int(id);
             code="identifiant: "+id+" nom: "+nom+" marque: "+marque+" departement: "+departement+" heure et date d entree: "+heu_date;
             QrCode qr = QrCode::encodeText(code.toUtf8().constData(), QrCode::Ecc::HIGH);

            // Read the black & white pixels
            QImage im(qr.getSize(),qr.getSize(), QImage::Format_RGB888);
            for (int y = 0; y < qr.getSize(); y++) {
                for (int x = 0; x < qr.getSize(); x++) {
                    int color = qr.getModule(x, y);  // 0 for white, 1 for black

                    // You need to modify this part
                    if(color==0)
                        im.setPixel(x, y,qRgb(254, 254, 254));
                    else
                        im.setPixel(x, y,qRgb(0, 0, 0));
                }
            }
            im=im.scaled(200,200);
            ui->qrcode->setPixmap(QPixmap::fromImage(im));
            int i=0 ;
            for(i=0;i<100;i=i+0.1){
                i++;
                ui->progressBar->setValue(i);
            }
}

void MainWindow::on_inserer_image_clicked()
{
       QFileDialog dialog(this);
       dialog.setNameFilter(tr("Images (*.png *.xpm *.jpg)"));
       dialog.setViewMode(QFileDialog::Detail);
       QString fileName = QFileDialog::getOpenFileName(this,
       tr("Open Images"), "C://Users//21698//Documents//gestionMateriel", tr("Image Files (*.png *.jpg *.bmp)"));
       if (!fileName.isEmpty())
       {
           QImage image(fileName);
           QSqlQuery qry;
           ui->label_image->setPixmap(QPixmap::fromImage(image));
           QString im=ui->label_image->text();
           int id=ui->le_id->text().toInt();
           Materiel m(id,im);
           bool test=m.ajouterimage(id,im);
           if(test)
           {

              QMessageBox::information(this,tr("Update Result"),tr("<font color=black>Profile Photo Update Completed"));
           }
           else

              QMessageBox::information(this,tr("Update Result failed"),tr("failed"));

       }

}




void MainWindow::on_calcul_clicked()
{

    calc=new Calculer(this);
    calc->show();

}
