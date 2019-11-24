#include "rdv.h"
#include <QString>
#include <QSqlQuery>

Rdv::Rdv(){}

Rdv::Rdv(QString Cin, QString type_rdv, QString date){
    this->Cin = Cin;
    this->type_rdv = type_rdv;
    this->date = date;
}

QString Rdv::getCin(){
    return this->Cin;
}

void Rdv::setCin(QString Cin){
    this->Cin = Cin;
}
QString Rdv::getType_rdv(){
    return type_rdv;
}

void Rdv::setType_rdv(QString type_rdv){
    this->type_rdv = type_rdv;
}

QString Rdv::getDate(){
    return date;
}

void Rdv::setDate(QString date){
    this->date = date;
}

bool Rdv::Ajouter(){
    QSqlQuery qr;
    qr.prepare("INSERT INTO Rdv (cin_pat, date_rdv, type_rdv ) VALUES (:Cin,  :date, :type_rdv)");
    qr.bindValue(":cin_pat", this->Cin);
    qr.bindValue(":date_rdv", this->date);
    qr.bindValue(":type_rdv", this->type_rdv);
    return qr.exec();
}
