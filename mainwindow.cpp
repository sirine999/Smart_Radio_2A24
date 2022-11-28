#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPrinter>
#include <QPainter>
#include "widget.h"
using namespace DuarteCorporation;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tab_emp->setModel(C.afficher());
    ui->cb_id_supp->setModel(C.getAllId());
    ui->cb_id_modif->setModel(C.getAllId());
    ui->cb_pdf->setModel(C.getAllId());

    ui->le_id->setValidator(new QIntValidator(100000, 999999, this));
    ui->le_salaire->setValidator(new QIntValidator(1000, 9999, this));




    //**************************************************arduino*********************

     int ret=A.connect_arduino();

         switch (ret) {
         case 0 :
             qDebug()<<"Arduino is available and connected to : "<<A.getarduino_port_name();
             break;

         case 1 :
             qDebug()<<"Arduino is available but not connected to : "<<A.getarduino_port_name();
             break;
         case -1 :
             qDebug()<<"Arduino is not available ";
             break;
         }

   QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(concatRfid()));









 //**************************************************************************************

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_ajout_em_clicked()
{
        int id=ui->le_id->text().toInt();
        int salaire=ui->le_salaire->text().toInt();
        QString prenom=ui->le_prenom->text();
        QString nom=ui->le_nom->text();
        QString mail=ui->le_mail->text();
        QString adresse=ui->le_adresse->text();
        QString genre = ui->cb_genre->currentText();
    Employee C(id,nom,prenom,adresse,mail,genre,salaire);
    bool test1=((controlEmail(mail))&&(controlId(id))&&(controlSalaire(salaire))&&(controlVide(adresse))&&(controlVide(mail))&&(controlVide(prenom)));

    if(test1)
      {
        bool test=C.ajouter();
        ui->tab_emp->setModel(C.afficher());
        ui->cb_id_supp->setModel(C.getAllId());
        ui->cb_id_modif->setModel(C.getAllId());
        ui->cb_pdf->setModel(C.getAllId());
    }
        /* if(test)
        {
            QMessageBox::information(nullptr, QObject::tr("ajouter un employé"),
                                       QObject::tr("employé ajouté.\n"
                                                   "Click Cancel to exit."), QMessageBox::Cancel);
            ui->tab_emp->setModel(C.afficher());
            ui->cb_id_supp->setModel(C.getAllId());
            ui->cb_id_modif->setModel(C.getAllId());
            ui->cb_pdf->setModel(C.getAllId());


        }
        }else
    { QMessageBox::critical(nullptr, QObject::tr("ajouter un employé"),
                               QObject::tr("employé non ajouté, vérifier les champs.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
    }*/
}

void MainWindow::on_pb_modif_emp_clicked()
{
        int id=ui->cb_id_modif->currentText().toInt();
        int salaire=ui->le_salaire_modif->text().toInt();
        QString prenom=ui->le_prenom_modif->text();
        QString nom=ui->le_nom_modif->text();
        QString mail=ui->le_mail_modif->text();
        QString adresse=ui->le_adresse_modif->text();
        QString genre = ui->cb_genre_modif->currentText();
Employee C(id,nom,prenom,adresse,mail,genre,salaire);
bool test1=((controlEmail(mail))&&(controlId(id))&&(controlSalaire(salaire))&&(controlVide(adresse))&&(controlVide(mail))&&(controlVide(prenom)));

if(test1)
  {
    bool test=C.modifier();
    ui->tab_emp->setModel(C.afficher());
    ui->cb_id_supp->setModel(C.getAllId());
    ui->cb_id_modif->setModel(C.getAllId());
    ui->cb_pdf->setModel(C.getAllId());}
    /*   if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("modifier un employé"),
                                   QObject::tr("employé modifié.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tab_emp->setModel(C.afficher());
        ui->cb_id_supp->setModel(C.getAllId());
        ui->cb_id_modif->setModel(C.getAllId());
        ui->cb_pdf->setModel(C.getAllId());

    }}else
{ QMessageBox::information(nullptr, QObject::tr("ajouter un employé"),
                           QObject::tr("employé non ajouté, vérifier les champs.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
}*/

}

void MainWindow::on_pb_supprimer_employe_clicked()
{
    QMessageBox msgBox;
    Employee C1;


C1.setId(ui->cb_id_supp->currentText().toInt());
        bool test=C1.supprimer(C1.getId());
        ui->tab_emp->setModel(C.afficher());
        ui->cb_id_supp->setModel(C.getAllId());
        ui->cb_id_modif->setModel(C.getAllId());
        ui->cb_pdf->setModel(C.getAllId());
   /* if(test)
      {  msgBox.setText("supprission avec succes.");
        ui->tab_emp->setModel(C.afficher());
        ui->cb_id_supp->setModel(C.getAllId());
        ui->cb_id_modif->setModel(C.getAllId());
        ui->cb_pdf->setModel(C.getAllId());

    }else
    { msgBox.setText("Echec de supprission");}
        msgBox.exec();*/
}

//control de saisie:

bool MainWindow::controlSalaire(int test)
{
    QString salair= QString::number(test);
    for(int i=0;i<salair.length();i++)
    {
        if (salair.length()==4)
        {
            return true;
        }
    }
    return false;
}
bool MainWindow::controlId(int test)
{
    QString num= QString::number(test);
    for(int i=0;i<num.length();i++)
    {
        if (num.length()==6)
        {
            return true;
        }
    }
    return false;
}
bool MainWindow::controlVide(QString test)
{
    if(test!="")
        return  true;
    return false;
}
bool MainWindow::controlEmail(QString test)
{
    for(int i=0;i<test.length();i++)
    {
        if (test.at(i)=='@')
        {
            return true;
        }
    }
    return false;
}












void MainWindow::on_pushButton_5_clicked()
{
    close();
}

void MainWindow::on_pushButton_10_clicked()
{
    close();
}

void MainWindow::on_pushButton_11_clicked()
{
    close();
}

void MainWindow::on_cb_id_modif_activated(const QString &arg1)
{
    QString choix=ui->cb_id_modif->currentText();


    Employee *EM;
    EM=C.reademploye(choix);//EM UN POINTEUR POUR Q'on stock dans lui le retour de la methode reademployer ili howa enregistrement de l'employer
      int salairee=EM->getSalaire();
      QString salairee_string=QString::number(salairee);


            ui->le_nom_modif->setText(EM->getNom());//3ibara 9otlo iktbli nom mta3 em ili hia enregistrement fil champ nom
            ui->le_prenom_modif->setText(EM->getPrenom());
            ui->le_adresse_modif->setText(EM->getAdresse());
            ui->le_mail_modif->setText(EM->getMail());
            ui->le_salaire_modif->setText(salairee_string);
            ui->cb_genre->setCurrentText(EM->getGenre());
}

void MainWindow::on_search_pb_clicked()
{
    QString val=ui->le_rech->text();
    QString option=ui->cb_rech_emp->currentText();
    if((val!="")&&(option=="id"))
{        ui->tab_emp->setModel(C.afficher_id(val));}
    else if((val!="")&&(option=="nom"))
    {
             ui->tab_emp->setModel(C.afficher_nom(val));
    }
    else if((val!="")&&(option=="salaire"))
    {
               ui->tab_emp->setModel(C.afficher_salaire(val));
    }else if(option=="choisir")
    {
       ui->tab_emp->setModel(C.afficher());
    }
}

void MainWindow::on_cb_tri_activated(const QString &arg1)
{
    QString choix=ui->cb_tri->currentText();
    ui->tab_emp->setModel(C.afficher_choix(choix));
}

void MainWindow::on_pushButton_clicked()
{
   QString id_cb=ui->cb_pdf->currentText();
   Employee * EM ;
   EM=C.reademploye(id_cb);
   QString id_string=QString::number(EM->getId());
   QString nom_string = EM->getNom();
   QString prenom_string = EM->getPrenom();
   QString adresse_string = EM->getAdresse();
   QString genre_string = EM->getGenre();
   QString salaire_string=QString::number(EM->getSalaire());





    QPrinter printer;
               printer.setOutputFormat(QPrinter::PdfFormat);
               printer.setOutputFileName("C:/Users/Mouhamed/Desktop/projetQt/documents/"+id_string+".pdf");
                          QPainter painter;
                          if(! painter.begin(&printer))
                          { qWarning("failed to open file");  }
                                 painter.setFont(QFont("Arial", 30));
                                 painter.setPen(Qt::darkRed);
                             painter.drawText(100,100," Smart Radio ");
                                 painter.setPen(Qt::black);
                              painter.drawText(50,50,"Information relative à l'employé");
                           painter.setPen(Qt::black);
                           painter.drawText(50,300,"id : " + id_string);
                           painter.drawText(50,400,"nom  : "+nom_string);
                           painter.drawText(50,500,"prenom   : "+ prenom_string);
                             painter.drawText(50,600,"adresse : " +adresse_string);
                             painter.drawText(50,700,"Salaire : "+salaire_string);
                             painter.drawText(50,800,"Genre : "+genre_string);
                          painter.end();
}

void MainWindow::on_pb_stat_clicked()
{
   statistiques S;
    S.setModal(true);
    S.exec();
}

void MainWindow::on_pushButton_2_clicked()
{
    widget w;
    w.exec();
}


//***************arduino ***************************
void MainWindow::concatRfid()
{
    bool found =false;
        QString nom="",RFID,msg,id;

        data =A.read_from_arduino();
        qDebug() <<"a=" << data;
        if (data!="#")
            uid+=data;
        else {
            int pos = uid.lastIndexOf(QChar('/'));
            qDebug() << "uid="<< uid.left(pos);
            qDebug()  << uid;
            QTableView tableEmploye;
            QSqlQueryModel * Mod=new  QSqlQueryModel();
            QSqlQuery qry;
            qry.prepare("select * from EMPLOYEE");
            qry.exec();
            Mod->setQuery(qry);
            tableEmploye.setModel(Mod);
            const int ligne = tableEmploye.model()->rowCount();
            for (int var = 0; var < ligne; var++) {
                if(tableEmploye.model()->data(tableEmploye.model()->index(var, 7))==uid)
                {
                   id= tableEmploye.model()->data(tableEmploye.model()->index(var, 0)).toString();
                   nom= tableEmploye.model()->data(tableEmploye.model()->index(var, 1)).toString();
                   RFID = tableEmploye.model()->data(tableEmploye.model()->index(var, 7)).toString();
                   found=true;
                   var=ligne;
                }
            }
                if(found){
                    A.writeStringToArduino("bonjour");
                    qDebug()<<"bonjour "<<nom;


                }else{
                    qDebug()<<"error";
                    A.writeStringToArduino("ERROR");
                }
            uid="";
            found = false;
            //qDebug() << uid;
 }
}
