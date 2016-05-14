#ifndef SCORE_H
#define SCORE_H
#include<QGraphicsTextItem>
#include<QDebug>


class Score: public QGraphicsTextItem
{
public:
    Score(QGraphicsItem * parent=0);
    ~Score(){qDebug()<<"dtr score";}
    void increase();
    int getscore();
    int score=0;
};



#endif // SCORE_H
