#include "mainwindow.h"
#include <QApplication>
#include "recipe.h"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/img/book_icon.ico"));
    MainWindow w;
    w.show();

    return a.exec();
}
