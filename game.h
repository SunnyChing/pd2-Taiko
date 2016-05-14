#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include<QGraphicsItemGroup>
#include<QLabel>
#include<QObject>
#include "Score.h"
#include "drum.h"
#include"mytimer.h"

class Game:public QGraphicsView
{
    Q_OBJECT

public:
    Game();
    QGraphicsScene * scene;
    Score * score;
    Drum * drum;
    MyTimer *mytimer;
    QMediaPlayer *gamebgm;
    QLabel * gamehelp;

    //countdown timer
    int gametime=30;
    QTimer * timer1;

    //spawn timer
    QTimer *timer;

public slots:
    void endgame();
};

#endif // GAME_H
