#include "sqlwraper.h"
#include <QSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDateTime>
#include <QDebug>
#include <QMessageBox>
#include <QObject>


void SQLWrapper::openDB(QString host, QString username, QString pass, QString dbname)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");;
    qDebug()<<"Let me try and connect";
    db.setHostName(host);
    db.setUserName(username);
    //db.setPassword(pass);
    db.setPassword(QString("pacmmm"));
    db.setDatabaseName(dbname);
    if (db.open())
    {
        qDebug()<<"DB Is HERE!!!!";
    }
    else
    {
        // So if we are not connected - display error message.
        if (db.lastError().isValid()) {
            QWidget *test = new QWidget();
            QPalette pallette;
            pallette.setColor(QPalette::Background, Qt::black);
            QMessageBox *error = new QMessageBox;
            error->setPalette(pallette);
            QString text = db.lastError().text();
            error->about(test, QObject::tr("DB Error detected"), QObject::tr(qPrintable(text)));
        }
    }


}

void SQLWrapper::closeDB()
{

}

/**
 * Expose isOpe() for DB object
 * @brief SQLWrapper::isConValid
 * @return
 */
bool SQLWrapper::isConValid()
{
    QSqlDatabase db = QSqlDatabase::database();
    if (db.isOpen())
    {
        return true;
    }
    return false;
}


/**
 * Check if table exists
 * @brief SQLWrapper::isStructValid
 * @return
 */
bool SQLWrapper::isStructValid()
{
    QSqlDatabase db = QSqlDatabase::database();
    qDebug() << db.tables();
    if (db.tables().contains( QString("results"))) {
        return true;
    }
    return false;
}

/**
 * Expose lastError()
 * @brief SQLWrapper::getError
 * @return
 */
QString SQLWrapper::getError()
{
    QSqlDatabase db = QSqlDatabase::database();
    if(db.lastError().isValid())
    {
        return QString(db.lastError().text());
    }
    return QString("No Errors");
}

/**
 * Base function to populate the leader board
 * and format the leaderbord text.
 * @brief SQLWrapper::loadLeaderBoard
 * @return QStringList
 */

QList<QList<QString>> SQLWrapper::loadLeaderBoard()
{
    QList<QList<QString>> answers;
    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery query("SELECT * FROM results ORDER BY score DESC LIMIT 6;");
    qDebug() << query.value(0).toString();
    while (query.next()) {
        qDebug() << query.value(5);
        QList<QString> a;
        a.append(QString("%1").arg(query.value(0).toInt()));
        a.append(QString("%1").arg(query.value(1).toString()));
        a.append(QString("%1").arg(query.value(2).toInt()));
        a.append(QString("%1").arg(query.value(3).toInt()));
        a.append(QString("%1").arg(query.value(4).toInt()));
        a.append(QString("%1").arg(query.value(5).toInt()));
        answers.append(a);
    }
    qDebug() << answers;
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
    int answer = 0;
    query.exec("SELECT score FROM results WHERE difficulty = " + QString("%1").arg(dificulty) + " ORDER BY score DESC LIMIT 1");
    while (query.next()) {
         answer = query.value(0).toInt();
    }

    return answer;
}

/**
 * Send data to database (name, score, dificulty, time)
 * @brief SQLWrapper::sendData
 * @param name
 * @param score
 * @param difficulty
 * @param time
 */
void SQLWrapper::sendData(QString name, int score, int difficulty, int time)
{
    QSqlDatabase db = QSqlDatabase::database();
    QDateTime * timestamp = new QDateTime;
    QSqlQuery query;
    query.exec("INSERT INTO results (username, score, difficulty, time, timestamp) VALUES ('"+ name +"', '" + QString("%1").arg(score) +"', '" + QString("%1").arg(difficulty) +"', '" + QString("%1").arg(time) +"', '" + QString("%1").arg(timestamp->currentSecsSinceEpoch()) +"')");
}

/**
 * Get relative position based on name, score and difficulty
 * @brief SQLWrapper::getRelativePosition
 * @param name
 * @param score
 * @param difficulty
 * @return
 */
QList<QList<QString>>SQLWrapper::getRelativePosition(QString name, int score, int difficulty)
{
    QList<QList<QString>> response;
    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery query;
    int row, all_rows, offset;
    // Let's get the row
    query.exec("WITH temp as (SELECT username, score, time, row_number() OVER (ORDER BY score DESC, timestamp DESC) as rownum FROM results WHERE difficulty='" +QString("%1").arg(difficulty)  + "') SELECT rownum, username, score, time FROM temp WHERE username like '"+ QString("%1").arg(name) +"' AND score = '" + QString("%1").arg(score) + "'");
    //qDebug() << "WITH temp as (SELECT username, score, time, row_number() OVER (ORDER BY score DESC, timestamp DESC) as rownum FROM results WHERE difficulty='" +QString("%1").arg(difficulty)  + "') SELECT rownum, username, score, time FROM temp WHERE username like '"+ QString("%1").arg(name) +"' AND score = '" + QString("%1").arg(score) + "'";
    while (query.next()) {
         row = query.value(0).toInt();
    }
    qDebug() << row;
    // Now let's take all results for this difficulty
    query.exec("WITH temp as (SELECT row_number() OVER (ORDER BY score DESC, timestamp DESC) as rownum FROM results WHERE difficulty='" + QString("%1").arg(difficulty)  + "') SELECT max(rownum) FROM temp");
    //qDebug() << "WITH temp as (SELECT row_number() OVER (ORDER BY score DESC, timestamp DESC) as rownum FROM results WHERE difficulty='" + QString("%1").arg(difficulty)  + "') SELECT max(rownum) FROM temp;";
    while (query.next()) {
         all_rows = query.value(0).toInt();
    }
    qDebug() << all_rows;

    // Now let's calculate the offset (We will always be requesting 5 rows)
    if (row < 3 || all_rows < 5)
    {
        offset = 0;
    }
    else if (row >= (all_rows - 2))
    {
        offset = all_rows - 5;
    }
    else
    {
        offset = row - 2;
    }

    query.exec("WITH temp as (SELECT username, score, time, row_number() OVER (ORDER BY score DESC, timestamp DESC) as rownum FROM results WHERE difficulty = '" + QString("%1").arg(difficulty)  + "') SELECT rownum, username, score, time FROM temp LIMIT 5 OFFSET " + QString("%1").arg(offset) + ";");
    qDebug() << "WITH temp as (SELECT username, score, time, row_number() OVER (ORDER BY score DESC, timestamp DESC) as rownum FROM results WHERE difficulty = '" + QString("%1").arg(difficulty)  + "') SELECT rownum, username, score, time FROM temp LIMIT 5 OFFSET " + QString("%1").arg(offset) + ";";
    while (query.next()) {
        QList<QString> a;
        a.append(QString("%1").arg(query.value(0).toInt()));
        a.append(QString("%1").arg(query.value(1).toString()));
        a.append(QString("%1").arg(query.value(2).toInt()));
        a.append(QString("%1").arg(query.value(3).toInt()));
        if (query.value(0).toInt() == row)
        {
            a.append(QString("%1").arg(1));
        }
        else
        {
            a.append(QString("%1").arg(0));
        }
        response.append(a);
    }

    return response;
}
