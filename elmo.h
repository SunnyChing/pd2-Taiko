#ifndef ELMO_H
#define ELMO_H
#include <QGraphicsPixmapItem>
#include <QObject>

class Elmo: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Elmo(QGraphicsItem * parent=0);
public slots:
    void move();
};



class CookieMonster: public Elmo{
    Q_OBJECT
public:
    CookieMonster(QGraphicsItem * parent=0);

};




#endif // ELMO_H
