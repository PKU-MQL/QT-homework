#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include<QGraphicsPixmapItem>
#include<QGraphicsView>
#include<QGraphicsScene>
#include<QKeyEvent>
#include<QTimer>
#include<QDebug>

namespace Ui {
class gamewindow;
}

class gamewindow : public QWidget
{
    Q_OBJECT

public:
    explicit gamewindow(QWidget *parent = nullptr);
    ~gamewindow();


private:
    Ui::gamewindow *ui;

signals:
    void signal_BacktoMain();

public slots:
    //界面跳转
    void init();
    void ToMain();
    void QuitMsg();
    //按键处理
    void keyChangeCallback();
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

public:
    //游戏界面元素
    QTimer* keyEventTimer;
    bool keyBook[20];
    int speed;
    int x,y;
    int angle;
    int window_width;
    int window_height;
    QGraphicsView vGameView;
    QGraphicsScene vGameScene;
    QGraphicsPixmapItem vBackground_1;
    QGraphicsPixmapItem vBall;
    QGraphicsPixmapItem vRacket_1;
    QGraphicsPixmapItem vRacket_2;
    QGraphicsPixmapItem vPlayer_1;
    QGraphicsPixmapItem vPlayer_2;
};

#endif // GAMEWINDOW_H
