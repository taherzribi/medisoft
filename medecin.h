#ifndef MEDECIN_H
#define MEDECIN_H

#include <QString>
#include <QSqlQueryModel>

class Medecin
{
public:
    Medecin();
    Medecin(QString nom, QString prenom, QString mtp);
    ~Medecin();

    bool Ajouter();
    bool Connect();
    QSqlQueryModel * print();

    //getters
    QString getIdMed();
    QString getNom();
    QString getPrenom();
    QString getMotDePasse();
    //setters
    void setIdMed(QString id_med);
    void setNom(QString nom);
    void setPrenom(QString prenom);
    void setMotDePasse(QString mdp);
private:
    QString id_medecin, nom, prenom;
    QString mtp;
};

#endif // MEDECIN_H
