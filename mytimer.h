#ifndef MYTIMER_H
#define MYTIMER_H

#include<QGraphicsTextItem>
#include<QtCore>

class MyTimer :public QGraphicsTextItem{
    Q_OBJECT
public:
    MyTimer(const int n,QGraphicsItem * parent=0);
    //QTimer *mytimer;
    int gametime;

public slots:
    void decrease();



};
#endif // MYTIMER_H
