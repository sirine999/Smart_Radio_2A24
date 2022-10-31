#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QMainWindow>
#include"materiel.h"

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
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_modif_clicked();



    void on_pushButton_trie_clicked();

    void on_pushButton_Recherche_clicked();

    void on_tab_materiel_activated(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    Materiel m;
};

#endif // MAINWINDOW_H
