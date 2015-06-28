#include "for5.h"
#include <QDebug>
for5::for5()
{

}

for5::~for5()
{

}
void for5::getsomething(block *blk[10][10], block *clicked, int more)
{
    qDebug()<<"getfor5";
    if(more!=0)clicked->getrand=5;
}

void for5::toclear(block *blk[10][10], block *clicked, int moreclear)
{

    qDebug()<<"for5";
    int row=clicked->row;
    int col=clicked->col;
    Destroy *d;
    switch (moreclear) {
    case 1://hori
        for(int i=col-2;i<=col+2;++i)
        {
            if(blk[row][i]->getrand<5)blk[row][i]->getrand=0;
            else if((blk[row][i]->getrand)>10)
            {
                int temp=blk[row][i]->getrand%10;
                switch (temp) {
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
    case 2://vertical
        for(int i=row-2;i<=row+2;++i)
        {
            if((blk[i][col]->getrand)<5&&(blk[i][col]->getrand)!=0)blk[i][col]->getrand=0;
            else if(blk[i][col]->getrand>10)
            {
                int temp=blk[i][col]->getrand%10;
                switch (temp) {
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
    default:
        break;
    }
}

int for5::ifmore(block *blk[10][10], block *clicked)
{
    if(clicked->getrand==0)return 0;
    int row=clicked->row;
    int col=clicked->col;
    int num=(blk[row][col]->getrand);
    if(num>0&&num!=5)
    {
        num=(((blk[row][col]->getrand)<10&&(blk[row][col]->getrand!=5)&&(blk[row][col]->getrand!=0))?blk[row][col]->getrand:blk[row][col]->getrand/10);
        if((row<2&&col<2)||(row>7&&col>7)||(row<2&&col>7)||(row>7&&col<2))return 0;
        if(col>=2&&col<=7)
        {
            if(row==0||row==1||row==8||row==9)
            {
                int left2=(((blk[row][col-2]->getrand)<10)?blk[row][col-2]->getrand:blk[row][col-2]->getrand/10);
                int left1=(((blk[row][col-1]->getrand)<10)?blk[row][col-1]->getrand:blk[row][col-1]->getrand/10);
                int right1=(((blk[row][col+1]->getrand)<10)?blk[row][col+1]->getrand:blk[row][col+1]->getrand/10);
                int right2=(((blk[row][col+2]->getrand)<10)?blk[row][col+2]->getrand:blk[row][col+2]->getrand/10);
                if(num==left2&&num==left1&&num==right1&&num==right2)return 1; //hori
            }
            if(row<=7&&row>=2)
            {
                int left2=(((blk[row][col-2]->getrand)<10)?blk[row][col-2]->getrand:blk[row][col-2]->getrand/10);
                int left1=(((blk[row][col-1]->getrand)<10)?blk[row][col-1]->getrand:blk[row][col-1]->getrand/10);
                int right1=(((blk[row][col+1]->getrand)<10)?blk[row][col+1]->getrand:blk[row][col+1]->getrand/10);
                int right2=(((blk[row][col+2]->getrand)<10)?blk[row][col+2]->getrand:blk[row][col+2]->getrand/10);
                int up2=(((blk[row-2][col]->getrand)<10)?blk[row-2][col]->getrand:blk[row-2][col]->getrand/10);
                int up1=(((blk[row-1][col]->getrand)<10)?blk[row-1][col]->getrand:blk[row-1][col]->getrand/10);
                int down1=(((blk[row+1][col]->getrand)<10)?blk[row+1][col]->getrand:blk[row+1][col]->getrand/10);
                int down2=(((blk[row+2][col]->getrand)<10)?blk[row+2][col]->getrand:blk[row+2][col]->getrand/10);
                if(num==left2&&num==left1&&num==right1&&num==right2)return 1;//hori
                if(num==up1&&num==up2&&num==down1&&num==down2) return 2;//vertical
            }
        }
        if(row>=2&&row<=7)
        {
            if(col==0||col==1||col==8||col==9)
            {
                int up2=(((blk[row-2][col]->getrand)<10)?blk[row-2][col]->getrand:blk[row-2][col]->getrand/10);
                int up1=(((blk[row-1][col]->getrand)<10)?blk[row-1][col]->getrand:blk[row-1][col]->getrand/10);
                int down1=(((blk[row+1][col]->getrand)<10)?blk[row+1][col]->getrand:blk[row+1][col]->getrand/10);
                int down2=(((blk[row+2][col]->getrand)<10)?blk[row+2][col]->getrand:blk[row+2][col]->getrand/10);
                if(num==up1&&num==up2&&num==down1&&num==down2) return 2;
            }
        }
    }

    return 0;
}
