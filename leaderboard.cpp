
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

            this->populate();
    }


LeaderBoard::~LeaderBoard()
{
    delete ui;
}

/**
 * We need a back button
 * @brief LeaderBoard::on_backBtn_clicked
 */
void LeaderBoard::on_backBtn_clicked()
{
    Options *w = new Options;
    w->show();
    this->close();
}

/**
 * Function that should populate the leader board
 *
 * TODO: Make leaderboard work with all corect requests.
 * @brief LeaderBoard::populate
 */
void LeaderBoard::populate()
{

    // Let's translate elements with score to map so we can address them properly
    QLabel* PlacesName[6];
    PlacesName[0] = this->ui->PlaceName_1;
    PlacesName[1] = this->ui->PlaceName_2;
    PlacesName[2] = this->ui->PlaceName_3;
    PlacesName[3] = this->ui->PlaceName_4;
    PlacesName[4] = this->ui->PlaceName_5;
    PlacesName[5] = this->ui->PlaceName_6;

    QLabel* Scores[6];
    Scores[0] = this->ui->PlaceScore_1;
    Scores[1] = this->ui->PlaceScore_2;
    Scores[2] = this->ui->PlaceScore_3;
    Scores[3] = this->ui->PlaceScore_4;
    Scores[4] = this->ui->PlaceScore_5;
    Scores[5] = this->ui->PlaceScore_6;

    QLabel* Difficulty[6];
    Difficulty[0] = this->ui->PlaceDif_1;
    Difficulty[1] = this->ui->PlaceDif_2;
    Difficulty[2] = this->ui->PlaceDif_3;
    Difficulty[3] = this->ui->PlaceDif_4;
    Difficulty[4] = this->ui->PlaceDif_5;
    Difficulty[5] = this->ui->PlaceDif_6;

    QLabel* Times[6];
    Times[0] = this->ui->PlaceTime_1;
    Times[1] = this->ui->PlaceTime_2;
    Times[2] = this->ui->PlaceTime_3;
    Times[3] = this->ui->PlaceTime_4;
    Times[4] = this->ui->PlaceTime_5;
    Times[5] = this->ui->PlaceTime_6;


    // Connect to DB
    SQLWrapper *sql = new SQLWrapper();
    //Populate the leader board.
    QList<QList<QString>> answers = sql->loadLeaderBoard();

    for (int i = 0; i < answers.size(); ++i)
    {
        PlacesName[i]->setText(QString("%1").arg(answers[i][1]));
        Scores[i]->setText(QString("%1").arg(answers[i][2]));
        Times[i]->setText(QString("%1 s").arg(answers[i][5]));
        switch(answers[i][4].toInt())
        {
            case 1:
                Difficulty[i]->setText(QString("Easy"));
            break;
            case 2:
                Difficulty[i]->setText(QString("Medium"));
            break;
            case 3:
                Difficulty[i]->setText(QString("Hard"));
            break;
        }

        qDebug() << answers[i];
    }
}
