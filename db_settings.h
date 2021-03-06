#ifndef DB_SETTINGS_H
#define DB_SETTINGS_H

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
#include "sqlwraper.h"


namespace Ui {
    class DB_Settings;
}

class DB_Settings : public QWidget
{
    Q_OBJECT

    public:
        explicit DB_Settings(QWidget *parent = 0);
        ~DB_Settings();
        QString msg;
        TextDrawing *text;
        void populate();
    private slots:
        void on_backBtn_clicked();
        void on_save_button_clicked();
        void on_installDBBtn_clicked();



    private:
     Ui::DB_Settings *ui;
     QGraphicsScene *scene;
     SQLWrapper *sql = new SQLWrapper();
     void checkState();
};


#endif // DB_SETTINGS_H
