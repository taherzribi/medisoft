#include "databaseconnection.h"

DataBaseConnection::DataBaseConnection(QString api_sql){
    qInfo() << "Connection to the database" << endl;
    db = QSqlDatabase::addDatabase(api_sql);
}

bool DataBaseConnection::OpenConnection(QString databasename, QString user, QString password){
    bool open = false;

    db.setDatabaseName(databasename);
    db.setUserName(user);
    db.setPassword(password);

    if(db.open()){
        open = true;
        qInfo() << db.tables();
    }else{
        throw QString("Error Connection");
    }
    return open;
}

bool DataBaseConnection::CloseConnection(){
    bool close = true;
    db.close();
    return close;
}
