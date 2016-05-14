#include "good.h"
#include<QTimer>
#include<QDebug>

Good::Good(QGraphicsItem * parent): QObject(), QGraphicsPixmapItem(parent)
{    qDebug()<<"good";
    // drew Good
       setPixmap(QPixmap(":/Elmo/good1.png"));
       setPos(400,300);

       QTimer::singleShot(500,this,SLOT(deletegood()));


}

void Good::deletegood()
{
    delete this;
}
