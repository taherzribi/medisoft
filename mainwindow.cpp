#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent, QString id) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->id_med = id;
    update_consultations_table();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete addconsultation;
    delete tmp_consultation;
}

void MainWindow::on_actionAjouter_3_triggered(){
    qInfo() << "ADD Consultation" << endl;
    addconsultation = new AddConsultation(this);
    connect(addconsultation, SIGNAL(consultations_updated(QString,QString,QString)), this, SLOT(on_consultations_updated(QString,QString,QString)));
    addconsultation->show();
}

void MainWindow::update_consultations_table(){
    ui->Consultations_table->setModel(tmp_consultation->print());
}

void MainWindow::on_consultations_updated(QString cin_pat, QString description, QString type_cons){
    tmp_consultation = new Consultation(id_med, cin_pat, description, type_cons);
    if(tmp_consultation->Ajouter()){
        qInfo() << "[?] consultation added" << endl;
        update_consultations_table();
    }else{
        qInfo() << "[!] consultation non added" << endl;
    }
}
