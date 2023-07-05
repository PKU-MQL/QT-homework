#include "setwindow.h"
#include "ui_setwindow.h"
#include <QButtonGroup>
SetWindow::SetWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SetWindow)
{
    ui->setupUi(this);

    //新建状态虚拟分组，添加玩家1角色选择情况
    m_player1 =new QButtonGroup(this);
    m_player1->addButton(ui->radioButton11,1);
    m_player1->addButton(ui->radioButton12,2);
    m_player1->addButton(ui->radioButton13,3);
    m_player1->addButton(ui->radioButton14,4);

    //新建状态虚拟分组，添加玩家2角色选择情况
    m_player2 =new QButtonGroup(this);
    m_player2->addButton(ui->radioButton21,1);
    m_player2->addButton(ui->radioButton22,2);
    m_player2->addButton(ui->radioButton23,3);
    m_player2->addButton(ui->radioButton24,4);

    //关联角色选择和调试输出
    connect(m_player1,QOverload<int>::of(&QButtonGroup::buttonClicked),this,&SetWindow::RecvPlayer1);
    connect(m_player2,QOverload<int>::of(&QButtonGroup::buttonClicked),this,&SetWindow::RecvPlayer2);


    connect(ui->pushButtonBack,&QPushButton::clicked,this,&SetWindow::ToMain);
    connect(ui->pushButtonBegin,&QPushButton::clicked,this,&SetWindow::ToGame);

    //初始默认都是第一个角色
    ui->radioButton11->setChecked(true);
    ui->radioButton21->setChecked(true);
}

SetWindow::~SetWindow()
{
    delete ui;
}

void SetWindow::init(){
    ui->BackGround->show();
    ui->pushButtonBack->show();
    ui->pushButtonBegin->show();
    ui->groupBox->show();
    ui->groupBox_2->show();

    ui->labelplayer1->show();
    ui->labelplayer2->show();

    ui->label_intro1->show();
    ui->label_intro2->show();
}
void SetWindow::ToMain(){
    emit signal_BacktoMain();
}
void SetWindow::ToGame(){
    emit signal_ToGame();
}

//接收角色选择情况的信号，传递角色属性给游戏界面
void SetWindow::RecvPlayer1(int id){
    QString formattedText;
    switch(id){
    case 1:
        qDebug()<<tr("Player1_1");
        formattedText="<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">IKUN 只因你太美</span></p><p><span style=\" font-size:14pt; font-weight:600;\">移动速度：1</span></p><p><span style=\" font-size:14pt; font-weight:600;\">跳跃高度：1</span></p><p><span style=\" font-size:14pt; font-weight:600;\">击球力度：4</span></p></body></html>";
        //ui->label_intro1->setText("INKUN 只因你太美\n移动速度：5\n跳跃高度：1\n击球力度：4\n");
        break;
    case 2:
        qDebug()<<tr("Player1_2");
        formattedText= "<html><head/><body><p><span style=\"font-size:14pt; font-weight:600;\">郭神 启动!</span></p><p><span style=\"font-size:14pt; font-weight:600;\">移动速度：5</span></p><p><span style=\"font-size:14pt; font-weight:600;\">跳跃高度：2</span></p><p><span style=\"font-size:14pt; font-weight:600;\">击球力度：3</span></p></body></html>";
        //ui->label_intro1->setText(formattedText);
        break;
    case 3:
        qDebug()<<tr("Player1_3");
        formattedText= "<html><head/><body><p><span style=\"font-size:14pt; font-weight:600;\">路人甲 打酱油的</span></p><p><span style=\"font-size:14pt; font-weight:600;\">移动速度：4</span></p><p><span style=\"font-size:14pt; font-weight:600;\">跳跃高度：3</span></p><p><span style=\"font-size:14pt; font-weight:600;\">击球力度：4</span></p></body></html>";
        //ui->label_intro1->setText(formattedText);
        break;
    case 4:
        qDebug()<<tr("Player1_4");
        formattedText= "<html><head/><body><p><span style=\"font-size:14pt; font-weight:600;\">绿头鸭 嘎嘎</span></p><p><span style=\"font-size:14pt; font-weight:600;\">移动速度：2</span></p><p><span style=\"font-size:14pt; font-weight:600;\">跳跃高度：1</span></p><p><span style=\"font-size:14pt; font-weight:600;\">击球力度：2</span></p></body></html>";

        break;
    default:
        break;
    }
    ui->label_intro1->setText(formattedText);
}
void SetWindow::RecvPlayer2(int id){
    QString formattedText;
    switch(id){
    case 1:
        qDebug()<<tr("Player2_1");
        formattedText="<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">IKUN 只因你太美</span></p><p><span style=\" font-size:14pt; font-weight:600;\">移动速度：1</span></p><p><span style=\" font-size:14pt; font-weight:600;\">跳跃高度：1</span></p><p><span style=\" font-size:14pt; font-weight:600;\">击球力度：4</span></p></body></html>";
        break;
    case 2:
        qDebug()<<tr("Player2_2");
        formattedText= "<html><head/><body><p><span style=\"font-size:14pt; font-weight:600;\">郭神 启动!</span></p><p><span style=\"font-size:14pt; font-weight:600;\">移动速度：5</span></p><p><span style=\"font-size:14pt; font-weight:600;\">跳跃高度：2</span></p><p><span style=\"font-size:14pt; font-weight:600;\">击球力度：3</span></p></body></html>";
        break;
    case 3:
        qDebug()<<tr("Player2_3");
        formattedText= "<html><head/><body><p><span style=\"font-size:14pt; font-weight:600;\">路人甲 打酱油的</span></p><p><span style=\"font-size:14pt; font-weight:600;\">移动速度：4</span></p><p><span style=\"font-size:14pt; font-weight:600;\">跳跃高度：3</span></p><p><span style=\"font-size:14pt; font-weight:600;\">击球力度：4</span></p></body></html>";
        break;
    case 4:
        qDebug()<<tr("Player2_4");
        formattedText= "<html><head/><body><p><span style=\"font-size:14pt; font-weight:600;\">绿头鸭 嘎嘎</span></p><p><span style=\"font-size:14pt; font-weight:600;\">移动速度：2</span></p><p><span style=\"font-size:14pt; font-weight:600;\">跳跃高度：1</span></p><p><span style=\"font-size:14pt; font-weight:600;\">击球力度：2</span></p></body></html>";
        break;
    default:
        break;
    }
    ui->label_intro2->setText(formattedText);
}
//处理主界面的esc enter space
void SetWindow::keyPressEvent(QKeyEvent *event){
    qDebug()<<"SetWindow into keyPressEvent--------"<<endl;
    auto key = event->key();
    switch (key) {
        case Qt::Key_Escape:ToMain();break;
        case Qt::Key_Space:ToGame();break;
        default:break;
    }
    key=NULL;
    return ;
}
