#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"ajouterpersonel.h"
#include<QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("D:/project/images/back.jpg");
    ui->labelpic->setPixmap(pix.scaled(885,595,Qt::KeepAspectRatio));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{  if((ui->pseudo->text()=="mohsen")&&(ui->motdepasse->text()=="mohsen"))
    {
        Ajouterpersonel a;
        a.show();
        MainWindow::hide();
        a.exec();
    }
}


