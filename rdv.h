#ifndef RDV_H
#define RDV_H
#include <QString>
#include <QSqlQueryModel>

class Rdv
{

public:
    Rdv();
    Rdv(QString Cin, QString type_rdv, QString date);
    ~Rdv();

    bool Ajouter();
    QSqlQueryModel * print();

    //getters
    QString getCin();
    QString getType_rdv();
    QString getDate();

    //setters
    void setCin(QString Cin);
    void setType_rdv(QString type_rdv);
    void setDate(QString Date);

private:
    QString Cin , type_rdv , date ;
};

#endif // RDV_H
