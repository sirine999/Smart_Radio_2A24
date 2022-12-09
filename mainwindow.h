#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "employee.h"
#include <QMainWindow>
#include <QDebug>
#include <QMessageBox>
#include "statistiques.h"



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
    void on_pb_ajout_em_clicked();

    void on_pb_modif_emp_clicked();

    void on_pb_supprimer_employe_clicked();

    bool controlSalaire(int test);

    bool controlId(int test);

    bool controlVide(QString test);

    bool controlEmail(QString test);



      void on_pushButton_5_clicked();

      void on_pushButton_10_clicked();

      void on_pushButton_11_clicked();

      void on_cb_id_modif_activated(const QString &arg1);

      void on_search_pb_clicked();

      void on_cb_tri_activated(const QString &arg1);

      void on_pushButton_clicked();

      void on_pb_stat_clicked();

      void on_pushButton_2_clicked();

      void concatRfid();

private:
    Ui::MainWindow *ui;
    Employee C;
    QByteArray data;
        arduino A;
        QString uid;
};
#endif // MAINWINDOW_H
