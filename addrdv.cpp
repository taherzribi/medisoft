#include "addrdv.h"
#include "ui_addrdv.h"
#include <QDebug>

AddRdv::AddRdv(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddRdv)
{
    ui->setupUi(this);
}

AddRdv::~AddRdv()
{
    delete ui;
}
void AddRdv::on_buttonBox_accepted()
{
    qInfo() << "--Add RDV--" << endl;
    emit rdv_updated(ui->cin->text(),ui->plainTextEdit->toPlainText(),ui->typ_cons1->text());
}
