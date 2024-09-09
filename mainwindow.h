#ifndef MAINWINDOW_H
#define MAINWINDOW_h

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
#include <QDir>


class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    void playVideoFile(QString videoFile);

private slots:
    void play();
    void ff();
    void rw();
    void volUp();
    void volDown();
    void mediaStateChanged(QMediaPlayer::State state);
    void toggleFullScreen();

private:
    QMediaPlayer* mediaPlayer;
    QVideoWidget* videoWidget;
    QShortcut* shortcut_toggle_play_pause;
    QShortcut* shortcut_toggle_full_screen;
    QShortcut* shortcut_quit;
    QShortcut* shortcut_ff;
    QShortcut* shortcut_rw;
    QShortcut* shortcut_vol_up;
    QShortcut* shortcut_vol_down;
    QString dir;
    bool fs;

};

#endif // MAINWINDOW_h
