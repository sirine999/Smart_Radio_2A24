#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QSqlError>
#include <QSqlQuery>
#include <QMainWindow>
#include "gprogrammes.h"
#include <QString>
#include <QSqlQuery>
#include<QtDebug>
#include<QObject>
#include<QPrinter>
#include<QPainter>
#include<QtCharts>
#include<QChartView>
#include <QFile>
#include "smtp.h"
#include "arduino.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void update_label();   // slot permettant la mise à jour du label état de la lampe 1,
    // ce slot est lancé à chaque réception d'un message de Arduino


    void on_ajouter_clicked();

    void on_Supprimer_clicked();

    void on_Modifier_clicked();

    void on_TableauAffichage_activated(const QModelIndex &index);

    void on_Trier_clicked();

    int on_ImporterPDF_clicked();

    void on_Rechercher_clicked();

    void sendMail();

    void mailSent(QString);

    void browse();

    void on_HISTORIQUE_clicked();


    void on_Quitter_clicked();

    void on_Quitter_2_clicked();

    void on_Quitter_3_clicked();

    void on_Quitter_4_clicked();

private:
    Ui::MainWindow *ui;
    GProgrammes Etmp;
    QStringList files;
    QByteArray data; // variable contenant les données reçues

    Arduino A; // objet temporaire


};
#endif // MAINWINDOW_H
