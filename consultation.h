#ifndef CONSULTATION_H
#define CONSULTATION_H
#include <QString>
#include <QSqlQueryModel>

class Consultation
{
public:
    Consultation();
    Consultation(QString id_med, QString cin_patient, QString description, QString type_cons);
    ~Consultation();

    bool Ajouter();
    QSqlQueryModel * print();

    //getters
    QString getIdMed();
    QString getCinPatient();
    QString getDescription();
    //setters
    void setIdMed(QString id_med);
    void setCinPatient(QString cin_pat);
    void setDescription(QString desc);
private:
    QString id_medecin, cin_patient, description, type_cons;
};

#endif // CONSULTATION_H
