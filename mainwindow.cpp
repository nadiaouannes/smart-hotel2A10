#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "signin.h"
#include <QPixmap>
#include <QMessageBox>
#include <QMediaPlayer>
#include <QSystemTrayIcon>
#include <QSqlQueryModel>
#include  "QSqlQuery"
#include<QtWidgets>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/ASUS/Desktop/QT/fond2.jpg");
    ui->label_pic->setPixmap(pix.scaled(901,631,Qt::KeepAspectRatio));

    QPixmap p("C:/Users/ASUS/Desktop/QT/parc.jpg");
    ui->label_parc->setPixmap(p.scaled(281,281,Qt::KeepAspectRatio));

    QPixmap ps("C:/Users/ASUS/Desktop/QT/start1.png");
    ui->label_start->setPixmap(ps.scaled(131,51,Qt::KeepAspectRatio));

    QPixmap pq("C:/Users/ASUS/Desktop/QT/quitter.png");
    ui->label_quitter->setPixmap(pq.scaled(131,51,Qt::KeepAspectRatio));

    QPixmap pb("C:/Users/ASUS/Desktop/QT/bienvenue.png");
    ui->bb->setPixmap(pb.scaled(811,171,Qt::KeepAspectRatio));

    QSqlQuery * query = new QSqlQuery();
    QSqlQueryModel * model = new QSqlQueryModel();


     query->prepare("SELECT * FROM VEHICULE");
     query->exec();
     model->setQuery(*query);


     if(model->rowCount()<11)
     {
          ui->label_2->setText("Disponible");
     }
     else
     {

         ui->label_2->setText("Plein");
     }

     query->prepare("SELECT * FROM ABONNE");
     query->exec();
     model->setQuery(*query);
     if(model->rowCount()>10)
     {
         ui->label_4->setText("Disponible");
     }
     else
     {
         ui->label_4->setText("Plein");

     }




}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_pushButton_start_clicked()
{
    signin x;
    x.setModal(this);
    x.exec();
}

void MainWindow::on_pushButton_quitter_clicked()
{
    notifier = new QSystemTrayIcon(this);
    notifier->setIcon(QIcon("notification.png"));
    notifier->show();
    notifier->showMessage("Au revoir","Le programme fut fermée",QSystemTrayIcon::Information,10000);

}


