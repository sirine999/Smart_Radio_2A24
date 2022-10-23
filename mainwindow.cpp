#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "TailButtonsDelegate.h"
#include "connexion.h"
#include <QSqlQuery>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(1);
    ui->tableView->setEditTriggers(QTableView::AllEditTriggers);
    ui->tableView->setSelectionBehavior(QTableView::SelectRows);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->setModel(inv.afficher(ui->rech->text(), 0));
    ui->tableView->setItemDelegateForColumn(4,new TailButtonsDelegate(ui->tableView));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_13_clicked()
{
    ui->tableView->setModel(inv.afficher(ui->rech->text(), 0));

}
