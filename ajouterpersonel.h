#ifndef AJOUTERPERSONEL_H
#define AJOUTERPERSONEL_H
#include <QDialog>
#include "qcustomplot.h"
#include "personnel.h"
#include "reclamation.h"

namespace Ui {
class Ajouterpersonel;
}

class Ajouterpersonel : public QDialog
{
    Q_OBJECT

public:
    explicit Ajouterpersonel(QWidget *parent = nullptr);
    ~Ajouterpersonel();

private slots:

    void on_ajouterper_clicked();

    void on_modifierper_clicked();

    void on_supprimerper_clicked();

    void on_rechercherper_clicked();

    void on_trieper_clicked();

    void on_ajouterrec_clicked();

    void on_modifierrec_clicked();

    void on_suprrimerrec_clicked();

    void on_recherecherrec_clicked();

    void on_trierrec_clicked();

    void on_modifierper_3_clicked();

private:
    Ui::Ajouterpersonel *ui;
    PERSONNEL tmpperosonel;
    RECLAMATION tmpreclamation;
};

#endif // AJOUTERPERSONEL_H
