#include "sqlwraper.h"
#include <QSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDateTime>
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

/**
 * Get highest score for dificulty
 * @brief SQLWrapper::getHighestScore
 * @param dificulty
 * @return
 */
int SQLWrapper::getHighestScore(int dificulty)
{
    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery query;
    query.exec("SELECT score FROM results WHERE dificulty = " + QString("%1").arg(dificulty) + " ORDER BY score DESC LIMIT 1");
    int answer = query.value(0).toInt();

    return answer;
}

void SQLWrapper::sendData(QString name, int score, int difficulty, int time)
{
    QSqlDatabase db = QSqlDatabase::database();
    QDateTime * timestamp = new QDateTime;
    QSqlQuery query;
    query.exec("INSERT INTO results (username, score, dificulty, time, timestamp) VALUES ('"+ name +"', '" + QString("%1").arg(score) +"', '" + QString("%1").arg(difficulty) +"', '" + QString("%1").arg(time) +"', '" + QString("%1").arg(timestamp->currentSecsSinceEpoch()) +"')");
}
