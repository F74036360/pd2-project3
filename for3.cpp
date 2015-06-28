#include "for3.h"
#include <QDebug>
for3::for3()
{

}

for3::~for3()
{

}

void for3::getsomething(block *blk[10][10], block *clicked, int more)
{

}

void for3::toclear(block *blk[10][10], block *clicked, int moreclear)
{
    qDebug()<<"for3_INTOCLEAR";
    int row=clicked->row;
    int col=clicked->col;
    int num=clicked->getrand;
    Destroy *d;
    if(num!=5&&num!=0)
    {
        switch (moreclear){
        case 1://up
            for(int i=row-2;i<=row;++i)
            {
                int tempnum=blk[i][col]->getrand;
                if(tempnum<5&&tempnum>0)
                {
                    blk[i][col]->getrand=0;
                }
                else
                {
                    tempnum=tempnum%10;
                    switch (tempnum) {
                    case 1:
                        d=new forhori;
                        d->toclear(blk,blk[i][col],0);
                        delete d;
                        break;
                    case 2:
                        d=new forvertical;
                        d->toclear(blk,blk[i][col],0);
                        delete d;
                        break;
                    case 3:
                        d=new fornine;
                        d->toclear(blk,blk[i][col],0);
                        delete d;
                        break;
                    default:
                        break;
                    }
                }
            }
            break;
        case 2://left
            for(int i=col-2;i<=col;++i)
            {
                int tempnum=blk[row][i]->getrand;
                if(tempnum<5&&tempnum>0)
                {
                    blk[row][i]->getrand=0;
                }
                else
                {
                    tempnum=tempnum%10;
                    switch (tempnum) {
                    case 1:
                        d=new forhori;
                        d->toclear(blk,blk[row][i],0);
                        delete d;
                        break;
                    case 2:
                        d=new forvertical;
                        d->toclear(blk,blk[row][i],0);
                        delete d;
                        break;
                    case 3:
                        d=new fornine;
                        d->toclear(blk,blk[row][i],0);
                        delete d;
                        break;
                    default:
                        break;
                    }
                }
            }

            break;

        case 3://down
            for(int i=row;i<=row+2;++i)
            {
                int tempnum=blk[i][col]->getrand;
                if(tempnum<5&&tempnum>0)
                {
                    blk[i][col]->getrand=0;
                }
                else
                {
                    tempnum=tempnum%10;
                    switch (tempnum) {
                    case 1:
                        d=new forhori;
                        d->toclear(blk,blk[i][col],0);
                        delete d;
                        break;
                    case 2:
                        d=new forvertical;
                        d->toclear(blk,blk[i][col],0);
                        delete d;
                        break;
                    case 3:
                        d=new fornine;
                        d->toclear(blk,blk[i][col],0);
                        delete d;
                        break;
                    default:
                        break;
                    }
                }
            }
            break;

        case 4://right
            for(int i=col;i<=col+2;++i)
            {
                int tempnum=blk[row][i]->getrand;
                if(tempnum<5&&tempnum>0)
                {
                    blk[row][i]->getrand=0;
                }
                else
                {
                    tempnum=tempnum%10;
                    switch (tempnum) {
                    case 1:
                        d=new forhori;
                        d->toclear(blk,blk[row][i],0);
                        delete d;
                        break;
                    case 2:
                        d=new forvertical;
                        d->toclear(blk,blk[row][i],0);
                        delete d;
                        break;
                    case 3:
                        d=new fornine;
                        d->toclear(blk,blk[row][i],0);
                        delete d;
                        break;
                    default:
                        break;
                    }
                }
            }

            break;
        case 5:
            for(int i=row-1;i<=row+1;++i)
            {
                int tempnum=blk[i][col]->getrand;
                if(tempnum<5&&tempnum>0)
                {
                    blk[i][col]->getrand=0;
                }
                else
                {
                    tempnum=tempnum%10;
                    switch (tempnum) {
                    case 1:
                        d=new forhori;
                        d->toclear(blk,blk[i][col],0);
                        delete d;
                        break;
                    case 2:
                        d=new forvertical;
                        d->toclear(blk,blk[i][col],0);
                        delete d;
                        break;
                    case 3:
                        d=new fornine;
                        d->toclear(blk,blk[i][col],0);
                        delete d;
                        break;
                    default:
                        break;
                    }
                }
            }
            break;
        case 6:
            for(int i=col-1;i<=col+1;++i)
            {
                int tempnum=blk[row][i]->getrand;
                if(tempnum<5&&tempnum>0)
                {
                    blk[row][i]->getrand=0;
                }
                else
                {
                    tempnum=tempnum%10;
                    switch (tempnum) {
                    case 1:
                        d=new forhori;
                        d->toclear(blk,blk[row][i],0);
                        delete d;
                        break;
                    case 2:
                        d=new forvertical;
                        d->toclear(blk,blk[row][i],0);
                        delete d;
                        break;
                    case 3:
                        d=new fornine;
                        d->toclear(blk,blk[row][i],0);
                        delete d;
                        break;
                    default:
                        break;
                    }
                }
            }

            break;

        default:
            break;
        }

    }


}

int for3::ifmore(block *blk[10][10], block *clicked)
{
    if(clicked->getrand==0||clicked->getrand==5)return 0;
    int row=clicked->row;
    int col=clicked->col;
    int num=((clicked->getrand<10)&&(clicked->getrand!=5)&&(clicked->getrand!=0))?blk[row][col]->getrand:blk[row][col]->getrand/10;

    if(row-2>=0)
    {
        int up2=((blk[row-2][col]->getrand)<10&&(blk[row-2][col]->getrand!=5)&&(blk[row-2][col]->getrand>0))?blk[row-2][col]->getrand:blk[row-2][col]->getrand/10;
        int up1=((blk[row-1][col]->getrand)<10&&(blk[row-1][col]->getrand!=5)&&(blk[row-1][col]->getrand>0))?blk[row-1][col]->getrand:blk[row-1][col]->getrand/10;
        if(num==up2&&num==up1)return 1;
    }
    if(row+2<=9)
    {
        int down1=(((blk[row+1][col]->getrand)<10)?blk[row+1][col]->getrand:blk[row+1][col]->getrand/10);
        int down2=(((blk[row+2][col]->getrand)<10)?blk[row+2][col]->getrand:blk[row+2][col]->getrand/10);
        if(num==down2&&num==down1)return 3;
    }
    if(col-2>=0)
    {
        int left2=(((blk[row][col-2]->getrand)<10&&(blk[row][col-2]->getrand)!=5&&(blk[row][col-2]->getrand)>0)?blk[row][col-2]->getrand:blk[row][col-2]->getrand/10);
        int left1=(((blk[row][col-1]->getrand)<10)?blk[row][col-1]->getrand:blk[row][col-1]->getrand/10);
        if(num==left1&&num==left2)return 2;
    }
    if(col+2<=9)
    {
        qDebug()<<"incol+2";
        int right1=(((blk[row][col+1]->getrand)<10)?blk[row][col+1]->getrand:blk[row][col+1]->getrand/10);
        int right2=(((blk[row][col+2]->getrand)<10)?blk[row][col+2]->getrand:blk[row][col+2]->getrand/10);
        if(num==right1&&num==right2)return 4;
    }
    if(row-1>=0&&row+1<=9)
    {
        int up1=(((blk[row-1][col]->getrand)<10)?blk[row-1][col]->getrand:blk[row-1][col]->getrand/10);
        int down1=(((blk[row+1][col]->getrand)<10)?blk[row+1][col]->getrand:blk[row+1][col]->getrand/10);
        if(num==up1&&num==down1)return 5;
    }
    if(col-1>=0&&col+1<=9)
    {
        int right1=(((blk[row][col+1]->getrand)<10)?blk[row][col+1]->getrand:blk[row][col+1]->getrand/10);
        int left1=(((blk[row][col-1]->getrand)<10)?blk[row][col-1]->getrand:blk[row][col-1]->getrand/10);
        if(num==right1&&num==left1)return 6;
    }

    return 0;
}


