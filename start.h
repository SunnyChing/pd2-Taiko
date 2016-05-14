#ifndef START_H
#define START_H
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include<QPushButton>
#include<QObject>
#include<Qdebug>
#include<QGraphicsVideoItem>
#include<QMediaPlayer>

class Start:public QGraphicsView
{
    Q_OBJECT
public:
    Start();
    ~Start(){qDebug()<<"startwindow close";}
    QGraphicsScene * startscene;
    QPushButton * bt_start,*bt_exit;
    QGraphicsVideoItem * bgv_start;
    QMediaPlayer * player;
public slots:
   void CloseStartView();
   void OpenGame();


};

#endif // START_H
