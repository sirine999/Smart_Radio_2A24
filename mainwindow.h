#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "pub.h"
#include <QMainWindow>
#include <QSortFilterProxyModel>

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

    void on_pb_ajouter_clicked();
    void on_pb_supprimer_clicked();
    void on_pb_modifier_clicked();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_lineEdit_9_textChanged(const QString );


    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
    Pub pub ;
    QPieSeries *series=new QPieSeries();
};

#endif // MAINWINDOW_H
