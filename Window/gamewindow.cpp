#include "gamewindow.h"

GameWindow::GameWindow(QWidget *parent) : QWidget(parent)
{
    GameWindow_backgroud = new myLabel(":/image/8.png",this);
    GameWindow_backgroud->move(0,0);

    Showlabel=new QLabel("游戏界面",this);
    Showlabel->move(640,100);

}
void GameWindow::ALLSHOW(){
    GameWindow_backgroud->show();
    Showlabel->show();
}
void GameWindow::ALLHIDE(){
    GameWindow_backgroud->hide();
    Showlabel->hide();
}
void GameWindow::KeyPress(QKeyEvent *ev){

}
void GameWindow::KeyRelease(QKeyEvent *ev){

}

void GameWindow::init(){
    ALLSHOW();
}

void GameWindow::ToMain(){
    ALLHIDE();
    emit signal_BacktoMain();
}
