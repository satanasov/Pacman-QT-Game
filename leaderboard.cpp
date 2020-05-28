
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
 * @brief LeaderBoard::populate
 */
void LeaderBoard::populate()
{

    // Let's translate elements with score to map so we can address them properly
    QLabel* labels[6];
    labels[0] = this->ui->label_4;
    labels[1] = this->ui->label_5;
    labels[2] = this->ui->label_6;
    labels[3] = this->ui->label_7;
    labels[4] = this->ui->label_8;
    labels[5] = this->ui->label_9;


    SQLWrapper *sql = new SQLWrapper();
    sql->openDB();
    QStringList answers = sql->loadLeaderBoard();
    qDebug() << sql->loadLeaderBoard();
    for (int i = 0; i < answers.size(); ++i)
    {
        QString text;
        text.append(QString("%1").arg(i+1));
        text.append(" ");
        text.append(answers.at(i).toLocal8Bit().constData());
        labels[i]->setText(text);
    }
}
