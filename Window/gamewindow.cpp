#include "gamewindow.h"
#include "ui_gamewindow.h"
#include <QMessageBox>
gamewindow::gamewindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gamewindow)
{
    ui->setupUi(this);

    window_width=1280;
    window_height=720;
    //setFixedSize(window_width,window_height+80);
    memset(keyBook,false,sizeof(keyBook));
    speed=1;
    x=this->width()/2;
    y=this->height()/2;
    keyEventTimer=new QTimer();
    QObject::connect(keyEventTimer,SIGNAL(timeout()),this,SLOT(keyChangeCallback()));
    keyEventTimer->start(10);


    vGameView.setSceneRect(QRect(0,0,window_width,window_height));
    vGameView.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    vGameView.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    vGameScene.setSceneRect(QRect(0,0,window_width,window_height));

    vBackground_1.setPixmap(QPixmap(":/image/test_background_2_720p.png"));

    vBall.setPixmap(QPixmap(":/image/badminton_default.png"));
    vBall.setPos(x,y);
    vBall.setTransformOriginPoint(vBall.boundingRect().center());


    vPlayer_1.setPixmap(QPixmap(":/image/player_default"));
    vPlayer_1.setPos(x,y);
    vPlayer_1.setTransformOriginPoint(vPlayer_1.boundingRect().center());

    vRacket_1.setPixmap(QPixmap(":/image/racket"));
    vRacket_1.setTransformOriginPoint(vRacket_1.boundingRect().center());
    angle=0;
    vRacket_1.setRotation(angle);


    vGameScene.addItem(&vBackground_1);
    vGameScene.addItem(&vBall);
    vGameScene.addItem(&vPlayer_1);
    vGameScene.addItem(&vRacket_1);
    vRacket_1.setParentItem(&vPlayer_1);

    vGameView.setFocusPolicy(Qt::NoFocus);//防止GraphicView类对方向键的占用
    vGameView.setScene(&vGameScene);
    vGameView.setParent(this);

    QPalette lcdpat=ui->scoreboard_1->palette();
    lcdpat.setColor(QPalette::Normal,QPalette::WindowText,Qt::red);
    ui->scoreboard_1->setPalette(lcdpat);
    ui->scoreboard_2->setPalette(lcdpat);

    //connect(ui->pushButton,&QPushButton::clicked,this,&gamewindow::ToMain);
    connect(ui->pushButton,&QPushButton::clicked,this,&gamewindow::QuitMsg);
}

gamewindow::~gamewindow()
{
    delete ui;
    delete keyEventTimer;
}

void gamewindow::init(){
    this->show();
}
void gamewindow::ToMain(){
    this->hide();//重复隐藏，可删去
    emit signal_BacktoMain();
}
void gamewindow::QuitMsg(){
    int res=QMessageBox::question(nullptr,"提醒","是否确认退出比赛？", QMessageBox::Yes|QMessageBox::No, QMessageBox::NoButton);
    if(res==QMessageBox::Yes){
        ToMain();
    }
}


void gamewindow::keyPressEvent(QKeyEvent* event){
    qDebug()<<"into keyPressEvent--------"<<endl;
    auto key = event->key();
    switch(key){
    case Qt::Key_W: keyBook[0] = true;break;
    case Qt::Key_S: keyBook[1] = true;break;
    case Qt::Key_A: keyBook[2] = true;break;
    case Qt::Key_D: keyBook[3] = true;break;
    case Qt::Key_Up: keyBook[4] = true;break;
    case Qt::Key_Down: keyBook[5] = true;break;
    case Qt::Key_Left: keyBook[6] = true;break;
    case Qt::Key_Right: keyBook[7] = true;break;
    case Qt::Key_Escape: QuitMsg();break;

    }


}

void gamewindow::keyReleaseEvent(QKeyEvent *event){
    auto key = event->key();
    switch(key){
    case Qt::Key_W:keyBook[0]= false;break;
    case Qt::Key_S:keyBook[1]= false;break;
    case Qt::Key_A:keyBook[2]= false;break;
    case Qt::Key_D:keyBook[3]= false;break;
    case Qt::Key_Up: keyBook[4] = false;break;
    case Qt::Key_Down: keyBook[5] = false;break;
    case Qt::Key_Left: keyBook[6] = false;break;
    case Qt::Key_Right: keyBook[7] =false;break;
    }
}

void gamewindow::keyChangeCallback(){
    //qDebug()<<"into keyChangeCallback,angle="<<angle<<endl;
    if(keyBook[0]) y-=speed;
    if(keyBook[1]) y+=speed;
    if(keyBook[2]) x-=speed;
    if(keyBook[3]) x+=speed;
    if(keyBook[4]) angle++;
    if(keyBook[5]) angle--;

    vPlayer_1.setPos(x,y);
    vRacket_1.setRotation(angle);
    ui->scoreboard_1->display(abs(x)%10);
    ui->scoreboard_2->display(abs(y)%10);

}
