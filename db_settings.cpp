#include "db_settings.h"
#include "ui_db_settings.h"
#include <QThread>
#include <QtWidgets>
#include "options.h"
#include "sqlwraper.h"
#include <QSettings>


DB_Settings::DB_Settings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DB_Settings)
    {
        QLabel *image = new QLabel();
               image->setPixmap( QPixmap( "paclogo.jpg" ) );
               image->show();
            ui->setupUi(this);

            this->populate();
    }


DB_Settings::~DB_Settings()
{
    delete ui;
}

/**
 * We need a back button
 * @brief DB_Settings::on_backBtn_clicked
 */
void DB_Settings::on_backBtn_clicked()
{
    Options *w = new Options;
    w->show();
    this->close();
}

/**
 * Function that should populate the settings window from settings.ini if we have it
 * @brief DB_Settings::populate
 */
void DB_Settings::populate()
{
    m_sSettingsFile = QApplication::applicationDirPath().left(1) + ":/settings.ini";
    QSettings settings(m_sSettingsFile, QSettings::NativeFormat);
    QString sText = settings.value("text", "").toString();
}
