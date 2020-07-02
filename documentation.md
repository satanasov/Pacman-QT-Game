# Pacman QT with PostgresSQL

## Per file description

### main.cpp

> Depends on:
> * options.cpp
> * sqlwrapper.cpp
> * < QSettings >
> * < QApplication >

#### main

Main executable function

> @brief main
>
> @param argc - command line paramer count
>
> @param argv - parameters passed to executable.
>
> @return

### sqlwrapper.cpp

>Depends on:
> * < QSql >
> * < QSqlDatabase >
> * < QSqlError >
> * < QSqlQuery >
> * < QDateTime >
> * < QDebug >
> * < QMessageBox >
> * < QObject >

All DB related functions are in this file

#### void SQLWrapper::openDB(QString host, QString username, QString pass, QString dbname)

Function used to open connection to the DB. On error it will popup message with the error faced.

Accepts QString parameters for host, username, password and DB name

> * @brief SQLWrapper::openDB
> * @param host
> * @param username
> * @param pass
> * @param dbname

#### void SQLWrapper::closeDB()

Function used to close DB connection.

> * @brief SQLWrapper::closeDB

#### bool SQLWrapper::isConValid()

Expose isOpen() for DB object

> * @brief SQLWrapper::isConValid
> * @return bool

#### bool SQLWrapper::isStructValid()

Check if table exists

>* @brief SQLWrapper::isStructValid
>* @return bool

#### QString SQLWrapper::getError()

Expose lastError()

>* @brief SQLWrapper::getError
>* @return QString

#### void SQLWrapper::deployTable()

Deploy table if the table is invalid

>* @brief SQLWrapper::deployTable

#### QList<QList<QString>> SQLWrapper::loadLeaderBoard()

Base function to populate the leader board and format the leaderbord text.

>* @brief SQLWrapper::loadLeaderBoard
>* @return QStringList

#### funtion int SQLWrapper::getHighestScore(int dificulty)

Get highest score for difficulty

>* @brief SQLWrapper::getHighestScore
>* @param difficulty
>* @return int

#### void SQLWrapper::sendData(QString name, int score, int difficulty, int time)

Send data to database (name, score, dificulty, time)

>* @brief SQLWrapper::sendData
>* @param name
>* @param score
>* @param difficulty
>* @param time

#### QList<QList<QString>>SQLWrapper::getRelativePosition(QString name, int score, int difficulty)

Get relative position based on name, score and difficulty

>* @brief SQLWrapper::getRelativePosition
>* @param name
>* @param score
>* @param difficulty
>* @return

### options.cpp

> Depends on:
> * pacmanwindow.cpp
> * leaderboard.cpp
> * sqlwraper.cpp
> * db_settings.cpp
> * < QDebug >

This is main screen of the game and take care of some ongoing drawing and user communication.

#### void Options::on_startButton_clicked()

When start button is pressed, error handling, setting difficulty and name to fields in main class.

> * @brief Options::on_startButton_clicked

#### void Options::on_leaderBoard_clicked()

Manage clicking on leaderboard

>* @brief Options::on_leaderBoard_clicked

#### void Options::on_dbSettings_clicked()

Let's go to Database settings

>* @brief Options::on_dbSettings_clicked

#### void Options::on_easyButton_toggled(bool )
#### void Options::on_mediumButton_toggled(bool )
#### void Options::on_hardButton_toggled(bool )

These functions set the difficulty

### db_settings.cpp

>Depends on:
> * options.cpp
> * sqlwraper.cpp
> * < QThread >
> * < QtWidgets >
> * < QSettings >

This file handles DB settings UI.

#### void DB_Settings::on_backBtn_clicked()

A back button to settings.

>* @brief DB_Settings::on_backBtn_clicked

#### void DB_Settings::on_save_button_clicked()

Action for save button. Save settings to sittings and test new connection

>* @brief DB_Settings::on_save_button_clicked

#### void DB_Settings::on_installDBBtn_clicked()

DB Deploy button. If we have connection but we don't have the table - deploy the table.

>* @brief DB_Settings::on_installDBBtn_clicked

#### void DB_Settings::populate()

Function that should populate the settings window from settings.ini if we have it

>* @brief DB_Settings::populate

#### void DB_Settings::checkState()

Private function that is related to graphics on this screen - Display OK and Error images on states
 > * @brief DB_Settings::checkState

### leaderbord.cpp

> Depends on:
> * < QThread >
> * < QtWidgets>
> * options.cpp
> * sqlwraper.cpp

This file is displaying the leaderboard for the game.

#### void LeaderBoard::on_backBtn_clicked()

Back button

> * @brief LeaderBoard::on_backBtn_clicked

#### void LeaderBoard::populate()

Function that should populate the leader board

>  * @brief LeaderBoard::populate


### pacmanwindow.cpp

>Depends on:
> * < QThread >
> * < QtWidgets >
> * options.cpp
> * sqlwraper.cpp

Main game window. The game logic and all is here

#### void Pacmanwindow::parseMessage(QString name, int temp, int bestscore)

Set player name, difficulty and bestscore

>* @brief Pacmanwindow::parseMessage
>* @param name
>* @param temp
>* @param bestscore


#### Pacmanwindow::start_Game()

A Method used to start the game both at the beginning, on new level and if there is a game over

>* @brief Pacmanwindow::start_Game

#### void Pacmanwindow::easy(){
#### void Pacmanwindow::medium(){
#### void Pacmanwindow::hard(){

Method used to set the difficulty

#### void Pacmanwindow::end_Game()

A method called when all lives are depleted resulting in changing the values.

>* @brief Pacmanwindow::end_Game

#### void Pacmanwindow::retry()

This code is used when one of the lives are taken.

> * @brief Pacmanwindow::retry

#### void Pacmanwindow::pacman_move()

Method for pacmans movenment and wall collisions etc..

> * @brief Pacmanwindow::pacman_move

#### void Pacmanwindow::ghostsmove()
#### void Pacmanwindow::ghostsmove1()
#### void Pacmanwindow::ghostsmove2()
#### void Pacmanwindow::ghostsmove3()

Moving ghosts around the map

#### void Pacmanwindow::moveghostsinrect3()
#### void Pacmanwindow::moveghostsinrect2()
#### void Pacmanwindow::moveghostsinrect1()
#### void Pacmanwindow::moveghostsinrect()

Keep ghosts in the lines.

#### void Pacmanwindow::checklost()

This method is used to check for collisions with the ghosts and balls

>* @brief Pacmanwindow::checklost

#### void Pacmanwindow::keyPressEvent(QKeyEvent * event)

method to evoke key pressing.

> * @brief Pacmanwindow::keyPressEvent
> * @param event

#### void Pacmanwindow::updater()

This updates the pacman with the use of timer connection

>* @brief Pacmanwindow::updater

#### void Pacmanwindow::pause()

This pauses the timer.

>* @brief Pacmanwindow::pause

#### void Pacmanwindow::ghostupdater()

This is an individual update for the ghosts, as they run on a seperate timer.

>* @brief Pacmanwindow::ghostupdater

#### void Pacmanwindow::on_pauseButton_clicked()

When pause button clicked pause the timer

>* @brief Pacmanwindow::on_pauseButton_clicked

#### void Pacmanwindow::on_controlsButton_clicked()

When controls buttons is clicked

>* @brief Pacmanwindow::on_controlsButton_clicked
