#include "heart.h"
#include <QDebug>

heart::heart()
{

}

heart::~heart()
{

}
void heart::spwan(block *blk[10][10],block *click,int mode)
{
    Destroy *d;
    int row=click->row;
    int col=click->col;
    int num=click->getrand;
    int fiveNum[5]={0};
    switch (mode) {
    case 1:
        click->getrand=5;
        if(col>=2&&(num==blk[row][col-2]->getrand||num==blk[row][col-2]->getrand/10)&&(num==blk[row][col-1]->getrand||num==blk[row][col-1]->getrand/10))
        {
            blk[row][col-2]->getrand=0;
            blk[row][col-1]->getrand=0;

        }
        else if(col<=7&&(num==blk[row][col+2]->getrand||num==blk[row][col+2]->getrand/10)&&(num==blk[row][col+1]->getrand||num==blk[row][col+1]->getrand/10))
        {
            blk[row][col+2]->getrand=0;
            blk[row][col+1]->getrand=0;
        }

        if(blk[row-2][col]->getrand/10!=0)fiveNum[0]=blk[row-2][col]->getrand%10;
        if(blk[row-1][col]->getrand/10!=0)fiveNum[1]=blk[row-1][col]->getrand%10;
        fiveNum[2]=blk[row][col]->getrand;
        if(blk[row+1][col]->getrand/10!=0)fiveNum[3]=blk[row+1][col]->getrand%10;
        if(blk[row+2][col]->getrand/10!=0)fiveNum[4]=blk[row+2][col]->getrand%10;
        for(int i=0;i<5;i++)
        {
            switch (fiveNum[i]) {
            case 0:
                blk[row-2+i][col]->getrand=0;
                break;
            case 1:
                d=new vertical;
                d->eliminate(blk,blk[row-2+i][col]);
                delete d;
                break;//explore
            case 2:
                d=new horizontal;
                d->eliminate(blk,blk[row-2+i][col]);
                delete d;
                break;
            case 3:
                d=new nineblock;
                d->eliminate(blk,blk[row-2+i][col]);
                delete d;
                break;
            default:
                break;
            }
        }
        break;
    case 2:
        click->getrand=5;
        if(row>=2&&(num==blk[row-2][col]->getrand||num==blk[row-2][col]->getrand/10)&&(num==blk[row-1][col]->getrand||num==blk[row-1][col]->getrand/10))
        {
            blk[row-2][col]->getrand=0;
            blk[row-1][col]->getrand=0;
        }
        else if(row<=7&&(num==blk[row+2][col]->getrand||num==blk[row+2][col]->getrand/10)&&(num==blk[row+1][col]->getrand||num==blk[row+1][col]->getrand/10))
        {
            blk[row+2][col]->getrand=0;
            blk[row+1][col]->getrand=0;
        }

        if(blk[row][col-2]->getrand/10!=0)fiveNum[0]=blk[row][col-2]->getrand%10;
        if(blk[row][col-1]->getrand/10!=0)fiveNum[1]=blk[row][col-1]->getrand%10;
        fiveNum[2]=blk[row][col]->getrand;
        if(blk[row][col+1]->getrand/10!=0)fiveNum[3]=blk[row][col+1]->getrand%10;
        if(blk[row][col+2]->getrand/10!=0)fiveNum[4]=blk[row][col+2]->getrand%10;
        for(int i=0;i<5;i++)
        {
            switch (fiveNum[i]) {
            case 0:
                blk[row][col-2+i]->getrand=0;
                break;
            case 1:
                d=new vertical;
                d->eliminate(blk,blk[row][col-2+i]);
                delete d;
                break;//explore
            case 2:
                d=new horizontal;
                d->eliminate(blk,blk[row][col-2+i]);
                delete d;
                break;
            case 3:
                d=new nineblock;
                d->eliminate(blk,blk[row][col-2+i]);
                delete d;
                break;
            default:
                break;
            }
        }
        break;
    case 3:
        num=num/10;
        if(col>=2&&(num==blk[row][col-2]->getrand||num==blk[row][col-2]->getrand/10)&&(num==blk[row][col-1]->getrand||num==blk[row][col-1]->getrand/10))
        {
            blk[row][col-2]->getrand=0;
            blk[row][col-1]->getrand=0;

        }
        else if(col<=7&&(num==blk[row][col+2]->getrand||num==blk[row][col+2]->getrand/10)&&(num==blk[row][col+1]->getrand||num==blk[row][col+1]->getrand/10))
        {
            blk[row][col+2]->getrand=0;
            blk[row][col+1]->getrand=0;
        }

        if(blk[row-2][col]->getrand/10!=0)fiveNum[0]=blk[row-2][col]->getrand%10;
        if(blk[row-1][col]->getrand/10!=0)fiveNum[1]=blk[row-1][col]->getrand%10;
        fiveNum[2]=blk[row][col]->getrand%10;
        if(blk[row+1][col]->getrand/10!=0)fiveNum[3]=blk[row+1][col]->getrand%10;
        if(blk[row+2][col]->getrand/10!=0)fiveNum[4]=blk[row+2][col]->getrand%10;
        for(int i=0;i<5;i++)
        {
            switch (fiveNum[i]) {
            case 0:
                blk[row-2+i][col]->getrand=0;
                break;
            case 1:
                d=new vertical;
                d->eliminate(blk,blk[row-2+i][col]);
                delete d;
                break;//explore
            case 2:
                d=new horizontal;
                d->eliminate(blk,blk[row-2+i][col]);
                delete d;
                break;
            case 3:
                d=new nineblock;
                d->eliminate(blk,blk[row-2+i][col]);
                delete d;
                break;
            default:
                break;
            }
        }
        break;
    case 4:
        num=num/10;
        if(row>=2&&(num==blk[row-2][col]->getrand||num==blk[row-2][col]->getrand/10)&&(num==blk[row-1][col]->getrand||num==blk[row-1][col]->getrand/10))
        {
            blk[row-2][col]->getrand=0;
            blk[row-1][col]->getrand=0;
        }
        else if(row<=7&&(num==blk[row+2][col]->getrand||num==blk[row+2][col]->getrand/10)&&(num==blk[row+1][col]->getrand||num==blk[row+1][col]->getrand/10))
        {
            blk[row+2][col]->getrand=0;
            blk[row+1][col]->getrand=0;
        }

        if(blk[row][col-2]->getrand/10!=0)fiveNum[0]=blk[row][col-2]->getrand%10;
        if(blk[row][col-1]->getrand/10!=0)fiveNum[1]=blk[row][col-1]->getrand%10;
        fiveNum[2]=blk[row][col]->getrand%10;
        if(blk[row][col+1]->getrand/10!=0)fiveNum[3]=blk[row][col+1]->getrand%10;
        if(blk[row][col+2]->getrand/10!=0)fiveNum[4]=blk[row][col+2]->getrand%10;
        for(int i=0;i<5;i++)
        {
            switch (fiveNum[i]) {
            case 0:
                blk[row][col-2+i]->getrand=0;
                break;
            case 1:
                d=new vertical;
                d->eliminate(blk,blk[row][col-2+i]);
                delete d;
                break;//explore
            case 2:
                d=new horizontal;
                d->eliminate(blk,blk[row][col-2+i]);
                delete d;
                break;
            case 3:
                d=new nineblock;
                d->eliminate(blk,blk[row][col-2+i]);
                delete d;
                break;
            default:
                break;
            }
        }
        break;
    default:
        break;
    }


}

void heart::eliminate(block *blk[10][10], block *click)
{

}


int heart::condition(block *blk[10][10], block *click)
{

}
