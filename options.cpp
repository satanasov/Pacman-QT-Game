
#include "options.h"
#include "ui_options.h"
#include "pacmanwindow.h"
#include "leaderboard.h"
#include "sqlwraper.h"
#include "db_settings.h"
#include <QDebug>


Options::Options(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Options)
{
    QLabel *image = new QLabel();
       image->setPixmap( QPixmap( "paclogo.jpg" ) );
       image->show();
    ui->setupUi(this);
    difficulty = 0;
    // if the toggle buttons not checked then warn
    // if text box

}

Options::~Options()
{
    delete ui;
}
// When start button is pressed, error handling, setting difficulty and name to fields in main class.

void Options::on_startButton_clicked()
{
    int temp = ui->nameText->toPlainText().size();
    if (difficulty == 0 || ui->nameText->toPlainText() == "")
    {
        QMessageBox::warning(this,"Warning","You haven't filled in all criteria");
        if (temp > 9)
        {
            QMessageBox::warning(this,"Warning","Only 9 characters allowed in the name");

        }
    }
    else {
        int bestscore = 0;
        // Let's get our heighest score from the DB
        SQLWrapper *sql = new SQLWrapper();
        if (!sql->isConValid()){
            qDebug() << "NoSQL Connection";
        }
        else
        {
            bestscore = sql->getHighestScore(difficulty);
        }


        // And let start the new game
        Pacmanwindow *w = new Pacmanwindow;

        QString nametemp = ui->nameText->toPlainText();

        w->parseMessage(nametemp, difficulty, bestscore);

        w->show();
        this->close();
    }
}

/**
 * Manage clicking on leaderboard
 * @brief Options::on_leaderBoard_clicked
 */
void Options::on_leaderBoard_clicked()
{
    LeaderBoard *w = new LeaderBoard;
    w->show();
    this->close();
}

/**
 * Let's go to Database settings
 *
 * @brief Options::on_dbSettings_clicked
 */
void Options::on_dbSettings_clicked()
{
    DB_Settings *db = new DB_Settings;
    db->show();
    this->close();
}
// When a radio button is pressed set the current number to the point that was pressed.
void Options::on_easyButton_toggled(bool )
{
    difficulty = 1;
}

void Options::on_mediumButton_toggled(bool )
{
    difficulty = 2;
}

void Options::on_hardButton_toggled(bool )
{
    difficulty = 3;
}
