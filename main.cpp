#include <QApplication>
#include "options.h"
#include "sqlwraper.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Let's open SQL connection on application start so we don't freeze on event.
    SQLWrapper *sql = new SQLWrapper();
    sql->openDB();

    Options o;
    o.show();

    return a.exec();
}
