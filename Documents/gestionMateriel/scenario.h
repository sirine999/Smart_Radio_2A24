#ifndef SCENARIO_H
#define SCENARIO_H
#include "arduino.h"
#include <QDialog>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDateTime>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include<QSerialPort>
#include<QSerialPortInfo>



namespace Ui {
class scenario;
}

class scenario : public QDialog
{
    Q_OBJECT

public:
    scenario(int,QString,QString);
    explicit scenario(QWidget *parent = nullptr);
     QSqlQueryModel * afficher_stock();
     bool insert_stock(int,QString,QString);
    bool supprimer(int id);
   ~scenario();

 private slots:
     void update_label();   // slot permettant la mise à jour du label état de la lampe 1,
     // ce slot est lancé à chaque réception d'un message de Arduino




private:
    Ui::scenario *ui;
    int arduino_connected;
    QByteArray data; // variable contenant les données reçues
    Arduino A; // objet temporaire
    int id;
    QString type,marque;
    scenario *sc;
};

#endif // SCENARIO_H
