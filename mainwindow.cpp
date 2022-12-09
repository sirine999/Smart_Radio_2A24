#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pub.h"
#include "exportexcelobject.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QFileDialog>
#include <QtPrintSupport/QPrinter>
#include <QPaintDevice>
#include <QPainter>
#include <QTextStream>
#include <QTextDocument>
#include <QMediaPlayer>
#include <QVideoWidget>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),ui(new Ui::MainWindow)
{
    ui->setupUi(this);
     ui->tableView->setModel(pub.afficher());


   pub.stat(series,ui->horizontalFrame);
     ui->le_id->setValidator (new QIntValidator(0, 9999, this));
     ui->passage->setValidator (new QIntValidator(1, 6, this));
     ui->tableView->setModel(pub.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_pb_ajouter_clicked()
{
    int id_pub=ui->le_id->text().toInt();
    QString nom_produit=ui->le_nomP->text();
    QString nom_entreprise=ui->le_nomE->text();
    QString type_produit=ui->le_type->text();
    int passage=ui->passage->text().toInt();
    QString horraire=ui->time->text();
    QString horraire1=ui->time1->text();
    QString horraire2=ui->time2->text();
    QString horraire3=ui->time3->text();
    QString horraire4=ui->time4->text();
    QString horraire5=ui->time5->text();
    QString duree=ui->date->text();
    QString duree1=ui->date1->text();
    int prix=ui->prix->text().toFloat();



    Pub   p(id_pub,nom_produit,nom_entreprise,type_produit,passage,horraire,horraire1,horraire2,horraire3,horraire4,horraire5,duree,duree1,prix);
bool test=p.ajouter();

if (test)
{ pub.stat(series,ui->horizontalFrame);
    ui->tableView->setModel(pub.afficher());
    QMessageBox::information(nullptr ,QObject::tr("OK"),
            QObject::tr("Ajout effectué\n"
                        "Click cancel to exit."),QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                          QObject::tr("Ajout non effectué. \n"
                                      "Click cancel to exit."), QMessageBox::Cancel);
}


void MainWindow::on_pb_supprimer_clicked()
{
    Pub pub;
    pub.setid(ui->lineEdit->text().toInt());

    bool test=pub.supprimer(pub.getid());
    if(test)
    {
 pub.stat(series,ui->horizontalFrame);
        QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("suppression effectuée\n"
                                              "Click Cancel to exit."),QMessageBox::Cancel);
    }
    else

        QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                                 QObject::tr("suppression non effectuée\n"
                                              "Click Cancel to exit."),QMessageBox::Cancel);



}


void MainWindow::on_pb_modifier_clicked()
{
    int id_pub=ui->le_id->text().toInt();
    QString nom_produit=ui->le_nomP->text();
    QString nom_entreprise=ui->le_nomE->text();
    QString type_produit=ui->le_type->text();
    int passage=ui->passage->text().toInt();
    QString horraire=ui->time->text();
    QString horraire1=ui->time1->text();
    QString horraire2=ui->time2->text();
    QString horraire3=ui->time3->text();
    QString horraire4=ui->time4->text();
    QString horraire5=ui->time5->text();
    QString duree=ui->date->text();
    QString duree1=ui->date1->text();
    int prix=ui->prix->text().toFloat();
    Pub   p(id_pub,nom_produit,nom_entreprise,type_produit,passage,horraire,horraire1,horraire2,horraire3,horraire4,horraire5,duree,duree1,prix);
    bool test=p.modifier();
     if(test)
     { pub.stat(series,ui->horizontalFrame);
         ui->tableView->setModel(pub.afficher());
         QMessageBox::information(nullptr,QObject::tr("OK"),
                               QObject::tr("Modification effectué\n""Click Cancel to exit."),QMessageBox::Cancel);
     }
     else
         QMessageBox::critical(nullptr,QObject::tr(" NOT OK"),
                                   QObject::tr("Modification non effectué\n""Click Cancel to exit."),QMessageBox::Cancel);

}




void MainWindow::on_pushButton_clicked()
{
    ui->tableView->setModel(pub.afficher());
}

void MainWindow::on_pushButton_2_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                        tr("Excel Files (*.xls)"));
        if (fileName.isEmpty())
            return;

        ExportExcelObject obj(fileName, "mydata", ui->tableView);

        //colums to export
        obj.addField(0, "le_id", "char(20)");
        obj.addField(1, "le_nomP", "char(20)");
        obj.addField(2, "le_nomE", "char(20)");
        obj.addField(3, "le_type", "char(20)");
        obj.addField(4, "passage", "char(20)");
        obj.addField(5, "time", "char(20)");
        obj.addField(5, "time1", "char(20)");
        obj.addField(5, "time2", "char(20)");
        obj.addField(5, "time3", "char(20)");
        obj.addField(5, "time4", "char(20)");
        obj.addField(5, "time5", "char(20)");
        obj.addField(6, "date", "char(20)");
        obj.addField(6, "date1", "char(20)");
        obj.addField(7, "prix", "char(20)");

        int retVal = obj.export2Excel();
        if( retVal > 0)
        {
            QMessageBox::information(this, tr("Done"),
                                     QString(tr("%1 records exported!")).arg(retVal)
                                     );
        }

}
void MainWindow::on_lineEdit_9_textChanged(const QString )
{
    Pub pub;
            if(ui->lineEdit_9->text() == "")
                {
                    ui->tableView->setModel(pub.afficher());
                }
                else
                {
                     ui->tableView->setModel(pub.rechercher(ui->lineEdit_9->text()));
                }
}


void MainWindow::on_pushButton_3_clicked()
{
    QString strStream;
                   QTextStream out(&strStream);

                    const int rowCount = ui->tableView->model()->rowCount();
                    const int columnCount = ui->tableView->model()->columnCount();
                   out <<  "<html>\n"
                   "<head>\n"
                                    "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                                    <<  QString("<title>%1</title>\n").arg("strTitle")
                                    <<  "</head>\n"
                                    "<body bgcolor=#ffffff link=#5000A0>\n"

                                   //     "<align='right'> " << datefich << "</align>"
                                    "<center> <H1>Liste des pubs</H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                                // headers
                                out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                                out<<"<cellspacing=10 cellpadding=3>";
                                for (int column = 0; column < columnCount; column++)
                                    if (!ui->tableView->isColumnHidden(column))
                                        out << QString("<th>%1</th>").arg(ui->tableView->model()->headerData(column, Qt::Horizontal).toString());
                                out << "</tr></thead>\n";

                                // data table
                                for (int row = 0; row < rowCount; row++) {
                                    out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                                    for (int column = 0; column < columnCount; column++) {
                                        if (!ui->tableView->isColumnHidden(column)) {
                                            QString data = ui->tableView->model()->data(ui->tableView->model()->index(row, column)).toString().simplified();
                                            out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                        }
                                    }
                                    out << "</tr>\n";
                                }
                                out <<  "</table> </center>\n"
                                    "</body>\n"
                                    "</html>\n";

                          QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
                            if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

                           QPrinter printer (QPrinter::PrinterResolution);
                            printer.setOutputFormat(QPrinter::PdfFormat);
                           printer.setPaperSize(QPrinter::A4);
                          printer.setOutputFileName(fileName);

                           QTextDocument doc;
                            doc.setHtml(strStream);
                            doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
                            doc.print(&printer);
}

void MainWindow::on_pushButton_4_clicked()
{

}

void MainWindow::on_pushButton_5_clicked()
{
    QMediaPlayer *player=new QMediaPlayer;
    QVideoWidget *VW=new QVideoWidget;
    player->setVideoOutput(VW);
    player->setMedia(QUrl::fromLocalFile("C:/cpt.mpg"));
    VW->setGeometry(100,100,300,400);
    VW->show();
    player->play();
}

