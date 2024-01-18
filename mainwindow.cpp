#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent) {
	
    mediaPlayer = new QMediaPlayer;
    videoWidget = new QVideoWidget;
    mediaPlayer->setVideoOutput(videoWidget);

    shortcut_quit = new QShortcut(QKeySequence("Q"), this);
    connect(shortcut_quit, &QShortcut::activated, qApp, &QApplication::quit);
    shortcut_toggle_play_pause = new QShortcut(QKeySequence("P"), this);
    connect(shortcut_toggle_play_pause, &QShortcut::activated, this, &MainWindow::play);
    shortcut_ff = new QShortcut(QKeySequence(Qt::Key_Right), this);
    connect(shortcut_ff, &QShortcut::activated, this, &MainWindow::ff);
    shortcut_rw = new QShortcut(QKeySequence(Qt::Key_Left), this);
    connect(shortcut_rw, &QShortcut::activated, this, &MainWindow::rw);

    setCentralWidget(videoWidget);
}

void MainWindow::playVideoFile(QString videoFile){
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
