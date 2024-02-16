#include "mainwindow.h"
#include <QWidget>
#include <QApplication>
#include <QCommandLineParser>
#include <QMainWindow>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow *mainWindow = new MainWindow();
    QCommandLineParser parser;
    parser.addPositionalArgument("videofile",  QCoreApplication::translate("main", "Video file to play."));
    parser.process(app);

    const QStringList args = parser.positionalArguments();


    mainWindow->playVideoFile(args.at(0));

    qApp->setOverrideCursor( QCursor( Qt::BlankCursor ) );
    mainWindow->resize(1024,768);
    mainWindow->show();
    return app.exec();
}

