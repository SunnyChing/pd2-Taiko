#include"elmo.h"
#include<QTimer>
#include<QGraphicsScene>

Elmo::Elmo(QGraphicsItem * parent): QObject(), QGraphicsPixmapItem(parent)
{
    // drew ELMO
       setPixmap(QPixmap(":/Elmo/elmo.png"));
      setPos(800,150);
    //connect
      QTimer *timer = new QTimer(this);
      connect(timer,SIGNAL(timeout()),this,SLOT(move()));
      timer -> start(50);
}

void Elmo::move()
{
    // move ELMO left
        setPos(x()-10,y());
        if (pos().x()  < 0){
                scene()->removeItem(this);
                delete this;
    }
}

CookieMonster::CookieMonster(QGraphicsItem *parent):Elmo(parent)
{
    // drew ELMO
       setPixmap(QPixmap(":/Elmo/cookiemster.png"));

}


