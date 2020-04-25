#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QSystemTrayIcon>
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
    void maFonction(QString const & texte);





private slots:
    void on_pushButton_start_clicked();

    void on_pushButton_quitter_clicked();

private:
    Ui::MainWindow *ui;
    QSystemTrayIcon * notifier;


};

#endif // MAINWINDOW_H
