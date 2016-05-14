#include"end.h"
#include"game.h"
#include<QGraphicsScene>

End::End()
{
    //set scene
    endscene =new QGraphicsScene();
    endscene->setSceneRect(0,0,500,400);

    //set bg
    end_bg = new QGraphicsPixmapItem;
    end_bg->setPixmap(QPixmap(":/Elmo/end_bg.jpeg"));
    end_bg->setPos(200,100);
    endscene->addItem(end_bg);
    //set view to scene
     setScene(endscene);
     //set view
     setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
     setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
     setFixedSize(500,300);

     //add buttom
    bt_end =new QPushButton("RESTART",this);
    bt_end->setGeometry(QRect(QPoint(60,220),QSize(100,50)));
    connect(bt_end,SIGNAL(clicked(bool)),this,SLOT(restartgame()));


    bt_restart =new QPushButton("EXIT",this);
    bt_restart->setGeometry(QRect(QPoint(340,220),QSize(100,50)));
    connect(bt_restart,SIGNAL(clicked()),this,SLOT(exitgame()));


}

void End::setfinalscore(int n)
{
    finalscore=n;
    displscore =new QGraphicsTextItem();
    displscore->setPlainText(QString("Score: ") + QString::number(finalscore)); // Score: 0
    displscore->setDefaultTextColor(Qt::blue);
    displscore->setFont(QFont("times",24));
    displscore->setPos(200,130);
    endscene->addItem(displscore);
}

void End::exitgame()
{
    close();
    delete this;
}

void End::restartgame()
{
    close();
    delete this;
    start =new Start();
    start->show();
}
