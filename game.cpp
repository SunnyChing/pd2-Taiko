#include"game.h"
#include<QTimer>
#include <QMediaPlayer>
#include<QBrush>
#include<Qimage>
#include"end.h"
#include<Qdebug>
Game::Game()
{
    // create the scene
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,800,600); // make the scene 800x600 instead of infinity by infinity (default)
    setBackgroundBrush(QBrush(QImage(":/Elmo/bg.png")));

    // make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
        // it can be used to visualize scenes)
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    // create an item to put into the scene
     drum = new Drum();
    drum->setRect(0,0,70,70);
    Drum * drum1 = new Drum();
    drum1->setRect(0,0,45,45);
    // add the item to the scene
    scene->addItem(drum);
    scene->addItem(drum1);


    //make drum focusable
    drum->setFlag(QGraphicsItem::ItemIsFocusable);
    drum->setFocus();

    drum->setPos(130,150);
    drum1->setPos(142.5,162.5);
    //create SCORE
    score = new Score();
    scene -> addItem(score);

    //create TIMER
    mytimer =new MyTimer(gametime,0);
    scene->addItem(mytimer);
    mytimer->setPos(mytimer->x()+100,mytimer->y());
    timer1 = new QTimer();
    connect(timer1,SIGNAL(timeout()),mytimer,SLOT(decrease()));
    timer1->start(1000);
    QTimer::singleShot(30000,this,SLOT(endgame()));



    // spawn ELMO
      timer = new QTimer();
      QObject::connect(timer,SIGNAL(timeout()),drum,SLOT(spawn()));
      timer->start(1000);


    // play background music
       gamebgm = new QMediaPlayer();
       gamebgm->setMedia(QUrl("qrc:/song/gamebg.mp3"));
       gamebgm->play();

}

void Game::endgame()
{
    gamebgm->stop();
    timer-> disconnect();
    timer1->disconnect();

    End *endwindow = new End();
    endwindow->setfinalscore( this ->score->getscore());
    endwindow->show();

    delete this;

}

