
#include "leaderboard.h"
#include "ui_leaderboard.h"
#include <QThread>
#include <QtWidgets>
#include "options.h"
#include "sqlwraper.h"


LeaderBoard::LeaderBoard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LeaderBoard)
    {
        QLabel *image = new QLabel();
               image->setPixmap( QPixmap( "paclogo.jpg" ) );
               image->show();
            ui->setupUi(this);
        SQLWrapper *sql = new SQLWrapper();
        sql->addDB();
    }


LeaderBoard::~LeaderBoard()
{
    delete ui;
}
