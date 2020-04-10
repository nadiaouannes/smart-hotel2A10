#include "home.h"
#include "ui_home.h"
#include "ajouterpersonel.h"
#include "gestion_formulaire.h"
#include<QPixmap>

Home::Home(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Home)
{
    ui->setupUi(this);
    QPixmap pix("D:/project/images/back.jpg");
    ui->labelpic2->setPixmap(pix.scaled(1031,601,Qt::KeepAspectRatio));

}

Home::~Home()
{
    delete ui;
}

void Home::on_pushButton_13_clicked()
{
Ajouterpersonel ajouterpersonel;
ajouterpersonel.setModal(true);
ajouterpersonel.exec();
}


void Home::on_pushButton_14_clicked()
{
  Gestion_formulaire gestion;
  gestion.setModal(true);
  gestion.exec();
}
