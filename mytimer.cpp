#include"mytimer.h"
#include<QFont>
#include"game.h"
#include<QObject>

MyTimer::MyTimer(const int n,QGraphicsItem *parent):  QGraphicsTextItem(parent)
{
    //mytimer=new QTimer();
    gametime=n;
     //draw the text
    setPlainText(QString("Time: ") + QString::number(gametime)); // Time: 30
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",24));


}

void MyTimer::decrease()
{
    gametime--;
    setPlainText(QString("Time: ") + QString::number(gametime));

}
