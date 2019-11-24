#include "menuwindow.h"
#include "databaseconnection.h"

#include <QApplication>
#include <QPushButton>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>

int main(int argc, char *argv[]){

    QApplication a(argc, argv);
    MenuWindow w;
    DataBaseConnection connection("QODBC");

    try{
        connection.OpenConnection("my_DataBase", "zribi", "esprit18");

    }catch(QString e){
        qInfo() << "Catch Error" << e << endl;
    }
    w.show();
    return a.exec();
}
