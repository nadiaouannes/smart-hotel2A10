#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "menu.h"
#include "stocke.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pb_ajouter_m_clicked();

    void on_pb_ajouter_s_clicked();

    void on_pb_supprimer_m_clicked();

    void on_pb_supprimer_s_clicked();

    void on_pb_modifier_m_clicked();



    void on_pushButton_trie_m_clicked();

    void on_pb_modifier_s_clicked();



    void on_pushButton_trie_s_clicked();

    void on_pb_rech_m_clicked();

    void on_pushButton_2_clicked();

    void on_pb_rech_s_clicked();

    void on_tabmenu_activated(const QModelIndex &index);

    void on_pushButton_3_clicked();

    void on_pb_actualiser_m_clicked();

private:
    Ui::MainWindow *ui;
    Menu *tmpmenu;
    Stocke *tmpstocke;
};

#endif // MAINWINDOW_H
