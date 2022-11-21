#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QMainWindow>
#include"materiel.h"
#include <QString>
#include <QSqlQuery>
#include<QtDebug>
#include<QObject>
#include<QDateTime>
#include<QPrinter>
#include<QPainter>
#include<QtCharts>
#include<QChartView>
#include"calculer.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void stat();
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_modif_clicked();



    void on_pushButton_trie_clicked();

    void on_pushButton_Recherche_clicked();

    void on_tab_materiel_activated(const QModelIndex &index);

    int on_pdf_clicked();




    void on_pb_qr_clicked();

    void on_inserer_image_clicked();



    int on_pb_pdf1_clicked();



    void on_calcul_clicked();

private:
    Ui::MainWindow *ui;
    Materiel m;
    Calculer *calc;

};

#endif // MAINWINDOW_H
