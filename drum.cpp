#include"drum.h"
#include"elmo.h"
#include"game.h"
#include"good.h"
#include<QDebug>
#include<QGraphicsScene>
#include <QList>
#include<stdlib.h>
#include<typeinfo>

extern Game *game; // there is an external global object called game
Drum::Drum(QGraphicsItem *parent)
{
    tocsound = new QMediaPlayer();
    tocsound ->setMedia(QUrl("qrc:/song/toc.wav.mp3"));
}

void Drum::keyPressEvent(QKeyEvent *tic)
{
     if (tic->key() == Qt::Key_Z)
     {
         // play tocound
                 if (tocsound->state() == QMediaPlayer::PlayingState){
                     tocsound->setPosition(0);
                 }
                 else if (tocsound->state() == QMediaPlayer::StoppedState){
                     tocsound->play();
                 }


         // if elmo collides , destroy
             QList<QGraphicsItem *> colliding_elmo = collidingItems();
             for (int i = 0, n = colliding_elmo.size(); i < n; ++i){
                 if (typeid( *(colliding_elmo[i])) == typeid(Elmo)){
                     //score increace
                     game->score->increase();
                     //good
                       QPointF point_drum =game->drum->pos();
                       QPointF point_elmo=colliding_elmo[i]->pos();
                       QLineF line(point_drum,point_elmo);

                       if(line.length()<3){
                           goodhit =new Good();
                           scene()->addItem(goodhit);

                       }
                     // remove
                     scene()->removeItem(colliding_elmo[i]);

                     // delete them both
                     delete colliding_elmo[i];

                     return;
                 }
            }
     }
     /*cookiemonster ase*/
     if (tic->key() == Qt::Key_X)
     {
         // play tocound
                 if (tocsound->state() == QMediaPlayer::PlayingState){
                     tocsound->setPosition(0);
                 }
                 else if (tocsound->state() == QMediaPlayer::StoppedState){
                     tocsound->play();
                 }


         // if elmo collides , destroy
             QList<QGraphicsItem *> colliding_cookmstr = collidingItems();
             for (int i = 0, n = colliding_cookmstr.size(); i < n; ++i){
                 if (typeid( *(colliding_cookmstr[i])) == typeid(CookieMonster)){
                     //score increace
                     game->score->increase();
                     //good
                       QPointF point_drum =game->drum->pos();
                       QPointF point_elmo=colliding_cookmstr[i]->pos();
                       QLineF line(point_drum,point_elmo);

                       if(line.length()<3){
                           goodhit =new Good();
                           scene()->addItem(goodhit);

                       }
                     // remove
                     scene()->removeItem(colliding_cookmstr[i]);

                     // delete
                     delete colliding_cookmstr[i];

                     return;
                 }
            }
     }



}

void Drum::spawn()
{
    // create an Elmo
  int random_number = rand();
  if(random_number%3){
     Elmo * elmo = new Elmo();
     scene()->addItem(elmo);
  }else
     {
     CookieMonster *cookmstr =new CookieMonster();
     scene()->addItem(cookmstr);
     }

}



