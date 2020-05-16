#include "sqlwraper.h"
#include <QSql>
#include <QSqlDatabase>
#include <QDebug>


void SQLWrapper::addDB()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");;
    db.setHostName("localhost");
    db.setUserName("pacman");
    db.setPassword("pacman");
    db.setDatabaseName("pacman");
    if (db.open())
    {
        qDebug()<<"DB Is HERE!!!!";
    }


}
