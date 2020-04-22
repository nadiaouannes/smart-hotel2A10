#ifndef VPERSONEL_H
#define VPERSONEL_H

#include <QMainWindow>
#include <QWidget>

class vpersonel
{
private:
    QString id,nom,prenom;

public:
    vpersonel();
    vpersonel(QString,QString,QString);
    QString getnom();
    QString getprenom();
    QString getid();
    void setnom(QString);
    void setprenom(QString);
    void setid(QString);
    bool ajouter();
    bool supprimer();
};

#endif // VPERSONEL_H







