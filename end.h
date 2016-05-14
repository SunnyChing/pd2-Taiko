#ifndef END_H
#define END_H

#include<QGraphicsView>
#include<QGraphicsScene>
#include<QPushButton>
#include<QGraphicsTextItem>
#include"score.h"
#include"start.h"
#include <QGraphicsPixmapItem>

class End:public QGraphicsView
{
    Q_OBJECT
public:
    End();
    ~End(){qDebug()<<"End is delete";}
    QGraphicsScene *endscene;
    QPushButton *bt_end;
    QPushButton *bt_restart;
    QGraphicsTextItem * displscore;
    QGraphicsPixmapItem *end_bg;
    Start * start;
    void setfinalscore(int n);

public slots:
    void exitgame();
    void restartgame();
private:
    int finalscore=0;
};

#endif // END_H
