#include"start.h"
#include"game.h"

extern Game *game;
Start::Start()
{
    //set scene
    startscene =new QGraphicsScene(this);
    startscene -> setSceneRect(0,0,500,300);
   //set view to scene
    setScene(startscene);
    //set view
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(500,300);

    // add video
   player =new QMediaPlayer(this);
   bgv_start=new QGraphicsVideoItem();
   player ->setVideoOutput(bgv_start);
   player->setMedia(QUrl("qrc:/song/elmo_start.mp4"));
   bgv_start->setSize(QSizeF(500,300));
   bgv_start->setPos(0,0);
   startscene->addItem(bgv_start);
   player->play();
    connect(player,SIGNAL(stateChanged(QMediaPlayer::State)),player,SLOT(play()));
    //add buttom
   bt_start =new QPushButton("START",this);
   bt_start->setGeometry(QRect(QPoint(60,220),QSize(100,50)));
   connect(bt_start,SIGNAL(clicked(bool)),this,SLOT(OpenGame()));



   bt_exit =new QPushButton("EXIT",this);
   bt_exit->setGeometry(QRect(QPoint(340,220),QSize(100,50)));
   connect(bt_exit,SIGNAL(clicked()),this,SLOT(CloseStartView()));

   // add video
  player =new QMediaPlayer(this);
  bgv_start=new QGraphicsVideoItem();
  player ->setVideoOutput(bgv_start);
  player->setMedia(QUrl("qrc:/song/elmo_start.mp4"));
  bgv_start->setSize(QSizeF(500,300));
  bgv_start->setPos(0,0);
  startscene->addItem(bgv_start);
  player->play();




}

void Start::CloseStartView()
{

    player->stop();
    close();
    delete this;

}

void Start::OpenGame()
{

    player->stop();
    close();
    delete this;

    game =new Game();
    game->show();

}
