#include "signin.h"
#include "ui_signin.h"
#include "choix.h"
#include "mainwindow.h"
#include <QSqlQuery>
#include <QMessageBox>
#include<QMediaPlayer>
#include<QPixmap>
#include<QtWidgets>

signin::signin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::signin)
{
    ui->setupUi(this);



    QPixmap p("C:/Users/ASUS/Desktop/QT/parc.jpg");
    ui->label_parc->setPixmap(p.scaled(281,281,Qt::KeepAspectRatio));

    QPixmap pa("C:/Users/ASUS/Desktop/QT/retour.png");
    ui->label->setPixmap(pa.scaled(181,91,Qt::KeepAspectRatio));
}

signin::~signin()
{
    delete ui;
}



void signin::on_pushButton_2_clicked()
{
    QSqlQuery query;
    query.prepare("SELECT * FROM LOGIN WHERE USERNAME=\'"+ui->lineEdit_username->text()+"\' AND PASSWORD=\'"+ui->lineEdit_password->text()+"\'");
     query.exec();

     QMediaPlayer * music = new QMediaPlayer();
     music->setMedia(QUrl("qrc:/img/img/button16.wav"));
     music->play();

       if(query.next())
       {

       QMessageBox::information(nullptr, QObject::tr("Login correcte"),
           QObject::tr("connection successful.\n"
                       "Click Cancel to exit."), QMessageBox::Cancel);
    choix g;
    g.setModal(this);
    g.exec();
    close();


   }
       else
           QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                       QObject::tr("connection failed\n\nusername or password incorrect.\n\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
}

void signin::on_pushButton_clicked()
{
    close();
}

