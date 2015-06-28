#include "game.h"
#include "ui_game.h"
#include <QDebug>

game::game(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::game)
{
    srand(time(NULL));
    ui->setupUi(this);
    score=0;

    rblk1=0;
    cblk1=0;
    ifclicked=false;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            blk[i][j]=new block(this,i,j);
            connect(blk[i][j],SIGNAL(Click(int,int)),this,SLOT(blkclick(int,int)));
            connect(blk[i][j],SIGNAL(aftermove()),this,SLOT(forzero()));
        }
    }
    ttt=new QTimer();
    connect(ttt,SIGNAL(timeout()),this,SLOT(counttime()));
    ttt->start(1000);
    start();
    count=60;
    ui->scorepic ->setVisible(1);
    ui->scorepic ->setAlignment(Qt::AlignCenter);
    str=QString::number(score,10);//int to string
    ui->scorepic->setText(str);
    ui->time->setVisible(1);
    ui->time->setAlignment(Qt::AlignCenter);
    str1=QString::number(count,10);//int to string
    ui->time->setText(str1);
    stone4=0;
    stone5=0;
    stoneL=0;
    ui->stone4->setAlignment(Qt::AlignCenter);
    ui->stone5->setAlignment(Qt::AlignCenter);
    ui->stoneL->setAlignment(Qt::AlignCenter);
    forstone4=QString::number(stone4,10);//int to string
    forstone5=QString::number(stone5,10);//int to string
    forstoneL=QString::number(stoneL,10);//int to string
    ui->stone4->setText(forstone4);
    ui->stone5->setText(forstone5);
    ui->stoneL->setText(forstoneL);

}


game::~game()
{
    delete ui;
}

void game::counttime()
{
    count--;
    str1=QString::number(count,10);//int to string
    ui->time->setText(str1);
    if(count==0)
    {
        win *a=new win;
        a->setWindowTitle("time's up");
        a->check(score);
        a->show();
        ttt->stop();
        score=0;
        this->close();

    }

}

void game::forzero()
{
    if(score>=10000&&score<30000)
    {
        QString star="2";
        ui->star->setAlignment(Qt::AlignCenter);
        ui->star->setText(star);
    }
    else if(score<10000&&score>1000)
    {
        QString star="1";
        ui->star->setAlignment(Qt::AlignCenter);
        ui->star->setText(star);
    }
    else if(score>=30000)
    {
        QString star="3";
        ui->star->setAlignment(Qt::AlignCenter);
        ui->star->setText(star);
    }
    else
    {
        QString star="0";
        ui->star->setAlignment(Qt::AlignCenter);
        ui->star->setText(star);
    }
    str=QString::number(score,10);//int to string
    ui->scorepic->setText(str);

    renewpic();
}

void game::renewpic()
{
    for(int i=0;i<10;++i)
    {
        for(int j=0;j<10;++j)
        {
            if(blk[i][j]->getrand!=ori[i][j])
            {
                blk[i][j]->setpic();
                ori[i][j]=blk[i][j]->getrand;
            }
        }
    }
}

bool game::For5(int row, int col)
{
    bool flag=0;
    Destroy *d=new for5;
    int ifmore=d->ifmore(blk,blk[row][col]);
    qDebug()<<ifmore<<"For5";
    if(ifmore!=0)
    {

        stone5++;
        forstone5=QString::number(stone5,10);//int to string
        ui->stone5->setText(forstone5);
        d->toclear(blk,blk[row][col],ifmore);
        d->getsomething(blk,blk[row][col],ifmore);
        flag=1;
        score=score+500;
    }
    delete d;
    return flag;
}

bool game::For4(int row, int col)
{
    bool flag=0;
    Destroy *d=new for4;
    int ifmore=d->ifmore(blk,blk[row][col]);
    qDebug()<<ifmore<<"For4";
    if(ifmore!=0)
    {
        stone4++;
        forstone4=QString::number(stone4,10);//int to string
        ui->stone4->setText(forstone4);
        d->toclear(blk,blk[row][col],ifmore);
        d->getsomething(blk,blk[row][col],ifmore);
        flag=1;
        score=score+400;
    }
    delete d;
    return flag;

}

bool game::ForLT(int row, int col)
{
    bool flag=0;
    Destroy *d=new forLorT;
    int ifmore=d->ifmore(blk,blk[row][col]);
    qDebug()<<ifmore<<"ForLT";
    if(ifmore!=0)
    {
        stoneL++;
        forstoneL=QString::number(stoneL,10);//int to string
        ui->stoneL->setText(forstoneL);
        ui->stoneL->setAlignment(Qt::AlignCenter);
        QString scoretxt=QString::number(score,10);//int to string
        ui->scorepic->setText(scoretxt);
        d->toclear(blk,blk[row][col],ifmore);
        d->getsomething(blk,blk[row][col],ifmore);
        flag=1;
        score=score+450;
    }
    delete d;
    return flag;

}

bool game::For3(int row, int col)
{
    bool flag=0;
    Destroy *d=new for3;
    int ifmore=d->ifmore(blk,blk[row][col]);
    qDebug()<<ifmore<<"For3";
    if(ifmore!=0)
    {
        d->toclear(blk,blk[row][col],ifmore);
        flag=1;
        score=score+300;
    }
    delete d;
    return flag;

}



bool game::judge(int r1, int c1,int r2,int c2)
{
    int flag[9];
    for(int i=0;i<9;i++)
    {
        flag[i]=0;
    }
    if(blk[r1][c1]->getrand!=0&&blk[r2][c2]->getrand!=0)
    {
        if(blk[r1][c1]->getrand!=5&&blk[r2][c2]->getrand!=5)
        {
            flag[0]=For5(r1,c1);
            flag[1]=For5(r2,c2);
            if(flag[0]==0&&flag[1]==0)
            {
                if(flag[0]==0&&flag[1]==0)
                {
                    flag[2]=ForLT(r1,c1);
                    flag[3]=ForLT(r2,c2);
                    if(flag[2]==0&&flag[3]==0)
                    {
                        flag[4]=For4(r1,c1);
                        flag[5]=For4(r2,c2);
                        if(flag[4]==0&&flag[5]==0)
                        {
                            flag[6]=For3(r1,c1);
                            flag[7]=For3(r2,c2);
                        }
                    }
                }
            }
        }
        else if(blk[r1][c1]->getrand==5||blk[r2][c2]->getrand==5)
        {
            Forstar(r1,c1,r2,c2);
            flag[8]=1;
            //randverse2();

        }
        if(flag[0]==0&&flag[1]==0&&flag[2]==0&&flag[3]==0&&flag[4]==0&&flag[5]==0&&flag[6]==0&&flag[7]==0&&flag[8]==0)
        {
            int temp=blk[r1][c1]->getrand;
            blk[r1][c1]->getrand=blk[r2][c2]->getrand;
            blk[r2][c2]->getrand=temp;
            return 0;
        }

    }

    if(flag[0]!=0||flag[1]!=0||flag[2]!=0||flag[3]!=0||flag[4]!=0||flag[5]!=0||flag[6]!=0||flag[7]!=0||flag[8]!=0)
    {
        fall();
        while(1)
        {
            if(check()==0)break;
            fall();
        }
    }


    randverse2();
    return 0;
}

void game::randverse2()
{
//    int down1=0,down2=0,right1=0,right2=0,left1=0,left2=0;
    for(int i=9;i>=0;i--)
    {
        for(int j=9;j>=0;j--)
        {

            if(blk[i][j]->getrand==0)
            {
                blk[i][j]->getrand=rand()%4+1;
                if(j>=2&&(blk[i][j]->getrand==blk[i][j-2]->getrand)&&(blk[i][j]->getrand==blk[i][j-1]->getrand))
                {
                      j++;
                }
                else if(j<=7&&(blk[i][j]->getrand==blk[i][j+2]->getrand)&&(blk[i][j]->getrand==blk[i][j+1]->getrand))
                {
                      j++;
                }
                else if(i<=7&&(blk[i][j]->getrand==blk[i+1][j]->getrand)&&(blk[i][j]->getrand==blk[i+2][j]->getrand))
                {
                      j++;
                }
                else if(j>=1&&j<=8&&(blk[i][j]->getrand==blk[i][j+1]->getrand)&&(blk[i][j]->getrand==blk[i][j-1]->getrand))
                {
                      j++;
                }
                qDebug()<<"i"<<i<<"j"<<j;
                qDebug()<<blk[i][j]->getrand;
            }
        }
    }
    while(1)
    {
        if(check()==0)break;
        fall();
        randverse2();
    }
}

void game::fall()
{
        for(int i=9;i>=0;--i)
        {
            for(int j=9;j>=0;--j)
            {
                for(int k=i-1;k>=0;--k)
                {
                        if(blk[i][j]->getrand==0&&blk[k][j]->getrand!=0)
                        {
                            blk[i][j]->getrand=blk[k][j]->getrand;
                            blk[k][j]->getrand=0;
                        }
                }

            }
        }
}

void game::Forstar(int r1, int c1,int r2,int c2)
{
    int tobeclear=(blk[r1][c1]->getrand!=5)?blk[r1][c1]->getrand:blk[r2][c2]->getrand;
    tobeclear=(tobeclear<10&&tobeclear!=0)?tobeclear:tobeclear/10;
    for(int i=0;i<10;++i)
    {
        for(int j=0;j<10;++j)
        {
            int temp=(blk[i][j]->getrand<10&&blk[i][j]->getrand!=5&&blk[i][j]->getrand>0)?blk[i][j]->getrand:blk[i][j]->getrand/10;
            if(temp==tobeclear)
            {
                if(blk[i][j]->getrand<10)blk[i][j]->getrand=0;
                else if(blk[i][j]->getrand>10)
                {
                    Destroy *d;
                    int tempnum=blk[i][j]->getrand%10;
                    switch (tempnum) {
                    case 1:
                        d=new forhori;
                        d->toclear(blk,blk[i][j],0);
                        delete d;
                        break;
                    case 2:
                        d=new forvertical;
                        d->toclear(blk,blk[i][j],0);
                        delete d;
                        break;
                    case 3:
                        d=new fornine;
                        d->toclear(blk,blk[i][j],0);
                        delete d;
                        break;
                    default:
                        break;
                    }
                }
            }
        }
    }
    if(blk[r1][c1]->getrand==5)blk[r1][c1]->getrand=0;
    if(blk[r2][c2]->getrand==5)blk[r2][c2]->getrand=0;


}

void game::start()
{

    int basic[12][12];
    for(int i=0;i<12;++i)
    {
        for(int j=0;j<12;++j)
        {
            basic[i][j]=-1;
        }
    }

    for(int i=1;i<11;++i)
    {
        for(int j=1;j<11;++j)
        {
            int k=rand()%4+1;
            basic[i][j]=k;
        }
    }

    bool flag=0;
    do{
           flag = 0;
           for(int i=1;i<11;++i)
           {
               for(int j=1;j<11;++j)
               {
                   if((basic[i][j]==basic[i+1][j]&&basic[i][j]==basic[i-1][j])||(basic[i][j]==basic[i][j+1]&&basic[i][j]==basic[i][j-1]))
                   {
                       basic[i][j]=(basic[i][j]+1)%4+1;
                       flag = 1;
                   }
               }
           }
       }while(flag);

    for(int i=0;i<10;++i)
    {
        for(int j=0;j<10;++j)
        {
            blk[i][j]->getrand=basic[i+1][j+1];
            blk[i][j]->setpic();
            ori[i][j]=blk[i][j]->getrand;
        }
    }

}

bool game::check()
{
    qDebug()<<"incheck";
    bool flag[5];
    for(int i=0;i<5;++i)flag[i]=0;
    for(int i=0;i<10;++i)
    {
        for(int j=0;j<10;++j)
        {
            flag[0]=For5(i,j);
            if(flag[0]==1)return 1;
        }
    }
    for(int i=0;i<10;++i)
    {
        for(int j=0;j<10;j++)
        {
            flag[1]=ForLT(i,j);
            if(flag[1]==1)return 1;
        }
    }
    for(int i=0;i<10;++i)
    {
        for(int j=0;j<10;j++)
        {
            flag[2]=For4(i,j);
            if(flag[2]==1)return 1;
        }
    }
    for(int i=0;i<10;++i)
    {
        for(int j=0;j<10;++j)
        {
            flag[3]=For3(i,j);
            if(flag[3]==1)return 1;
        }
    }
    return 0;
}

void game::blkclick(int row,int col)
{
    if(ifclicked==false)
    {
        setclickpic(blk[row][col]);
        ifclicked=true;
        rblk1=row;
        cblk1=col;
    }
    else
    {
        if((rblk1==row)&&((cblk1-1)==col))
        {
             *blk[row][col] - blk[rblk1][cblk1];
            judge(rblk1,cblk1,row,col);
            ifclicked=false;
        }
        else if(rblk1==row&&((cblk1+1)==col))
        {
             *blk[rblk1][cblk1]-blk[row][col];
            judge(rblk1,cblk1,row,col);
             ifclicked=false;
        }
        else if(rblk1-1==row&&cblk1==col)
        {
             *blk[row][col]|blk[rblk1][cblk1];
            judge(row,col,rblk1,cblk1);
            ifclicked=false;
        }
        else if(rblk1+1==row&&cblk1==col)
        {
             *blk[rblk1][cblk1]|blk[row][col];
            judge(row,col,rblk1,cblk1);
              ifclicked=false;
        }
        else
        {
            setclickpic(blk[rblk1][cblk1]);
            ifclicked=false;
        }
    }


}


void game::setclickpic(block *b)
{
    if(ifclicked==false)
    {
         b->button->setIconSize(b->button->size());
        switch (b->getrand) {
        case 1:
            b->button->setIcon(QIcon(QPixmap(":/blue_ori-1.png")));
            break;
        case 11:
            b->button->setIcon(QIcon(QPixmap(":/blue_line-1.png")));
            break;
        case 12:
            b->button->setIcon(QIcon(QPixmap(":/blue_shoot-1.png")));
            break;
        case 13:
            b->button->setIcon(QIcon(QPixmap(":/blue_star-1.png")));
            break;
        case 2:
            b->button->setIcon(QIcon(QPixmap(":/red_ori-1.png")));
            break;
        case 21:
            b->button->setIcon(QIcon(QPixmap(":/red_line-1.png")));
            break;
        case 22:
            b->button->setIcon(QIcon(QPixmap(":/red_shoot-1.png")));
            break;
        case 23:
            b->button->setIcon(QIcon(QPixmap(":/red_star-1.png")));
            break;
        case 3:
            b->button->setIcon(QIcon(QPixmap(":/pur_ori-1.png")));
            break;
        case 31:
            b->button->setIcon(QIcon(QPixmap(":/pur_line-1.png")));
            break;
        case 32:
            b->button->setIcon(QIcon(QPixmap(":/pur_shoot-1.png")));
            break;
        case 33:
            b->button->setIcon(QIcon(QPixmap(":/pur_star-1.png")));
            break;
        case 4:
            b->button->setIcon(QIcon(QPixmap(":/green_ori-1.png")));
            break;
        case 41:
            b->button->setIcon(QIcon(QPixmap(":/gre_line-1.png")));
            break;
        case 42:
            b->button->setIcon(QIcon(QPixmap(":/green_shoot-1.png")));
            break;
        case 43:
            b->button->setIcon(QIcon(QPixmap(":/green_star-1.png")));
            break;
        case 5:
            b->button->setIcon(QIcon(QPixmap(":/bumb-1.png")));
            break;
        default:
            break;
        }
    }
    else
    {
        b->setpic();
    }

}


