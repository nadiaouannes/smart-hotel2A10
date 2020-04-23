#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "client.h"
#include "reservation.h"
#include <QMainWindow>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();




    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_tabetudiant_activated(const QModelIndex &index);

    void on_modifier_clicked();

    void on_pb_ajouter_2_clicked();

    void on_modifier_2_clicked();

    void on_tabetudiant_2_activated(const QModelIndex &index);

    void on_pb_supprimer_2_clicked();

    void on_comboBox_2_currentIndexChanged(const QString &arg1);

    void on_text_id_cursorPositionChanged(int arg1, int arg2);

    void on_modifier_3_clicked();

    void on_tmpclient_activated(const QModelIndex &index);

    void on_tabreservation_activated(const QModelIndex &index);

    void on_comboBox_activated(const QString &arg1);

    void on_comboBox_2_activated(const QString &arg1);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::MainWindow *ui;
    Client tmpclient;
    reservation tabreservation;

};

#endif // MAINWINDOW_H
