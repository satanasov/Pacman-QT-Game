#ifndef SQLWRAPER_H
#define SQLWRAPER_H

#include <QString>
#include <QList>
#include <QSql>
#include <QPalette>

class SQLWrapper
{
    public:
        void openDB(QString hostname, QString username, QString password, QString dbname);
        void closeDB();
        QPalette pallett;
        QList<QList<QString>> loadLeaderBoard();
        int getHighestScore(int dificulty);
        void sendData(QString name, int score, int difficulty, int time);
        QList<QList<QString>> getRelativePosition(QString name, int score, int difficulty);
};

#endif // SQLWRAPER_H
