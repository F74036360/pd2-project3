#include "fornine.h"

fornine::fornine()
{

}

fornine::~fornine()
{

}

void fornine::getsomething(block *blk[10][10], block *clicked, int more)
{

}

void fornine::toclear(block *blk[10][10], block *clicked, int moreclear)
{
    //game.score+=1000;
    int row=clicked->row;
    int col=clicked->col;
    int num=clicked->getrand;
    clicked->getrand=0;
    if(row-1>=0)blk[row-1][col]->getrand=0;
    if(row+1<=9)blk[row+1][col]->getrand=0;
    if(col-1>=0)blk[row][col-1]->getrand=0;
    if(col+1<=9)blk[row][col+1]->getrand=0;
    if(row-1>=0&&col-1>=0)blk[row-1][col-1]->getrand=0;
    if(row-1>=0&&col+1<=9)blk[row-1][col+1]->getrand=0;
    if(row+1<=9&&col-1>=0)blk[row+1][col-1]->getrand=0;
    if(row+1<=9&&col+1<=9)blk[row+1][col+1]->getrand=0;

}

int fornine::ifmore(block *blk[10][10], block *clicked)
{
    return 0;

}
