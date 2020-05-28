#include "sqlwraper.h"
#include <QSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>


void SQLWrapper::openDB()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");;
    qDebug()<<"Let me try and connect";
    db.setHostName("localhost");
    db.setUserName("pacman");
    db.setPassword("pacman");
    db.setDatabaseName("pacman");
    if (db.open())
    {
        qDebug()<<"DB Is HERE!!!!";
    }
    else
    {
        if (db.lastError().isValid()) {
            qDebug() << "Error loading database:" << db.lastError();
        }
    }


}

void SQLWrapper::closeDB()
{

}

/**
 * Base function to populate the leader board
 * and format the leaderbord text.
 * @brief SQLWrapper::loadLeaderBoard
 * @return QStringList
 */

QStringList SQLWrapper::loadLeaderBoard()
{
    QStringList answers;
    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery query("SELECT * FROM results ORDER BY score DESC;");
    qDebug() << query.value(0).toString();
    while (query.next()) {
        //answers[0] = query.value(0).toString();
        //answers->append(query.value(0).toString());
        qDebug() << query.value(0).toString();
        qDebug() << query.value(1).toString();
        qDebug() << query.value(2).toString();
        qDebug() << query.value(3).toString();
        QString text = query.value(2).toString() + " " + query.value(1).toString();
        answers<<text;
    }

    return answers;

}
