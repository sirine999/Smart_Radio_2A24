/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab_5;
    QGroupBox *groupBox_10;
    QLineEdit *ID;
    QLabel *label_12;
    QLabel *label_27;
    QSpinBox *Duree;
    QLabel *label_29;
    QLineEdit *nomPresentateur;
    QLabel *label_31;
    QLabel *label_32;
    QSpinBox *Nbreinvites;
    QPushButton *ajouter;
    QDateEdit *Date_Prog;
    QLabel *label_16;
    QLineEdit *nomProg;
    QLabel *label_13;
    QLineEdit *typeProg;
    QLineEdit *Le_rech;
    QComboBox *comboBox_recherche;
    QLabel *label_17;
    QPushButton *Rechercher;
    QGroupBox *groupBox_4;
    QTableView *TableauAffichage;
    QPushButton *Trier;
    QPushButton *Modifier;
    QPushButton *Supprimer;
    QPushButton *ImporterPDF;
    QComboBox *comboBox_tri;
    QLabel *label_19;
    QPushButton *Quitter;
    QLabel *label_3;
    QWidget *tab;
    QGroupBox *groupBox;
    QFrame *horizontalFrame;
    QHBoxLayout *horizontalLayout;
    QPushButton *Quitter_2;
    QWidget *tab_7;
    QGroupBox *groupBox_2;
    QTextBrowser *Histo;
    QPushButton *HISTORIQUE;
    QPushButton *Quitter_3;
    QWidget *tab_8;
    QGroupBox *groupBox_6;
    QLineEdit *file;
    QPushButton *sendBtn;
    QPushButton *browseBtn;
    QLineEdit *rcpt;
    QLineEdit *mail_pass;
    QTextEdit *msg;
    QLineEdit *subject;
    QPushButton *Quitter_4;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menuGestion_des_Programmes;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1310, 703);
        MainWindow->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 0);\n"
"color: rgb(255, 255, 255);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setEnabled(true);
        tabWidget->setGeometry(QRect(40, 10, 1241, 671));
        tabWidget->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 0);\n"
"color: rgb(255, 255, 255);\n"
""));
        tabWidget->setTabShape(QTabWidget::Triangular);
        tabWidget->setElideMode(Qt::ElideNone);
        tabWidget->setUsesScrollButtons(true);
        tabWidget->setDocumentMode(false);
        tabWidget->setTabBarAutoHide(false);
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        groupBox_10 = new QGroupBox(tab_5);
        groupBox_10->setObjectName(QStringLiteral("groupBox_10"));
        groupBox_10->setGeometry(QRect(10, 9, 1211, 171));
        groupBox_10->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 0);\n"
"color: rgb(255, 255, 255);"));
        ID = new QLineEdit(groupBox_10);
        ID->setObjectName(QStringLiteral("ID"));
        ID->setGeometry(QRect(10, 52, 211, 30));
        ID->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        label_12 = new QLabel(groupBox_10);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(10, 26, 120, 17));
        QFont font;
        font.setFamily(QStringLiteral("Berlin Sans FB"));
        font.setPointSize(9);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        label_12->setFont(font);
        label_27 = new QLabel(groupBox_10);
        label_27->setObjectName(QStringLiteral("label_27"));
        label_27->setGeometry(QRect(10, 100, 231, 17));
        label_27->setFont(font);
        Duree = new QSpinBox(groupBox_10);
        Duree->setObjectName(QStringLiteral("Duree"));
        Duree->setGeometry(QRect(10, 130, 211, 30));
        Duree->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        label_29 = new QLabel(groupBox_10);
        label_29->setObjectName(QStringLiteral("label_29"));
        label_29->setGeometry(QRect(260, 100, 130, 17));
        label_29->setFont(font);
        nomPresentateur = new QLineEdit(groupBox_10);
        nomPresentateur->setObjectName(QStringLiteral("nomPresentateur"));
        nomPresentateur->setGeometry(QRect(510, 130, 211, 30));
        nomPresentateur->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        label_31 = new QLabel(groupBox_10);
        label_31->setObjectName(QStringLiteral("label_31"));
        label_31->setGeometry(QRect(510, 100, 145, 17));
        label_31->setFont(font);
        label_32 = new QLabel(groupBox_10);
        label_32->setObjectName(QStringLiteral("label_32"));
        label_32->setGeometry(QRect(760, 26, 116, 17));
        label_32->setFont(font);
        Nbreinvites = new QSpinBox(groupBox_10);
        Nbreinvites->setObjectName(QStringLiteral("Nbreinvites"));
        Nbreinvites->setGeometry(QRect(760, 52, 120, 30));
        Nbreinvites->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        ajouter = new QPushButton(groupBox_10);
        ajouter->setObjectName(QStringLiteral("ajouter"));
        ajouter->setEnabled(true);
        ajouter->setGeometry(QRect(760, 130, 120, 30));
        QFont font1;
        font1.setFamily(QStringLiteral("News701 BT"));
        font1.setPointSize(8);
        font1.setBold(true);
        font1.setItalic(false);
        font1.setWeight(75);
        ajouter->setFont(font1);
        ajouter->setStyleSheet(QLatin1String("background-color: rgb(255, 170, 0);\n"
"color: rgb(0, 0, 0);"));
        Date_Prog = new QDateEdit(groupBox_10);
        Date_Prog->setObjectName(QStringLiteral("Date_Prog"));
        Date_Prog->setGeometry(QRect(260, 130, 211, 30));
        Date_Prog->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        label_16 = new QLabel(groupBox_10);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(260, 26, 141, 17));
        label_16->setFont(font);
        nomProg = new QLineEdit(groupBox_10);
        nomProg->setObjectName(QStringLiteral("nomProg"));
        nomProg->setGeometry(QRect(260, 52, 211, 30));
        nomProg->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        label_13 = new QLabel(groupBox_10);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(510, 26, 143, 17));
        label_13->setFont(font);
        typeProg = new QLineEdit(groupBox_10);
        typeProg->setObjectName(QStringLiteral("typeProg"));
        typeProg->setGeometry(QRect(510, 52, 211, 30));
        typeProg->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        Le_rech = new QLineEdit(groupBox_10);
        Le_rech->setObjectName(QStringLiteral("Le_rech"));
        Le_rech->setGeometry(QRect(1090, 70, 100, 22));
        Le_rech->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        comboBox_recherche = new QComboBox(groupBox_10);
        comboBox_recherche->setObjectName(QStringLiteral("comboBox_recherche"));
        comboBox_recherche->setGeometry(QRect(960, 70, 100, 22));
        comboBox_recherche->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        label_17 = new QLabel(groupBox_10);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(1020, 30, 120, 17));
        label_17->setFont(font);
        label_17->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        Rechercher = new QPushButton(groupBox_10);
        Rechercher->setObjectName(QStringLiteral("Rechercher"));
        Rechercher->setGeometry(QRect(1020, 110, 120, 30));
        QFont font2;
        font2.setFamily(QStringLiteral("Berlin Sans FB"));
        font2.setPointSize(9);
        font2.setBold(false);
        font2.setWeight(50);
        Rechercher->setFont(font2);
        Rechercher->setStyleSheet(QLatin1String("background-color: rgb(255, 170, 0);\n"
"color: rgb(0, 0, 0);"));
        groupBox_4 = new QGroupBox(tab_5);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(10, 180, 1211, 371));
        groupBox_4->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 0);\n"
"color: rgb(255, 255, 255);"));
        TableauAffichage = new QTableView(groupBox_4);
        TableauAffichage->setObjectName(QStringLiteral("TableauAffichage"));
        TableauAffichage->setGeometry(QRect(10, 20, 1021, 331));
        TableauAffichage->setStyleSheet(QLatin1String("background-color: rgb(255, 170, 0);\n"
"color: rgb(0, 0, 0);"));
        Trier = new QPushButton(groupBox_4);
        Trier->setObjectName(QStringLiteral("Trier"));
        Trier->setGeometry(QRect(1050, 110, 120, 30));
        Trier->setFont(font2);
        Trier->setStyleSheet(QLatin1String("background-color: rgb(255, 170, 0);\n"
"color: rgb(0, 0, 0);"));
        Modifier = new QPushButton(groupBox_4);
        Modifier->setObjectName(QStringLiteral("Modifier"));
        Modifier->setGeometry(QRect(1050, 160, 120, 30));
        Modifier->setFont(font2);
        Modifier->setStyleSheet(QLatin1String("background-color: rgb(255, 170, 0);\n"
"color: rgb(0, 0, 0);"));
        Supprimer = new QPushButton(groupBox_4);
        Supprimer->setObjectName(QStringLiteral("Supprimer"));
        Supprimer->setGeometry(QRect(1050, 210, 120, 30));
        Supprimer->setFont(font2);
        Supprimer->setStyleSheet(QLatin1String("background-color: rgb(255, 170, 0);\n"
"color: rgb(0, 0, 0);"));
        ImporterPDF = new QPushButton(groupBox_4);
        ImporterPDF->setObjectName(QStringLiteral("ImporterPDF"));
        ImporterPDF->setGeometry(QRect(1050, 260, 120, 30));
        ImporterPDF->setFont(font2);
        ImporterPDF->setStyleSheet(QLatin1String("background-color: rgb(255, 170, 0);\n"
"color: rgb(0, 0, 0);"));
        comboBox_tri = new QComboBox(groupBox_4);
        comboBox_tri->setObjectName(QStringLiteral("comboBox_tri"));
        comboBox_tri->setGeometry(QRect(1090, 70, 100, 22));
        comboBox_tri->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        label_19 = new QLabel(groupBox_4);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(1050, 30, 120, 17));
        label_19->setFont(font);
        label_19->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        Quitter = new QPushButton(groupBox_4);
        Quitter->setObjectName(QStringLiteral("Quitter"));
        Quitter->setGeometry(QRect(1050, 310, 120, 30));
        Quitter->setFont(font2);
        Quitter->setStyleSheet(QLatin1String("background-color: rgb(255, 170, 0);\n"
"color: rgb(0, 0, 0);"));
        label_3 = new QLabel(tab_5);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(130, 590, 56, 16));
        QIcon icon;
        icon.addFile(QStringLiteral("../../../Desktop/programmation-web.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tab_5, icon, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 1211, 541));
        horizontalFrame = new QFrame(groupBox);
        horizontalFrame->setObjectName(QStringLiteral("horizontalFrame"));
        horizontalFrame->setGeometry(QRect(280, 30, 641, 491));
        horizontalFrame->setStyleSheet(QLatin1String("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);"));
        horizontalLayout = new QHBoxLayout(horizontalFrame);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        Quitter_2 = new QPushButton(groupBox);
        Quitter_2->setObjectName(QStringLiteral("Quitter_2"));
        Quitter_2->setGeometry(QRect(1080, 500, 120, 30));
        Quitter_2->setFont(font2);
        Quitter_2->setStyleSheet(QLatin1String("background-color: rgb(255, 170, 0);\n"
"color: rgb(0, 0, 0);"));
        QIcon icon1;
        icon1.addFile(QStringLiteral("../../../Desktop/statistiques.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tab, icon1, QString());
        tab_7 = new QWidget();
        tab_7->setObjectName(QStringLiteral("tab_7"));
        groupBox_2 = new QGroupBox(tab_7);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(70, 50, 1101, 461));
        Histo = new QTextBrowser(groupBox_2);
        Histo->setObjectName(QStringLiteral("Histo"));
        Histo->setGeometry(QRect(70, 40, 961, 321));
        Histo->setStyleSheet(QLatin1String("background-color: rgb(255, 170, 0);\n"
"color: rgb(0, 0, 0);"));
        HISTORIQUE = new QPushButton(groupBox_2);
        HISTORIQUE->setObjectName(QStringLiteral("HISTORIQUE"));
        HISTORIQUE->setGeometry(QRect(460, 380, 191, 30));
        HISTORIQUE->setFont(font2);
        HISTORIQUE->setStyleSheet(QLatin1String("background-color: rgb(255, 170, 0);\n"
"color: rgb(0, 0, 0);"));
        Quitter_3 = new QPushButton(groupBox_2);
        Quitter_3->setObjectName(QStringLiteral("Quitter_3"));
        Quitter_3->setGeometry(QRect(970, 420, 120, 30));
        Quitter_3->setFont(font2);
        Quitter_3->setStyleSheet(QLatin1String("background-color: rgb(255, 170, 0);\n"
"color: rgb(0, 0, 0);"));
        QIcon icon2;
        icon2.addFile(QStringLiteral("../../../Desktop/history.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tab_7, icon2, QString());
        tab_8 = new QWidget();
        tab_8->setObjectName(QStringLiteral("tab_8"));
        groupBox_6 = new QGroupBox(tab_8);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        groupBox_6->setGeometry(QRect(120, 20, 1001, 521));
        file = new QLineEdit(groupBox_6);
        file->setObjectName(QStringLiteral("file"));
        file->setGeometry(QRect(150, 106, 561, 23));
        file->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        sendBtn = new QPushButton(groupBox_6);
        sendBtn->setObjectName(QStringLiteral("sendBtn"));
        sendBtn->setGeometry(QRect(150, 440, 691, 31));
        sendBtn->setStyleSheet(QLatin1String("background-color: rgb(255, 170, 0);\n"
"color: rgb(0, 0, 0);"));
        sendBtn->setIconSize(QSize(30, 90));
        browseBtn = new QPushButton(groupBox_6);
        browseBtn->setObjectName(QStringLiteral("browseBtn"));
        browseBtn->setGeometry(QRect(720, 105, 121, 24));
        browseBtn->setStyleSheet(QLatin1String("background-color: rgb(255, 170, 0);\n"
"color: rgb(0, 0, 0);"));
        rcpt = new QLineEdit(groupBox_6);
        rcpt->setObjectName(QStringLiteral("rcpt"));
        rcpt->setGeometry(QRect(150, 36, 491, 21));
        rcpt->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        mail_pass = new QLineEdit(groupBox_6);
        mail_pass->setObjectName(QStringLiteral("mail_pass"));
        mail_pass->setGeometry(QRect(662, 36, 181, 20));
        mail_pass->setStyleSheet(QLatin1String("background-color: rgb(255, 170, 0);\n"
"color: rgb(0, 0, 0);"));
        mail_pass->setEchoMode(QLineEdit::Password);
        msg = new QTextEdit(groupBox_6);
        msg->setObjectName(QStringLiteral("msg"));
        msg->setGeometry(QRect(150, 142, 691, 291));
        msg->setStyleSheet(QLatin1String("background-color: rgb(255, 170, 0);\n"
"color: rgb(0, 0, 0);"));
        subject = new QLineEdit(groupBox_6);
        subject->setObjectName(QStringLiteral("subject"));
        subject->setGeometry(QRect(150, 70, 691, 16));
        subject->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        Quitter_4 = new QPushButton(groupBox_6);
        Quitter_4->setObjectName(QStringLiteral("Quitter_4"));
        Quitter_4->setGeometry(QRect(150, 480, 691, 31));
        Quitter_4->setStyleSheet(QLatin1String("background-color: rgb(255, 170, 0);\n"
"color: rgb(0, 0, 0);"));
        QIcon icon3;
        icon3.addFile(QStringLiteral("../../../Desktop/email.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tab_8, icon3, QString());
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1310, 26));
        menuGestion_des_Programmes = new QMenu(menubar);
        menuGestion_des_Programmes->setObjectName(QStringLiteral("menuGestion_des_Programmes"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuGestion_des_Programmes->menuAction());

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        groupBox_10->setTitle(QApplication::translate("MainWindow", "Cr\303\251er un Programme", Q_NULLPTR));
        ID->setText(QString());
        label_12->setText(QApplication::translate("MainWindow", "ID du programme :", Q_NULLPTR));
        label_27->setText(QApplication::translate("MainWindow", "Dur\303\251e du programme (en minutes) :", Q_NULLPTR));
        label_29->setText(QApplication::translate("MainWindow", "Date de lancement  :", Q_NULLPTR));
        nomPresentateur->setText(QString());
        label_31->setText(QApplication::translate("MainWindow", "Nom du pr\303\251sentateur  :", Q_NULLPTR));
        label_32->setText(QApplication::translate("MainWindow", "Nombre d'invit\303\251s  :", Q_NULLPTR));
        ajouter->setText(QApplication::translate("MainWindow", "Ajouter", Q_NULLPTR));
        label_16->setText(QApplication::translate("MainWindow", "Nom du programme  :", Q_NULLPTR));
        nomProg->setText(QString());
        label_13->setText(QApplication::translate("MainWindow", "Type de programme  : ", Q_NULLPTR));
        typeProg->setText(QString());
        Le_rech->setText(QString());
        comboBox_recherche->clear();
        comboBox_recherche->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "ID", Q_NULLPTR)
         << QApplication::translate("MainWindow", "nomProg", Q_NULLPTR)
         << QApplication::translate("MainWindow", "nomPresentateur", Q_NULLPTR)
        );
        label_17->setText(QApplication::translate("MainWindow", "Rechercher :", Q_NULLPTR));
        Rechercher->setText(QApplication::translate("MainWindow", "Rechercher", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Afficher un programme", Q_NULLPTR));
        Trier->setText(QApplication::translate("MainWindow", "Trier", Q_NULLPTR));
        Modifier->setText(QApplication::translate("MainWindow", "Modifier", Q_NULLPTR));
        Supprimer->setText(QApplication::translate("MainWindow", "Supprimer", Q_NULLPTR));
        ImporterPDF->setText(QApplication::translate("MainWindow", "Importer PDF", Q_NULLPTR));
        comboBox_tri->clear();
        comboBox_tri->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "nomProg", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Nbreinvites", Q_NULLPTR)
         << QApplication::translate("MainWindow", "ID", Q_NULLPTR)
        );
        label_19->setText(QApplication::translate("MainWindow", "Trier :", Q_NULLPTR));
        Quitter->setText(QApplication::translate("MainWindow", "Quitter", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("MainWindow", "Programmes", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "Statistiques", Q_NULLPTR));
        Quitter_2->setText(QApplication::translate("MainWindow", "Quitter", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Statistiques", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Historique", Q_NULLPTR));
        HISTORIQUE->setText(QApplication::translate("MainWindow", "Afficher Historique", Q_NULLPTR));
        Quitter_3->setText(QApplication::translate("MainWindow", "Quitter", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_7), QApplication::translate("MainWindow", "Historique", Q_NULLPTR));
        groupBox_6->setTitle(QApplication::translate("MainWindow", "Mailing", Q_NULLPTR));
        file->setText(QString());
        file->setPlaceholderText(QApplication::translate("MainWindow", "Parcourir votre pi\303\250ce jointe ", Q_NULLPTR));
        sendBtn->setText(QApplication::translate("MainWindow", "Send", Q_NULLPTR));
        browseBtn->setText(QApplication::translate("MainWindow", "Parcourir...", Q_NULLPTR));
        rcpt->setText(QString());
        rcpt->setPlaceholderText(QApplication::translate("MainWindow", "Destination", Q_NULLPTR));
        mail_pass->setPlaceholderText(QApplication::translate("MainWindow", "mot de passe de votre mail", Q_NULLPTR));
        msg->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2';\"><br /></p></body></html>", Q_NULLPTR));
        msg->setPlaceholderText(QApplication::translate("MainWindow", "Taper votre message ici ...", Q_NULLPTR));
        subject->setText(QString());
        subject->setPlaceholderText(QApplication::translate("MainWindow", "Sujet", Q_NULLPTR));
        Quitter_4->setText(QApplication::translate("MainWindow", "Quitter", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_8), QApplication::translate("MainWindow", "Mailing", Q_NULLPTR));
        menuGestion_des_Programmes->setTitle(QApplication::translate("MainWindow", "Gestion des Programmes", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
