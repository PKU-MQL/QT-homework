#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include "mylabel.h"
#include "mybutton.h"
#include "prewindow.h"
#include "pausewindow.h"
#include "gamewindow.h"

#include "description.h"
#include "ui_description.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = NULL);
    ~Widget();

public:
    void ALLHIDE();
    void ALLSHOW();
    void QuitMsg();

    void ToPre();
    void ToHelp();
    void ToGame();

    void BackfromPre();
    void BackformHelp();

    void keyPress(QKeyEvent *ev);
    void keyRelease(QKeyEvent *ev);
private:
    myLabel *mainbg;
//    QPushButton* quitbutton;
//    QPushButton* nextbutton;
//    QPushButton* helpbutton;
    myButton* quitbutton;
    myButton* nextbutton;
    myButton* helpbutton;
    QLabel *Showlabel;//界面说明


    PreWindow* m_prewindow;//准备界面
    PauseWindow* m_pausewindow;//暂停界面
    Description* m_helpwindow;//描述界面
    GameWindow* m_gamewindow;//游戏界面

};

#endif // WIDGET_H
