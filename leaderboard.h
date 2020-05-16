#ifndef LEADERBOARD_H
#define LEADERBOARD_H

#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QSound>
#include <QSoundEffect>
#include <QShortcut>


namespace Ui {
    class LeaderBoard;
}

class LeaderBoard : public QWidget
{
    Q_OBJECT

    public:
        explicit LeaderBoard(QWidget *parent = 0);
        ~LeaderBoard();
        QString msg;
    //private slots:



    private:
     Ui::LeaderBoard *ui;
};


#endif // LEADERBOARD_H
