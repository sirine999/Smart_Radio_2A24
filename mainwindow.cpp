#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tab_emp->setModel(C.afficher());
    ui->cb_id_supp->setModel(C.getAllId());
    ui->cb_id_modif->setModel(C.getAllId());
    ui->le_id->setValidator(new QIntValidator(100000, 999999, this));
    ui->le_salaire->setValidator(new QIntValidator(1000, 9999, this));

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
        if(test)
        {
            QMessageBox::information(nullptr, QObject::tr("ajouter un employé"),
                                       QObject::tr("employé ajouté.\n"
                                                   "Click Cancel to exit."), QMessageBox::Cancel);
            ui->tab_emp->setModel(C.afficher());
            ui->cb_id_supp->setModel(C.getAllId());
            ui->cb_id_modif->setModel(C.getAllId());


        }
        }else
    { QMessageBox::critical(nullptr, QObject::tr("ajouter un employé"),
                               QObject::tr("employé non ajouté, vérifier les champs.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
    }
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
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("modifier un employé"),
                                   QObject::tr("employé modifié.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tab_emp->setModel(C.afficher());
        ui->cb_id_supp->setModel(C.getAllId());
        ui->cb_id_modif->setModel(C.getAllId());

    }}else
{ QMessageBox::information(nullptr, QObject::tr("ajouter un employé"),
                           QObject::tr("employé non ajouté, vérifier les champs.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
}

}

void MainWindow::on_pb_supprimer_employe_clicked()
{
    QMessageBox msgBox;
    Employee C1;


C1.setId(ui->cb_id_supp->currentText().toInt());
        bool test=C1.supprimer(C1.getId());
    if(test)
      {  msgBox.setText("supprission avec succes.");
        ui->tab_emp->setModel(C.afficher());
        ui->cb_id_supp->setModel(C.getAllId());
        ui->cb_id_modif->setModel(C.getAllId());
    }else
    { msgBox.setText("Echec de supprission");}
        msgBox.exec();
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










void MainWindow::on_cb_id_modif_activated()
{
    QString choix=ui->cb_id_modif->currentText();


    Employee *EM;
    EM=C.reademploye(choix);
      int salairee=EM->getSalaire();
      QString salairee_string=QString::number(salairee);


            ui->le_nom_modif->setText(EM->getNom());
            ui->le_prenom_modif->setText(EM->getPrenom());
            ui->le_adresse_modif->setText(EM->getAdresse());
            ui->le_mail_modif->setText(EM->getMail());
            ui->le_salaire_modif->setText(salairee_string);
            ui->cb_genre->setCurrentText(EM->getGenre());
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
