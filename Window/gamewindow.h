#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QObject>
#include <QWidget>
#include <mylabel.h>

class GameWindow : public QWidget
{
    Q_OBJECT
public:
    explicit GameWindow(QWidget *parent = nullptr);

        QLabel *Showlabel;//界面说明
    myLabel* GameWindow_backgroud;

    void KeyPress(QKeyEvent *ev);
    void KeyRelease(QKeyEvent *ev);
    void ALLHIDE();
    void ALLSHOW();
signals:
    void signal_BacktoMain();
public slots:
    void init();
    void ToMain();
};

#endif // GAMEWINDOW_H
