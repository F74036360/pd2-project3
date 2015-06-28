#include "forlort.h"
#include "QDebug"
forLorT::forLorT()
{
    center=0;

}

forLorT::~forLorT()
{

}

void forLorT::getsomething(block *blk[10][10], block *clicked, int more)
{
    qDebug()<<"INforLTborn";
    if(more!=0)
    {
        int temp=(center<10&&center!=5&&center>0)?center:center/10;
        temp=(temp*10)+3;
        clicked->getrand=temp;
    }
}

void forLorT::toclear(block *blk[10][10], block *clicked, int moreclear)
{
    Destroy *d;
    int row=clicked->row;
    int col=clicked->col;
    switch (moreclear) {
    case 1:
        qDebug()<<"INforLT1";
        for(int i=row;i<=row+2;++i)
        {
            if(blk[i][col]->getrand<10&&blk[i][col]->getrand!=5)blk[i][col]->getrand=0;
            else if(blk[i][col]->getrand>10)
            {
                int tempnum=blk[i][col]->getrand%10;
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
        for(int i=col;i<=col+2;++i)
        {
            if(blk[row][i]->getrand<10&&blk[row][i]->getrand!=5&&blk[row][i]->getrand!=0)blk[row][i]->getrand=0;
            else if(blk[row][i]->getrand>10)
            {
                int tempnum=blk[row][i]->getrand%10;
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
    case 2:
        qDebug()<<"INforLT2";
        for(int i=row-2;i<=row;++i)
        {
            if(blk[i][col]->getrand<10&&blk[i][col]->getrand!=5&&blk[i][col]->getrand!=0)blk[i][col]->getrand=0;
            else if(blk[i][col]->getrand>10)
            {
                int tempnum=blk[i][col]->getrand%10;
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
        for(int i=col;i<=col+2;++i)
        {
            if(blk[row][i]->getrand<10&&blk[row][i]->getrand!=5&&blk[row][i]->getrand!=0)blk[row][i]->getrand=0;
            else if(blk[row][i]->getrand>10)
            {
                int tempnum=blk[row][i]->getrand%10;
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

    case 3:
        qDebug()<<"INforLT3";
        for(int i=row;i<=row+2;++i)
        {
            if(blk[i][col]->getrand<10&&blk[i][col]->getrand!=5&&blk[i][col]->getrand!=0)blk[i][col]->getrand=0;
            else if(blk[i][col]->getrand>10)
            {
                int tempnum=blk[i][col]->getrand%10;
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
        for(int i=col-2;i<=col;++i)
        {
            if(blk[row][i]->getrand<10&&blk[row][i]->getrand!=5&&blk[row][i]->getrand!=0)blk[row][i]->getrand=0;
            else if(blk[row][i]->getrand>10)
            {
                int tempnum=blk[row][i]->getrand%10;
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
    case 4:
        qDebug()<<"INforLT4";
        for(int i=row-2;i<=row;++i)
        {
            if(blk[i][col]->getrand<10&&blk[i][col]->getrand!=5&&blk[i][col]->getrand!=0)blk[i][col]->getrand=0;
            else if(blk[i][col]->getrand>10)
            {
                int tempnum=blk[i][col]->getrand%10;
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
        for(int i=col-2;i<=col;++i)
        {
            if(blk[row][i]->getrand<10&&blk[row][i]->getrand!=5&&blk[row][i]->getrand!=0)blk[row][i]->getrand=0;
            else if(blk[row][i]->getrand>10)
            {
                int tempnum=blk[row][i]->getrand%10;

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
        qDebug()<<"INforLT5";
        for(int i=row;i<=row+2;++i)
        {
            if(blk[i][col]->getrand<10&&blk[i][col]->getrand!=5&&blk[i][col]->getrand!=0)blk[i][col]->getrand=0;
            else if(blk[i][col]->getrand>10)
            {
                int tempnum=blk[i][col]->getrand%10;
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
        for(int i=col-1;i<=col+1;++i)
        {
            if(blk[row][i]->getrand<10&&blk[row][i]->getrand!=5&&blk[row][i]->getrand!=0)blk[row][i]->getrand=0;
            else if(blk[row][i]->getrand>10)
            {
                int tempnum=blk[row][i]->getrand%10;
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
    case 6:
        qDebug()<<"INforLT6";
        for(int i=row-1;i<=row+1;++i)
        {
            if(blk[i][col]->getrand<10&&blk[i][col]->getrand!=5&&blk[i][col]->getrand!=0)blk[i][col]->getrand=0;
            else if(blk[i][col]->getrand>10)
            {
                int tempnum=blk[i][col]->getrand%10;

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
        for(int i=col-2;i<=col;++i)
        {
            if(blk[row][i]->getrand<10&&blk[row][i]->getrand!=5&&blk[row][i]->getrand!=0)blk[row][i]->getrand=0;
            else if(blk[row][i]->getrand>10)
            {
                int tempnum=blk[row][i]->getrand%10;

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
    case 7:
        qDebug()<<"INforLT7";
        for(int i=row-2;i<=row;++i)
        {
            if(blk[i][col]->getrand<10&&blk[i][col]->getrand!=5&&blk[i][col]->getrand!=0)blk[i][col]->getrand=0;
            else if(blk[i][col]->getrand>10)
            {
                int tempnum=blk[i][col]->getrand%10;
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
        for(int i=col-1;i<=col+1;++i)
        {
            if(blk[row][i]->getrand<10&&blk[row][i]->getrand!=5&&blk[row][i]->getrand!=0)blk[row][i]->getrand=0;
            else if(blk[row][i]->getrand>10)
            {
                int tempnum=blk[row][i]->getrand%10;

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
    case 8:
        qDebug()<<"INforLT8";
        for(int i=row-1;i<=row+1;++i)
        {
            if(blk[i][col]->getrand<10&&blk[i][col]->getrand!=5&&blk[i][col]->getrand!=0)blk[i][col]->getrand=0;
            else if(blk[i][col]->getrand>10)
            {
                int tempnum=blk[i][col]->getrand%10;

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
        for(int i=col;i<=col+2;++i)
        {
            if(blk[row][i]->getrand<10&&blk[row][i]->getrand!=5&&blk[row][i]->getrand!=0)blk[row][i]->getrand=0;
            else if(blk[row][i]->getrand>10)
            {
                int tempnum=blk[row][i]->getrand%10;

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



int forLorT::ifmore(block *blk[10][10], block *clicked)
{
    center=clicked->getrand;
    if(clicked->getrand==5||clicked->getrand==0)return 0;
    int row=clicked->row;
    int col=clicked->col;
    int num=clicked->getrand;
    num=(num<10&&num!=5&&num>0)?num:num/10;
    if((row>=0&&row<=7)&&(col>=0&&col<=7))
    {
        int right1=(((blk[row][col+1]->getrand)<10)?blk[row][col+1]->getrand:blk[row][col+1]->getrand/10);
        int right2=(((blk[row][col+2]->getrand)<10)?blk[row][col+2]->getrand:blk[row][col+2]->getrand/10);
        int down1=(((blk[row+1][col]->getrand)<10)?blk[row+1][col]->getrand:blk[row+1][col]->getrand/10);
        int down2=(((blk[row+2][col]->getrand)<10)?blk[row+2][col]->getrand:blk[row+2][col]->getrand/10);
        if(num==right1&&num==right2&&num==down1&&num==down2)
        {
            return 1;
           /*
             ***
             *
             *
             */
        }
    }
    if(row<=9&&row>=2&&col<=7&&col>=0)
    {
        int right1=(((blk[row][col+1]->getrand)<10)?blk[row][col+1]->getrand:blk[row][col+1]->getrand/10);
        int right2=(((blk[row][col+2]->getrand)<10)?blk[row][col+2]->getrand:blk[row][col+2]->getrand/10);
        int up2=(((blk[row-2][col]->getrand)<10)?blk[row-2][col]->getrand:blk[row-2][col]->getrand/10);
        int up1=(((blk[row-1][col]->getrand)<10)?blk[row-1][col]->getrand:blk[row-1][col]->getrand/10);
        if(num==right1&&num==right2&&num==up1&&num==up2)
        {
            return 2;
            /*
             *
             *
             ***
            */
        }
    }
    if(col<=9&&col>=2&&row>=0&&row<=7)
    {
        int down1=(((blk[row+1][col]->getrand)<10)?blk[row+1][col]->getrand:blk[row+1][col]->getrand/10);
        int down2=(((blk[row+2][col]->getrand)<10)?blk[row+2][col]->getrand:blk[row+2][col]->getrand/10);
        int left2=(((blk[row][col-2]->getrand)<10)?blk[row][col-2]->getrand:blk[row][col-2]->getrand/10);
        int left1=(((blk[row][col-1]->getrand)<10)?blk[row][col-1]->getrand:blk[row][col-1]->getrand/10);
        if(num==down1&&num==down2&&num==left1&&num==left2)return 3;
        /*
       ***
         *
         *
         */
    }
    if(col<=9&&col>=2&&row<=9&&row>=2)
    {
        /*
         *
         *
       ***
       */
        int left2=(((blk[row][col-2]->getrand)<10)?blk[row][col-2]->getrand:blk[row][col-2]->getrand/10);
        int left1=(((blk[row][col-1]->getrand)<10)?blk[row][col-1]->getrand:blk[row][col-1]->getrand/10);
        int up2=(((blk[row-2][col]->getrand)<10)?blk[row-2][col]->getrand:blk[row-2][col]->getrand/10);
        int up1=(((blk[row-1][col]->getrand)<10)?blk[row-1][col]->getrand:blk[row-1][col]->getrand/10);
        if(num==left1&&num==left2&&num==up1&&num==up2)return 4;
    }
    if(row>=0&&row<=7&&col>=1&&col<=8)
    {
        int left1=(((blk[row][col-1]->getrand)<10)?blk[row][col-1]->getrand:blk[row][col-1]->getrand/10);
        int right1=(((blk[row][col+1]->getrand)<10)?blk[row][col+1]->getrand:blk[row][col+1]->getrand/10);
        int down1=(((blk[row+1][col]->getrand)<10)?blk[row+1][col]->getrand:blk[row+1][col]->getrand/10);
        int down2=(((blk[row+2][col]->getrand)<10)?blk[row+2][col]->getrand:blk[row+2][col]->getrand/10);
        if(num==left1&&num==right1&&num==down1&&num==down2 )return 5;
        /*
         ***
          *
          *
             */
    }
    if(row>=1&&row<=8&&col>=2)
    {
        int left2=(((blk[row][col-2]->getrand)<10)?blk[row][col-2]->getrand:blk[row][col-2]->getrand/10);
        int left1=(((blk[row][col-1]->getrand)<10)?blk[row][col-1]->getrand:blk[row][col-1]->getrand/10);
        int up1=(((blk[row-1][col]->getrand)<10)?blk[row-1][col]->getrand:blk[row-1][col]->getrand/10);
        int down1=(((blk[row+1][col]->getrand)<10)?blk[row+1][col]->getrand:blk[row+1][col]->getrand/10);
        if(num==left1&&num==left2&&num==up1&&num==down1)return 6;
    }
    if(row>=2&&col>=1&&col<=8)
    {
        int left1=(((blk[row][col-1]->getrand)<10)?blk[row][col-1]->getrand:blk[row][col-1]->getrand/10);
        int right1=(((blk[row][col+1]->getrand)<10)?blk[row][col+1]->getrand:blk[row][col+1]->getrand/10);
        int up2=(((blk[row-2][col]->getrand)<10)?blk[row-2][col]->getrand:blk[row-2][col]->getrand/10);
        int up1=(((blk[row-1][col]->getrand)<10)?blk[row-1][col]->getrand:blk[row-1][col]->getrand/10);
        if(num==left1&&num==right1&&num==up2&&num==up1)return 7;
    }
    if(row<=8&&row>=1&&col<=7)
    {
        int up1=(((blk[row-1][col]->getrand)<10)?blk[row-1][col]->getrand:blk[row-1][col]->getrand/10);
        int down1=(((blk[row+1][col]->getrand)<10)?blk[row+1][col]->getrand:blk[row+1][col]->getrand/10);
        int right1=(((blk[row][col+1]->getrand)<10)?blk[row][col+1]->getrand:blk[row][col+1]->getrand/10);
        int right2=(((blk[row][col+2]->getrand)<10)?blk[row][col+2]->getrand:blk[row][col+2]->getrand/10);
        if(num==up1&&num==down1&&num==right1&&num==right2)return 8;

    }

    return 0;
}

