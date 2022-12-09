#include "login.h"
#include "ui_login.h"
#include <QDebug>
#include <qdebug.h>
Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::on_pb_login_clicked()
{
       QString login, Password , role;
      login =ui->le_login->text();
       Password=ui->le_password->text();

       Admin A1(login,Password,role);//construc
    bool test=A1.Login();
    if((test))
      {
        ui->le_status->setText("[+]Valid username and password ");
       QThread::sleep(3);//attendre 3 secondes avant fermer la fenetre
        close();
        MainWindow* M= new MainWindow(this);
        M->show();


       }
    else {
          ui->le_status->setText("wrong username or password");
         }



}

void Login::on_pb_clear_clicked()
{
    ui->le_password->setText("");
    ui->le_login->setText("");
}
