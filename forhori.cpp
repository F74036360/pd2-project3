#include "forhori.h"
#include <QDebug>
forhori::forhori()
{

}

forhori::~forhori()
{

}

void forhori::getsomething(block *blk[10][10], block *clicked, int more)
{

}

void forhori::toclear(block *blk[10][10], block *clicked, int moreclear)
{
    //game.score+=1000;
    qDebug()<<"inhori";
    int row=clicked->row;
    int col=clicked->col;
    Destroy *d;
    for(int i=0;i<10;++i)
    {
        if(i!=col)
        {
            if(blk[row][i]->getrand<10&&blk[row][i]->getrand!=5)
            {
                 blk[row][i]->getrand=0;
            }
        }
    }
    blk[row][col]->getrand=0;
}

int forhori::ifmore(block *blk[10][10], block *clicked)
{

    return 0;
}

