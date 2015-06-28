#include "forvertical.h"

forvertical::forvertical()
{

}

forvertical::~forvertical()
{

}

void forvertical::getsomething(block *blk[10][10], block *clicked, int more)
{

}

void forvertical::toclear(block *blk[10][10], block *clicked, int moreclear)
{
    int row=clicked->row;
    int col=clicked->col;
    Destroy *d;
    for(int i=0;i<10;++i)
    {
        if(i!=row)
        {
            if(blk[i][col]->getrand<10&&blk[i][col]->getrand!=5)
            {
                 blk[i][col]->getrand=0;
            }
        }
    }
    blk[row][col]->getrand=0;
}

int forvertical::ifmore(block *blk[10][10], block *clicked)
{
    return 0;

}
