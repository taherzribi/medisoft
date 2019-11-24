#ifndef DATEBASECONNECTION_H
#define DATEBASECONNECTION_H
#include <QSqlDatabase>
#include <QString>
#include <QDebug>

class DataBaseConnection
{
public:
    DataBaseConnection(QString api_sql);
    bool OpenConnection(QString databasename, QString user, QString password);
    bool CloseConnection();
private:
    QSqlDatabase db;
};

#endif // DATEBASECONNECTION_H
