#ifndef DRUM_H
#define DRUM_H
#include<QGraphicsRectItem>
#include<QGraphicsEllipseItem>
#include<QKeyEvent>
#include "elmo.h"
#include"good.h"
#include<QObject>
#include <QMediaPlayer>

class Drum: public QObject, public QGraphicsEllipseItem
{  Q_OBJECT
    public:
        Drum(QGraphicsItem * parent=0);
        void keyPressEvent(QKeyEvent *tic);
        Good * goodhit;

   public slots:
        void spawn();
   private:
        QMediaPlayer *tocsound;

};

#endif // DRUM_H
