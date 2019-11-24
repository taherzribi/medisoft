#include "consultation.h"
#include <QString>
#include <QSqlQuery>

Consultation::Consultation(){}
Consultation::~Consultation(){}

Consultation::Consultation(QString id_med, QString cin_patient, QString description, QString type_cons){
    this->id_medecin = id_med;
    this->cin_patient = cin_patient;
    this->description = description;
    this->type_cons = type_cons;
}

QString Consultation::getIdMed(){
    return this->id_medecin;
}

void Consultation::setIdMed(QString id_med){
    this->id_medecin = id_med;
}

QString Consultation::getCinPatient(){
    return cin_patient;
}

void Consultation::setCinPatient(QString cin_pat){
    this->id_medecin = cin_pat;
}

QString Consultation::getDescription(){
    return description;
}

void Consultation::setDescription(QString desc){
    this->description = desc;
}

bool Consultation::Ajouter(){
    QSqlQuery qr;
    qr.prepare("INSERT INTO consultations (description, cin_pat, id_med, type_cons) VALUES (:des, :cin, :id_med, :type_cons);");
    qr.bindValue(":des", this->description);
    qr.bindValue(":cin", this->cin_patient);
    qr.bindValue(":id_med", this->id_medecin);
    qr.bindValue(":type_cons", this->type_cons);

    return qr.exec();
}

QSqlQueryModel * Consultation::print(){
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM consultations");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_cons"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("description"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("cin_pat"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("id_med"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_cons"));

    return model;
}
