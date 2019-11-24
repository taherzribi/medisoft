#ifndef CONNECTION_H
#define CONNECTION_H
#include "newacount.h"
#include "medecin.h"
#include <QMainWindow>
#include "mainwindow.h"

namespace Ui {
class Connection;
}

class Connection : public QMainWindow
{
    Q_OBJECT

public:
    explicit Connection(QWidget *parent = nullptr);
    ~Connection();

private slots:
    void on_pushButton_clicked();

    void on_create_account_clicked();

    void on_Connect_clicked();

private:
    Ui::Connection *ui;
    NewAcount * new_account;
    Medecin * tmp_med;
    MainWindow *main_window;
};

#endif // CONNECTION_H
