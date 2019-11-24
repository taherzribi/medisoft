#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "addconsultation.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr, QString id = "0");
    ~MainWindow();
    void update_consultations_table();

private slots:
    void on_consultations_updated(QString cin_pat, QString description, QString type_cons);
    void on_actionAjouter_3_triggered();

private:
    Ui::MainWindow *ui;
    AddConsultation * addconsultation;
    Consultation *tmp_consultation;
    QString id_med;
};

#endif // MAINWINDOW_H
