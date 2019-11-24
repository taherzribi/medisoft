#include "connection.h"
#include "ui_connection.h"
#include <QDebug>

Connection::Connection(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Connection)
{
    ui->setupUi(this);
    new_account = new NewAcount(this);
}

Connection::~Connection()
{
    delete ui;
    delete new_account;
    delete tmp_med;
    delete main_window;
}

void Connection::on_create_account_clicked()
{
    qInfo() << "New account button clicked";
    this->new_account->show();
}

void Connection::on_Connect_clicked()
{
    qInfo() << "Connection button clicked";
    tmp_med = new Medecin(ui->Nom->text(),ui->Prenom->text(),ui->password->text());
    if(tmp_med->Connect()){
        qInfo() << "Correct" << endl;
        main_window = new MainWindow(this, tmp_med->getIdMed());
        main_window->show();
    }else{
        qInfo() << "Incorrect" << endl;
    }
}
