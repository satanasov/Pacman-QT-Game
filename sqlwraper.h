#ifndef SQLWRAPER_H
#define SQLWRAPER_H

#include <QString>
#include <QList>
#include <QSql>

class SQLWrapper
{
    public:
        void openDB();
        void closeDB();
        QStringList loadLeaderBoard();
        int getHighestScore(int dificulty);
        void sendData(QString name, int score, int difficulty, int time);
        QList<QList<QString>> getRelativePosition(QString name, int score, int difficulty);
};

#endif // SQLWRAPER_H
