#include "vertical.h"

vertical::vertical()
{

}

vertical::~vertical()
{

}

void vertical::spwan(block *blk[10][10], block *click, int mode)
{

}

void vertical::eliminate(block *blk[10][10], block *click)
{
     int col=click->col;
     for(int i=0;i<10;i++)
     {

         blk[i][col]->getrand=0;

     }
}

int vertical::condition(block *blk[10][10], block *click)
{

}
