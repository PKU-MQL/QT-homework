#include "description.h"
#include "ui_description.h"

Description::Description(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Description)
{
    ui->setupUi(this);
    connect(ui->pushButton,&QPushButton::clicked,this,&Description::ToMain);
}

Description::~Description()
{
    delete ui;
}

void Description::init(){
    ui->pushButton->show();
    ui->textEdit->show();
}

void Description::ToMain(){
    ui->pushButton->hide();
    ui->textEdit->hide();
    emit BacktoMain();
}
