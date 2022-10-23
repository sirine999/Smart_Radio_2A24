#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "invite.h"
#include "TailButtonsDelegate.h"

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


    void on_pushButton_13_clicked();

private:
    Ui::MainWindow *ui;
    invite  inv;
    //Profils P;
    //int nextScene = 3;
    int mref;
    QByteArray data;
    //Arduino A;
};
#endif // MAINWINDOW_H
