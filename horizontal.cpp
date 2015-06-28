#include "horizontal.h"

horizontal::horizontal()
{

}

horizontal::~horizontal()
{

}

void horizontal::spwan(block *blk[10][10], block *click, int mode)
{

}

void horizontal::eliminate(block *blk[10][10], block *click)
{
    int row=click->row;
    for(int i=0;i<10;i++)
    {
        blk[row][i]->getrand=0;
    }

}

int horizontal::condition(block *blk[10][10], block *click)
{

}

