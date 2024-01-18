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


class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    void playVideoFile(QString videoFile);

private slots:
    void play();
    void ff();
    void rw();

private:
    QMediaPlayer* mediaPlayer;
    QVideoWidget* videoWidget;
    QShortcut* shortcut_toggle_play_pause;
    QShortcut* shortcut_quit;
    QShortcut* shortcut_ff;
    QShortcut* shortcut_rw;


};

#endif // MAINWINDOW_h
