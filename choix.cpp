#include "choix.h"
#include "ui_choix.h"
#include "perso.h"
#include "client.h"
#include<QtWidgets>

choix::choix(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::choix)
{
    ui->setupUi(this);

    QPixmap pa("C:/Users/ASUS/Desktop/QT/retour.png");
    ui->label_2->setPixmap(pa.scaled(181,91,Qt::KeepAspectRatio));
}

choix::~choix()
{
    delete ui;
}

void choix::on_pushButton_3_clicked()
{
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
    notifyIcon->show();
    notifyIcon->setIcon(QIcon("icone.png"));

    notifyIcon->showMessage("parking","GOODBYE",QSystemTrayIcon::Information,15000);
    hide();

}

void choix::on_pushButton_2_clicked()
{
    perso x;
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
    notifyIcon->show();
    notifyIcon->setIcon(QIcon("icone.png"));

    notifyIcon->showMessage("GESTION PARKING  PERSONNELS ","bienvenue",QSystemTrayIcon::Information,15000);
    x.setModal(this);
    x.exec();

}

void choix::on_pushButton_clicked()
{
    client x;
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
    notifyIcon->show();
    notifyIcon->setIcon(QIcon("icone.png"));

    notifyIcon->showMessage("GESTION PARKING  CLIENTS ","bienvenue",QSystemTrayIcon::Information,15000);
    x.setModal(this);
    x.exec();

}
