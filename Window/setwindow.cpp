#include "setwindow.h"
#include "ui_setwindow.h"

SetWindow::SetWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SetWindow)
{
    ui->setupUi(this);
    connect(ui->pushButtonBack,&QPushButton::clicked,this,&SetWindow::ToMain);
    connect(ui->pushButtonBegin,&QPushButton::clicked,this,&SetWindow::ToGame);
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

}
void SetWindow::ToMain(){
    emit signal_BacktoMain();
}
void SetWindow::ToGame(){
    emit signal_ToGame();
}
