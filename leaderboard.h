#ifndef LEADERBOARD_H
#define LEADERBOARD_H

#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QSound>
#include <QPainter>
#include <QSoundEffect>
#include <QShortcut>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include "textdrawing.h"


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
        TextDrawing *text;
        void populate();
    private slots:
        void on_backBtn_clicked();



    private:
     Ui::LeaderBoard *ui;
     QGraphicsScene *scene;
};


#endif // LEADERBOARD_H
