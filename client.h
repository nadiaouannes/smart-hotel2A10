#ifndef CLIENT_H
#define CLIENT_H
#include "vclients.h"
#include <QDialog>

namespace Ui {
class client;
}

class client : public QDialog
{
    Q_OBJECT

public:
    explicit client(QWidget *parent = nullptr);
    ~client();

private slots:
    void on_pushButton_clicked();

    void on_ajouter_clicked();

    void on_pushButton_3_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_pushButton_5_clicked();

    void on_lineEdit_5_textChanged(const QString &arg1);

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

private:
    vclients tmpvehicule;

    Ui::client *ui;
};

#endif // CLIENT_H
