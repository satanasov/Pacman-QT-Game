
#include "leaderboard.h"
#include "ui_leaderboard.h"
#include <QThread>
#include <QtWidgets>
#include "options.h"


LeaderBoard::LeaderBoard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LeaderBoard)
    {
        QLabel *image = new QLabel();
               image->setPixmap( QPixmap( "paclogo.jpg" ) );
               image->show();
            ui->setupUi(this);
    }

LeaderBoard::~LeaderBoard()
{
    delete ui;
}
