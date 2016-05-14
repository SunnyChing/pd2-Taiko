#include"score.h"
#include<QFont>
#include<QObject>


Score::Score(QGraphicsItem *parent) :QGraphicsTextItem()
{
    // initialize the score to 0
       //score = 0;

       // set the text
       setPlainText(QString("Score: ") + QString::number(score)); // Score: 0
       setDefaultTextColor(Qt::blue);
       setFont(QFont("times",24));
}

void Score::increase()
{
    score++;
    setPlainText(QString("Score: ") + QString::number(score));
}

int Score::getscore()
{
    return score;
}

