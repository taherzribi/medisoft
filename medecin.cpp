#include "medecin.h"

#include <QString>
#include <QSqlQuery>
#include <QCryptographicHash>
#include <QByteArray>
#include <QDebug>
Medecin::Medecin()
{

}

Medecin::~Medecin()
{

}
Medecin::Medecin(QString nom, QString prenom, QString mtp){
    this->prenom = prenom;
    this->nom = nom;
    this->mtp = mtp;
}

QString Medecin::getIdMed(){
    return this->id_medecin;
}

void Medecin::setIdMed(QString id_med){
    this->id_medecin = id_med;
}

QString Medecin::getNom(){
    return nom;
}

void Medecin::setNom(QString nom){
    this->nom = nom;
}

QString Medecin::getPrenom(){
    return prenom;
}

void Medecin::setPrenom(QString prenom){
    this->prenom = prenom;
}

bool Medecin::Ajouter(){
    QSqlQuery qr;

    QByteArray mdp_hash = QCryptographicHash::hash(this->mtp.toLocal8Bit(), QCryptographicHash::Sha256);
    QString pass_string = mdp_hash.toHex();

    qr.prepare("INSERT INTO medecin (nom, prenom, mtp) VALUES (:nom, :prenom, :pass);");
    qr.bindValue(":nom", this->nom);
    qr.bindValue(":prenom", this->prenom);
    qr.bindValue(":pass", pass_string);
    qInfo() << qr.isValid();
    return qr.exec();
}

bool Medecin::Connect(){
    QSqlQuery qr;

    QByteArray mdp_hash = QCryptographicHash::hash(mtp.toLocal8Bit(), QCryptographicHash::Sha256);
    QString pass_string = mdp_hash.toHex();

    qr.prepare("SELECT * FROM medecin WHERE mtp= :mdp and nom= :nom and prenom = :prenom;");
    qr.bindValue(":nom", this->nom);
    qr.bindValue(":prenom", this->prenom);
    qr.bindValue(":mdp", pass_string);
    qr.exec();
    qInfo() << this->nom << this->prenom <<pass_string<<qr.size() << qr.exec();
    qr.next();
    QString buffer =  qr.value(0).toString();
    if(qr.size() > 0 || buffer != ""){
        this->setIdMed(qr.value(0).toString());
        return true;
    }else{
        return false;
    }
}
QSqlQueryModel * Medecin::print(){
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM medecin");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_med"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));

    return model;
}
