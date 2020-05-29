#ifndef SQLWRAPER_H
#define SQLWRAPER_H

#include <QString>
#include <QSql>

class SQLWrapper
{
    public:
        void openDB();
        void closeDB();
        QStringList loadLeaderBoard();
        int getHighestScore(int dificulty);
};

#endif // SQLWRAPER_H
