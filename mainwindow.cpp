#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent) {
	
    fs = false;
    mediaPlayer = new QMediaPlayer;
    videoWidget = new QVideoWidget;
    mediaPlayer->setVideoOutput(videoWidget);

    dir = QDir::currentPath();

    shortcut_quit = new QShortcut(QKeySequence("Q"), this);
    connect(shortcut_quit, &QShortcut::activated, qApp, &QApplication::quit);
    shortcut_toggle_play_pause = new QShortcut(QKeySequence("P"), this);
    connect(shortcut_toggle_play_pause, &QShortcut::activated, this, &MainWindow::play);
    shortcut_ff = new QShortcut(QKeySequence(Qt::Key_Right), this);
    connect(shortcut_ff, &QShortcut::activated, this, &MainWindow::ff);
    shortcut_rw = new QShortcut(QKeySequence(Qt::Key_Left), this);
    connect(shortcut_rw, &QShortcut::activated, this, &MainWindow::rw);
    shortcut_vol_up = new QShortcut(QKeySequence(Qt::Key_Up), this);
    connect(shortcut_vol_up, &QShortcut::activated, this, &MainWindow::volUp);
    shortcut_vol_down = new QShortcut(QKeySequence(Qt::Key_Down), this);
    connect(shortcut_vol_down, &QShortcut::activated, this, &MainWindow::volDown);

    connect(mediaPlayer, &QMediaPlayer::stateChanged, this, &MainWindow::mediaStateChanged);

    shortcut_toggle_full_screen = new QShortcut(QKeySequence("F"), this);
    connect(shortcut_toggle_full_screen, &QShortcut::activated, this, &MainWindow::toggleFullScreen);

    setStyleSheet("background-color: black;");
    setCentralWidget(videoWidget);
}

void MainWindow::playVideoFile(QString videoFile){
    if (videoFile.front() != "/") {
	    videoFile = dir + "/" +  videoFile;
    }
    mediaPlayer->setMedia(QUrl::fromLocalFile(videoFile));
    mediaPlayer->play();
}

void MainWindow::play()
{
    if (mediaPlayer->state() == QMediaPlayer::PlayingState) {
        mediaPlayer->pause();
    } else {
        mediaPlayer->play();
    }
}

void MainWindow::ff()
{
    int pos = mediaPlayer->position();
    mediaPlayer->setPosition(pos+5000);
}

void MainWindow::rw()
{
    int pos = mediaPlayer->position();
    mediaPlayer->setPosition(pos-5000);
}

void MainWindow::volUp()
{
    int vol = mediaPlayer->volume();
    mediaPlayer->setVolume(vol+10);
}
void MainWindow::volDown()
{
    int vol = mediaPlayer->volume();
    mediaPlayer->setVolume(vol-10);
}

void MainWindow::mediaStateChanged(QMediaPlayer::State state)
{
    if (state == QMediaPlayer::StoppedState) {
        qApp->quit();
    } 
}

void MainWindow::toggleFullScreen()
{
	if (fs == true) {
		setWindowFlags(NULL);
		fs = false;
		showMaximized();
	} else {
		setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint);
		fs = true;
		showMaximized();
	}
}
