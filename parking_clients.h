#ifndef PARKING_CLIENTS_H
#define PARKING_CLIENTS_H

#include "vclients.h"

#include <QDialog>

namespace Ui {
class parking_clients;
}

class parking_clients : public QDialog
{
    Q_OBJECT

public:
    explicit parking_clients(QWidget *parent = nullptr);
    ~parking_clients();

private slots:


    void on_pushButton_clicked();
    void Refresh(int);

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_ADD_clicked();

    void on_DELETE_clicked();

    void on_EDIT_clicked();

    void on_pushButton_6_clicked();

    void on_SHOW_clicked();

    void on_pushButton_7_clicked();
    int getChoix();
    void setChoix(int);
    int getChoixzone();
    void setChoixzone(int);
    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();


    void on_lineEdit_10_textChanged(const QString &arg1);

    void on_tableView_activated(const QModelIndex &index);

    void on_pushButton_11_clicked();

private:
    Ui::parking_clients *ui;

    vclients tmpvehicule;
    int choixzone;
    int choix;
};

#endif // PARKING_CLIENTS_H
