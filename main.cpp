#include <QApplication>
#include "options.h"
#include "sqlwraper.h"
#include <QSettings>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Request settings
    QSettings settings("Anavaro", "PacMan");
    QString DB_HOST = settings.value("DB_HOST", "").toString();
    QString DB_USER = settings.value("DB_USER", "").toString();
    QString DB_PASS = settings.value("DB_PASS", "").toString();
    QString DB_NAME = settings.value("DB_NAME", "").toString();

    // Let's open SQL connection on application start so we don't freeze on event.
    SQLWrapper *sql = new SQLWrapper();
    sql->openDB(DB_HOST, DB_USER, DB_PASS, DB_NAME);

    Options o;
    o.show();

    return a.exec();
}
