#include "menuwindow.h"
#include "ui_menuwindow.h"
#include "connection.h"

MenuWindow::MenuWindow(QWidget *parent) :QMainWindow(parent),ui(new Ui::MenuWindow){
    ui->setupUi(this);
    connect = new Connection(this);
}

MenuWindow::~MenuWindow(){
    delete ui;
    delete connect;
}

void MenuWindow::on_Connect_clicked(){
    this->hide();
    this->connect->show();
    //this->show();
}
