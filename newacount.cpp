#include "newacount.h"
#include "ui_newacount.h"
#include <QDebug>

NewAcount::NewAcount(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewAcount)
{
    ui->setupUi(this);
}

NewAcount::~NewAcount()
{
    delete ui;
    delete tmp_med;
}

void NewAcount::on_create_accepted()
{
    if(ui->password->text() == ui->password_confirmation->text()){
        tmp_med = new Medecin(ui->name->text(), ui->surname->text(), ui->password->text());
        if (tmp_med->Ajouter()){
            qInfo() << "Medecin added" << endl;
        }else{
            qInfo() << "Medecin not added"<<ui->name->text()<< ui->surname->text()<< ui->password->text() << endl;
        }
    }else{
        qInfo() << "password != confirmation" << endl;
    }
}
