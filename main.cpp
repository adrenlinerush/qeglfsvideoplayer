#include <QStyle>
#include <QWidget>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QPushButton>
#include <QSlider>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QShortcut>
#include <QKeySequence>
#include <QApplication>
#include <QCommandLineParser>
#include <QMainWindow>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QMainWindow *mainWindow = new QMainWindow();
    QCommandLineParser parser;
    parser.addPositionalArgument("videofile",  QCoreApplication::translate("main", "Video file to play."));
    parser.process(app);

    const QStringList args = parser.positionalArguments();

    QMediaPlayer* mediaPlayer = new QMediaPlayer;
    QVideoWidget* videoWidget = new QVideoWidget;
    mediaPlayer->setVideoOutput(videoWidget);

    QShortcut* shortcut_quit = new QShortcut(QKeySequence("Q"), mainWindow);
    mainWindow->connect(shortcut_quit, &QShortcut::activated, qApp, &QApplication::quit);

    mediaPlayer->setMedia(QUrl::fromLocalFile(args.at(0)));
    mediaPlayer->play();

    mainWindow->setCentralWidget(videoWidget);
    mainWindow->show();
    return app.exec();
}

