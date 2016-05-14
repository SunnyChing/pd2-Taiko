#ifndef GOOD_H
#define GOOD_H

#include<QGraphicsTextItem>
#include<Qdebug>

class Good: public QObject,public QGraphicsPixmapItem
{ Q_OBJECT
public:
    Good(QGraphicsItem * parent=0);
    ~Good(){qDebug()<<"del good";}
public slots:
    void deletegood();
};
#endif // GOOD_H
