#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"
#include "reservation.h"
#include <QMessageBox>
#include <QPixmap>
#include <QPainter>
#include<QSqlError>
#include <QPrinter>
#include<QPrintDialog>
#include<QPointer>
#include<QPrintPreviewDialog>
#include<QFileDialog>
#include<QTextDocument>
#include<QPaintEvent>
#include<QSqlRecord>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
ui->setupUi(this);

ui->tmpclient->setModel(tmpclient.afficher());
QPixmap pix("C:/Users/ASUS/Desktop/p/t.png");
ui->label_20->setPixmap(pix);
ui->label_22->setPixmap(pix);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
    int id = ui->text_id->text().toInt();
    QString nom= ui->text_nom->text();
    QString prenom= ui->text_prenom->text();
    int n_cin = ui->text_cin->text().toInt();
    QString chambre= ui->comboBox->currentText();
    int jours = ui->text_jours->text().toInt();


    //QString chambre= ui->lineEdit_ch->text();
  Client c(id,nom,prenom,n_cin,chambre,jours);
  bool test=c.ajouter();

  if(test)
{

      ui->tmpclient->setModel(tmpclient.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un client"),
                  QObject::tr("client ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un client"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pb_supprimer_clicked()
{
int id = ui->lineEdit_id_2->text().toInt();
bool test=tmpclient.supprimer(id);
if(test)
{ui->tmpclient->setModel(tmpclient.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Supprimer un étudiant"),
                QObject::tr("Etudiant supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer un étudiant"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}

/*void MainWindow::on_comboBox_currentIndexChanged(const QString &arg1)
{

  QString chambre=ui->comboBox->currentText();
  QSqlQuery qry;
  qry.prepare("select * from etudiant where chambre='"+chambre+"'");
  if(qry.exec())
  {
      while(qry.next())
      {
          ui->text_chambre->setText(qry.value(4).toString());
      }
  }
  else
  {
      QMessageBox::critical(this,tr("error"),qry.lastError().text());
  }
}*/
void MainWindow::on_tmpclient_activated(const QModelIndex &index)
{
    QString val=ui->tmpclient->model()->data(index).toString();
    QSqlQuery qry;
    qry.prepare("select * from etudiant where id='"+val+"'");
    if(qry.exec())
    {
        while(qry.next())
        {
            ui->text_id->setText(qry.value(0).toString());
            ui->text_nom->setText(qry.value(1).toString());
            ui->text_prenom->setText(qry.value(2).toString());
            ui->text_cin->setText(qry.value(3).toString());
            ui->comboBox->currentText();
            ui->text_jours->setText(qry.value(5).toString());
        }

    }
    else
    {
        QMessageBox::critical(this,tr("error::"),qry.lastError().text());
    }
}


void MainWindow::on_modifier_clicked()
{
    QString nom,prenom,chambre,id,jours,n_cin;
    id=ui->text_id->text();
    nom=ui->text_nom->text();
    prenom=ui->text_prenom->text();
    chambre=ui->comboBox->currentText();
    n_cin=ui->text_cin->text();
    jours=ui->text_jours->text();

    QSqlQuery qry;
    qry.prepare("update etudiant set id='"+id+"',nom='"+nom+"' ,prenom='"+prenom+"',n_cin='"+n_cin+"',chambre='"+chambre+"',jours='"+jours+"' where id='"+id+"'");
    if(qry.exec())
    {
        ui->tmpclient->setModel(tmpclient.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("modifier"),
                          QObject::tr("modifié\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("modifier"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_pb_ajouter_2_clicked()
{
    int id = ui->lineEdit_id_3->text().toInt();
    QString nom= ui->lineEdit_id_4->text();
    QString type= ui->comboBox_2->currentText();
    int jours = ui->lineEdit_id_5->text().toInt();

  reservation r(id,nom,type,jours);
  bool test=r.ajouter();
  if(test)
{

      ui->tabreservation->setModel(tabreservation.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter une reservation"),
                  QObject::tr("reservation ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter une reservation"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_modifier_2_clicked()
{
    QString nom,type,id,jours;
    id=ui->lineEdit_id_3->text();
    nom=ui->lineEdit_id_4->text();
    type=ui->comboBox_2->currentText();
    jours=ui->lineEdit_id_5->text();

    QSqlQuery qry;
    qry.prepare("update reservation set id='"+id+"',nom='"+nom+"' ,type='"+type+"',jours='"+jours+"' where id='"+id+"'");
    if(qry.exec())
    {
        ui->tabreservation->setModel(tabreservation.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("modifier"),
                          QObject::tr("modifié\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
    {

        QMessageBox::critical(nullptr, QObject::tr("modifier"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
}





void MainWindow::on_pb_supprimer_2_clicked()
{
    int id = ui->lineEdit_id_6->text().toInt();
    bool test=tabreservation.supprimer(id);
    if(test)
    {ui->tabreservation->setModel(tabreservation.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer une reservation"),
                    QObject::tr("reservation supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une reservation"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


}



void MainWindow::on_modifier_3_clicked()
{
     QString nom=ui->recherche->text();
    ui->tmpclient->setModel(tmpclient.recherche(nom));
}


void MainWindow::on_tabreservation_activated(const QModelIndex &index)
{
    QString val=ui->tabreservation->model()->data(index).toString();
    QSqlQuery qry;
    qry.prepare("select * from reservation where id='"+val+"'");
    if(qry.exec())
    {
        while(qry.next())
        {
            ui->lineEdit_id_3->setText(qry.value(0).toString());
            ui->lineEdit_id_4->setText(qry.value(1).toString());
            ui->comboBox_2->currentText();
            ui->lineEdit_id_5->setText(qry.value(3).toString());
        }

    }
    else
    {
        QMessageBox::critical(this,tr("error::"),qry.lastError().text());
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->tmpclient->setModel(tmpclient.afficher());//refresh

}



void MainWindow::on_pushButton_3_clicked()
{
    QString str;
       str.append("<html><head></head><body><center>"+QString("&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;;<font size=""10"" color =""red""> GESTION DES CLIENTS </font><br /> <br /> "));
       str.append("<table border=1><tr>");
       str.append("<td>"+QString("  ")+"&nbsp;&nbsp;<font color =""blue""  size=""10"">ID</font>&nbsp;&nbsp;"+"</td>");
       str.append("<td>"+QString("&nbsp;&nbsp;<font color =""blue""  size=""10"">Nom </font>&nbsp;&nbsp;")+"</td>");
       str.append("<td>"+QString("&nbsp;&nbsp;<font color =""blue""  size=""10"">Prénom</font>&nbsp;&nbsp;")+"</td>");
       str.append("<td>"+QString("  ")+"&nbsp;&nbsp;<font color =""blue""  size=""10"">n_cin</font>&nbsp;&nbsp;"+"</td>");
       str.append("<td>"+QString("&nbsp;&nbsp;<font color =""blue""  size=""10"">chambre </font>&nbsp;&nbsp;")+"</td>");
       str.append("<td>"+QString("&nbsp;&nbsp;<font color =""blue""  size=""10"">jours </font>&nbsp;&nbsp;")+"</td>");
       QSqlQuery * query=new QSqlQuery();
       query->exec("select * from etudiant");
       while(query->next())
       {
           str.append("<tr><td>");
           str.append("&nbsp;&nbsp;<font color =""green"" size= ""10"">"+query->value(0).toString()+"&nbsp;&nbsp;");
           str.append("</td><td>");
           str.append("&nbsp;&nbsp;<font color =""green""  size=""10"">"+query->value(1).toString()+"&nbsp;&nbsp;");
           str.append("</td><td>");
           str.append("&nbsp;&nbsp;<font color =""green"" size=""10"">"+query->value(2).toString()+"&nbsp;&nbsp;");
            str.append("</td><td>");
           str.append("&nbsp;&nbsp;<font color =""green"" size= ""10"">"+query->value(3).toString()+"&nbsp;&nbsp;");
           str.append("</td><td>");
           str.append("&nbsp;&nbsp;<font color =""green""  size=""10"">"+query->value(4).toString()+"&nbsp;&nbsp;");
           str.append("</td><td>");
           str.append("&nbsp;&nbsp;<font color =""green""  size=""10"">"+query->value(5).toString()+"&nbsp;&nbsp;");


           }
       str.append("</table></center><body></html>");
       QPrinter printer;
       printer.setOrientation(QPrinter::Portrait);
       printer.setOutputFormat(QPrinter::PdfFormat);
       printer.setPaperSize(QPrinter::A4);
       QString path= QFileDialog::getSaveFileName(NULL,"imprimer","gestion des clients","PDF(*.pdf");
        if(path.isEmpty()) return;
        printer.setOutputFileName(path);
        QTextDocument doc;
        doc.setHtml(str);
        doc.print(&printer);
}

void MainWindow::on_pushButton_clicked()
{

    QString str;
       str.append("<html><head></head><body><center>"+QString("&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;;<font size=""10"" color =""red""> GESTION DES CLIENTS </font><br /> <br /> "));
       str.append("<table border=1><tr>");
       str.append("<td>"+QString("  ")+"&nbsp;&nbsp;<font color =""blue""  size=""10"">ID</font>&nbsp;&nbsp;"+"</td>");
       str.append("<td>"+QString("&nbsp;&nbsp;<font color =""blue""  size=""10"">Nom </font>&nbsp;&nbsp;")+"</td>");
       str.append("<td>"+QString("&nbsp;&nbsp;<font color =""blue""  size=""10"">type</font>&nbsp;&nbsp;")+"</td>");
       str.append("<td>"+QString("  ")+"&nbsp;&nbsp;<font color =""blue""  size=""10"">jours</font>&nbsp;&nbsp;"+"</td>");

       QSqlQuery * query=new QSqlQuery();
       query->exec("select * from reservation");
       while(query->next())
       {
           str.append("<tr><td>");
           str.append("&nbsp;&nbsp;<font color =""green"" size= ""10"">"+query->value(0).toString()+"&nbsp;&nbsp;");
           str.append("</td><td>");
           str.append("&nbsp;&nbsp;<font color =""green""  size=""10"">"+query->value(1).toString()+"&nbsp;&nbsp;");
           str.append("</td><td>");
           str.append("&nbsp;&nbsp;<font color =""green"" size=""10"">"+query->value(2).toString()+"&nbsp;&nbsp;");
            str.append("</td><td>");
           str.append("&nbsp;&nbsp;<font color =""green"" size= ""10"">"+query->value(3).toString()+"&nbsp;&nbsp;");



           }
       str.append("</table></center><body></html>");
       QPrinter printer;
       printer.setOrientation(QPrinter::Portrait);
       printer.setOutputFormat(QPrinter::PdfFormat);
       printer.setPaperSize(QPrinter::A4);
       QString path= QFileDialog::getSaveFileName(NULL,"imprimer","gestion des reservations","PDF(*.pdf");
        if(path.isEmpty()) return;
        printer.setOutputFileName(path);
        QTextDocument doc;
        doc.setHtml(str);
        doc.print(&printer);

}

void MainWindow::on_pushButton_4_clicked()
{
    QString nom=ui->lineEdit->text();
   ui->tabreservation->setModel(tabreservation.recherche(nom));
}





void MainWindow::on_pushButton_5_clicked()
{
     ui->tabreservation->setModel(tabreservation.afficher());//refresh
}
