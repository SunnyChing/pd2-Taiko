
#include <QApplication>
#include"drum.h"
#include"game.h"
#include"start.h"
Game * game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Start * startwindow=new Start();
    startwindow -> show();
    //connect bt to game
   // connect(bt_start,SIGNAL(click()),this,SLOT(game()));
    //game =new Game();
    //game -> show();

    return a.exec();
}
