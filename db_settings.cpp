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

void DB_Settings::on_save_button_clicked()
{
    QSettings settings("Anavaro", "PacMan");
    QString DB_HOST = ui->db_host_input->toPlainText();
    QString DB_USER = ui->db_username_input->toPlainText();
    QString DB_PASS = ui->db_password_input->toPlainText();
    QString DB_NAME = ui->db_name_input->toPlainText();
    qDebug() << DB_HOST;
    settings.setValue("DB_HOST", DB_HOST);
    settings.setValue("DB_USER", DB_HOST);
    settings.setValue("DB_PASS", DB_HOST);
    settings.setValue("DB_NAME", DB_HOST);

    qDebug() << m_sSettingsFile;
}

/**
 * Function that should populate the settings window from settings.ini if we have it
 * @brief DB_Settings::populate
 */
void DB_Settings::populate()
{
    QSettings settings("Anavaro", "PacMan");
    QString DB_HOST = settings.value("DB_HOST", "").toString();
    QString DB_USER = settings.value("DB_USER", "").toString();
    QString DB_PASS = settings.value("DB_PASS", "").toString();
    QString DB_NAME = settings.value("DB_NAME", "").toString();
    ui->db_host_input->setPlainText(DB_HOST);
    ui->db_username_input->setPlainText(DB_USER);
    ui->db_password_input->setPlainText(DB_PASS);
    ui->db_name_input->setPlainText(DB_NAME);
}

