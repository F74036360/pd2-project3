#include "nineblock.h"

nineblock::nineblock()
{

}

nineblock::~nineblock()
{

}

void nineblock::spwan(block *blk[10][10], block *click, int mode)
{

}

void nineblock::eliminate(block *blk[10][10], block *click)
{
    int row=click->row;
    int col=click->col;
    blk[row][col]->getrand=0;
    if((row>=1&&col>=1))blk[row-1][col-1]->getrand=0;
    if(row>=1)blk[row-1][col]->getrand=0;
    if(row<=8)blk[row+1][col]->getrand=0;
    if(col>=1)blk[row][col-1]->getrand=0;
    if(col<=8)blk[row][col+1]->getrand=0;
    if(row>=1&&col<=8)blk[row-1][col+1]->getrand=0;
    if(row<=8&&col>=1)blk[row+1][col-1]->getrand=0;
    if(row<=8&&col<=8)blk[row+1][col+1]->getrand=0;

}

int nineblock::condition(block *blk[10][10], block *click)
{

}
