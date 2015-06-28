#include "for4.h"
#include <QDebug>
for4::for4()
{
    center=0;

}

for4::~for4()
{

}



void for4::getsomething(block *blk[10][10], block *clicked, int more)
{
    if(more==1||more==2)//gethori
    {

        int temp=(center<10)?center:center/10;
        temp=(temp*10)+1;
        qDebug()<<"temp"<<temp;
        clicked->getrand=temp;
    }
    else if(more==3||more==4)
    {
        int temp=(center<10)?center:center/10;
        qDebug()<<"temp"<<temp;
        temp=(temp*10)+2;
        clicked->getrand=temp;
    }

}

void for4::toclear(block *blk[10][10], block *clicked, int moreclear)
{
    qDebug()<<"for4";
    Destroy *d;
    int row=clicked->row;
    int col=clicked->col;
    int num=clicked->getrand;
    if(num!=0&&num!=5)
    {
        switch (moreclear) {
        case 1://from left1 to right2
            for(int i=col-1;i<=col+2;++i)
            {
                int temp=blk[row][i]->getrand;
                if(temp<5)blk[row][i]->getrand=0;
                else if(temp>10)
                {
                    temp=temp%10;
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
        case 2://from left2 to right1
            for(int i=col-2;i<=col+1;++i)
            {
                int temp=blk[row][i]->getrand;
                if(temp<5&&temp>0)blk[row][i]->getrand=0;
                else if(temp>10)
                {
                    temp=temp%10;
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
        case 3://from up1 to down2
            for(int i=row-1;i<=row+2;++i)
            {
                int temp=blk[i][col]->getrand;
                if(temp<5)blk[i][col]->getrand=0;
                else if(temp>10)
                {
                    temp=temp%10;
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
        case 4://from up2 to down1
            for(int i=row-2;i<=row+1;++i)
            {
                int temp=blk[i][col]->getrand;
                if(temp<5&&temp>0)blk[i][col]->getrand=0;
                else if(temp>10)
                {
                    temp=temp%10;
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


}

int for4::ifmore(block *blk[10][10], block *clicked)
{
    if(clicked->getrand==0||clicked->getrand==5)return 0;
    center=clicked->getrand;
    int row=clicked->row;
    int col=clicked->col;
    if((row==0&&col==0)||(row==9&&col==9)||(row==0&&col==9)||(row==9&&col==0))return 0;
    int num=clicked->getrand;
    num=(num<10&&num!=5&&num!=0)?num:num/10;
    if(row-2>=0&&row-1>=0&&row+1<=9)
    {
        int up1=(((blk[row-1][col]->getrand)<10&&(blk[row-1][col]->getrand!=5)&&(blk[row-1][col]->getrand>0))?blk[row-1][col]->getrand:blk[row-1][col]->getrand/10);
        int up2=(((blk[row-2][col]->getrand)<10)?blk[row-2][col]->getrand:blk[row-2][col]->getrand/10);
        int down1=(((blk[row+1][col]->getrand)<10)?blk[row+1][col]->getrand:blk[row+1][col]->getrand/10);
        if(up2==up1&&up2==num&&up2==down1)return 4;

    }
    if(row-1>=0&&row+2<=9)
    {

        int up1=(((blk[row-1][col]->getrand)<10)?blk[row-1][col]->getrand:blk[row-1][col]->getrand/10);
        int down1=(((blk[row+1][col]->getrand)<10)?blk[row+1][col]->getrand:blk[row+1][col]->getrand/10);
        int down2=(((blk[row+2][col]->getrand)<10)?blk[row+2][col]->getrand:blk[row+2][col]->getrand/10);
        if(num==up1&&num==down1&&num==down2)return 3;

    }
    if(col-2>=0&&col+1<=9)
    {
        int left1=(((blk[row][col-1]->getrand)<10)?blk[row][col-1]->getrand:blk[row][col-1]->getrand/10);
        int left2=(((blk[row][col-2]->getrand)<10)?blk[row][col-2]->getrand:blk[row][col-2]->getrand/10);
        int right1=(((blk[row][col+1]->getrand)<10)?blk[row][col+1]->getrand:blk[row][col+1]->getrand/10);
        if(num==left1&&num==left2&&num==right1)return 2;//from right1 to left2
    }
    if(col-1>=0&&col+1<=9&&col+2<=9)
    {

        int left1=(((blk[row][col-1]->getrand)<10)?blk[row][col-1]->getrand:blk[row][col-1]->getrand/10);
        int right1=(((blk[row][col+1]->getrand)<10)?blk[row][col+1]->getrand:blk[row][col+1]->getrand/10);
        int right2=(((blk[row][col+2]->getrand)<10)?blk[row][col+2]->getrand:blk[row][col+2]->getrand/10);

        if(num==left1&&num==right1&&num==right2)return 1;//from left1 to right2
    }

    return 0;
}
