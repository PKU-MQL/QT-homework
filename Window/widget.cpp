#include "widget.h"
#include <QLabel>
#include "mylabel.h"
#include "mybutton.h"
#include <QPushButton>
#include <QMessageBox>
#include "prewindow.h"
#include "description.h"
#include "ui_description.h"
#include <QDebug>
//主窗口函数，控制各界面出现的消失信号与槽函数的实现
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    mainbg=new myLabel(":/image/4.png",this);
    //背景贴图需要1280*960的大小
    mainbg->move(0,0);

    Showlabel=new QLabel("开始界面",this);
    Showlabel->move(640,100);

    setFocus();
    setFixedSize(1280,960);//重要++设定窗口大小
    setWindowIcon(QIcon(":/image/badminton_icon.png"));
    setWindowTitle("火柴人羽毛球");
    /*setWindowIcon(QIcon("://art/icon.ico"));
            setWindowTitle("砰碰砰大乱斗");*/

    //帮助界面 对象初始化
    m_helpwindow=new Description(this);
    m_helpwindow->move(320,240);
    m_helpwindow->hide();


    //准备界面 对象初始化
    m_prewindow=new PreWindow(this);
    m_prewindow->setFixedSize(this->size());
    //m_prewindow->move(0,0);
    m_prewindow->hide();

    //游戏界面 对象初始化
    m_gamewindow =new GameWindow(this);
    m_gamewindow->setFixedSize(this->size());
    m_gamewindow->hide();

    //暂停界面 对象初始化
    m_pausewindow=new PauseWindow(this);
    m_pausewindow->setFixedSize(this->size());
    //m_pausewindow->move(0,0);
    m_pausewindow->hide();


    //帮助按钮 后期可改成自定义类 加上动画和音乐特效
    //helpbutton=new QPushButton("帮助",this);
    helpbutton=new myButton(":/image/help.png",this);
    helpbutton->move(220,60);
    //connect(helpbutton,&QPushButton::clicked,this,&Widget::ToHelp);
    connect(helpbutton,&myButton::ButtonClicked,this,&Widget::ToHelp);
    connect(m_helpwindow,&Description::BacktoMain,this,&Widget::BackformHelp);


    //开始按钮 后期可改成自定义类
    //nextbutton=new QPushButton("开始!",this);
    nextbutton=new myButton(":/image/start.png",this);
    nextbutton->move(1000,750);
//    connect(nextbutton,&QPushButton::clicked,this,&Widget::ToPre);
    connect(nextbutton,&myButton::ButtonClicked,this,&Widget::ToPre);
    connect(m_prewindow,&PreWindow::signal_BacktoMain,this,&Widget::BackfromPre);
    connect(m_prewindow,&PreWindow::signal_ToGame,this,&Widget::ToGame);

    //退出选项
    //quitbutton=new QPushButton("退出",this);
    quitbutton=new myButton(":/image/exit.png",this);
    quitbutton->move(80,60);
    //connect(quitbutton,&QPushButton::clicked,this,&Widget::QuitMsg);
    connect(quitbutton,&myButton::ButtonClicked,this,&Widget::QuitMsg);


}

Widget::~Widget()
{

}


//处理游戏界面的按键 上下左右 esc等等
void Widget::keyPress(QKeyEvent *ev){
    m_gamewindow->KeyPress(ev);
    return ;
}
void Widget::keyRelease(QKeyEvent *ev){
    m_gamewindow->KeyRelease(ev);
    return ;
}

void Widget::QuitMsg(){//退出消息提醒
    int res = QMessageBox::question(nullptr,"WARNING","Are you sure to exit？", QMessageBox::Yes|QMessageBox::No, QMessageBox::NoButton);
    if(res == QMessageBox::Yes){
        this->close();
    }
}
void Widget::ALLHIDE(){//隐藏主界面所有
    quitbutton->hide();
    nextbutton->hide();
    helpbutton->hide();
    Showlabel->hide();
    mainbg->hide();
}
void Widget::ALLSHOW(){//显示主界面所有
    mainbg->show();
    quitbutton->show();
    nextbutton->show();
    helpbutton->show();
    Showlabel->show();
}
void Widget::ToHelp(){//前往帮助界面
    ALLHIDE();
    m_helpwindow->show();
    m_helpwindow->init();
}
void Widget::ToPre(){//前往准备界面
    ALLHIDE();
    qDebug()<<tr("前往准备界面--------");
    m_prewindow->show();
    m_prewindow->init();
}
void Widget::ToGame(){//前往游戏界面
    ALLHIDE();
    qDebug()<<tr("前往游戏界面");
    m_gamewindow->show();
}
void Widget::BackformHelp(){//从帮助界面返回
    m_helpwindow->hide();
    ALLSHOW();
}
void Widget::BackfromPre(){//从准备界面返回
    m_prewindow->hide();
    ALLSHOW();
}
