#include "addconsultation.h"
#include "ui_addconsultation.h"
#include <QDebug>

AddConsultation::AddConsultation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddConsultation)
{
    ui->setupUi(this);
}

AddConsultation::~AddConsultation()
{
    delete ui;
}

void AddConsultation::on_buttonBox_accepted()
{
    qInfo() << "--Add consultation--" << endl;
    emit consultations_updated(ui->cin_pat->text(),ui->plainTextEdit->toPlainText(),ui->typ_cons->text());
}
