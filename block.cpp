#include "block.h"
#include <QDebug>

block::block(QWidget *parent, int Row, int Col):QObject (parent)
{
    row=Row;
    col=Col;
    button=new QPushButton(parent);
    button->setGeometry(50*col+10,50*row+10,50,50);
    button->setFlat(true);
    button->setIconSize(button->size());
    connect(button,SIGNAL(clicked()),this,SLOT(click()));

    shift=1;
    time=new QTimer();

}

block::~block()
{
}

void block::click()
{
    emit Click(row,col);
}
void block::Rand()
{
    getrand=rand()%4+1;
}

void block::setpic()
{
    switch (getrand) {
    case 1:
        button->setIcon(QIcon(QPixmap(":/blue_ori.png")));
        button->setIconSize(button->size());
        break;
    case 11:
        button->setIcon(QIcon(QPixmap(":/blue_line.png")));
        button->setIconSize(button->size());
        break;
    case 12:
        button->setIcon(QIcon(QPixmap(":/blue_shoot.png")));
        button->setIconSize(button->size());
        break;
    case 13:
        button->setIcon(QIcon(QPixmap(":/blue_star.png")));
        button->setIconSize(button->size());
        break;

    case 2:
        button->setIcon(QIcon(QPixmap(":/red_ori.png")));
        button->setIconSize(button->size());
        break;
    case 21:
        button->setIcon(QIcon(QPixmap(":/red_line.png")));
        button->setIconSize(button->size());
        break;
    case 22:
        button->setIcon(QIcon(QPixmap(":/red_shoot.png")));
        button->setIconSize(button->size());
        break;
    case 23:
        button->setIcon(QIcon(QPixmap(":/red_star.png")));
        button->setIconSize(button->size());
        break;

    case 3:
        button->setIcon(QIcon(QPixmap(":/pur_ori.png")));
        button->setIconSize(button->size());
        break;
    case 31://hori
        button->setIcon(QIcon(QPixmap(":/pur_line.png")));
        button->setIconSize(button->size());
        break;
    case 32://verti
        button->setIcon(QIcon(QPixmap(":/pur_shoot.png")));
        button->setIconSize(button->size());
        break;
    case 33://nine
        button->setIcon(QIcon(QPixmap(":/pur_star.png")));
        button->setIconSize(button->size());
        break;
    case 4:
        button->setIcon(QIcon(QPixmap(":/green_ori.png")));
        button->setIconSize(button->size());
        break;
    case 41:
        button->setIcon(QIcon(QPixmap(":/gre_line.png")));
        button->setIconSize(button->size());
        break;
    case 42:
        button->setIcon(QIcon(QPixmap(":/green_shoot.png")));
        button->setIconSize(button->size());
        break;
    case 43:
        button->setIcon(QIcon(QPixmap(":/green_star.png")));
        button->setIconSize(button->size());
        break;
    case 5:
        button->setIcon(QIcon(QPixmap(":/bumb.png")));
        button->setIconSize(button->size());
        break;
    default:
        button->setIcon(QIcon(QPixmap("1")));
        button->setIconSize(button->size());
        break;
    }
}

void block::operator - (block *blk)
{
    if(blk->getrand!=0)
    {
            int temp=blk->getrand;
            blk->getrand=getrand;
            getrand=temp;
    }

    connect(time,SIGNAL(timeout()),this,SLOT(toright()));
    connect(blk->time,SIGNAL(timeout()),blk,SLOT(toleft()));
    time->start(50);
    blk->time->start(50);

}

void block::operator | (block *blk)
{
    if(blk->getrand!=0)
    {
        int temp=blk->getrand;
        blk->getrand=getrand;
        getrand=temp;
    }
    connect(time,SIGNAL(timeout()),this,SLOT(todown()));
    connect(blk->time,SIGNAL(timeout()),blk,SLOT(toup()));
    time->start(50);
    blk->time->start(50);

}

void block::todown()
{

    button->setGeometry(col*50+10,row*50+shift*10+10,50,50);
    shift++;
    if(shift==6)
    {
        shift=1;
        disconnect(time,SIGNAL(timeout()),this,SLOT(todown()));
        button->setGeometry(col*50+10,row*50+10,50,50);
        setpic();
        emit aftermove();
    }
}

void block::toup()
{

    button->setGeometry(col*50+10,row*50-shift*10+10,50,50);
    shift++;
    if(shift==6)
    {
        shift=1;
        disconnect(time,SIGNAL(timeout()),this,SLOT(toup()));
        button->setGeometry(col*50+10,row*50+10,50,50);
        setpic();
        emit aftermove();
    }

}

void block::toright()
{
    button->setGeometry(col*50+shift*10+10,row*50+10,50,50);
    shift++;
    if(shift==6)
    {
        shift=1;
        disconnect(time,SIGNAL(timeout()),this,SLOT(toright()));
        button->setGeometry(col*50+10,row*50+10,50,50);
        setpic();
        emit aftermove();
    }
}

void block::toleft()
{
    button->setGeometry(col*50-shift*10+10,row*50+10,50,50);
    shift++;
    if(shift==6)
    {
        shift=1;
        disconnect(time,SIGNAL(timeout()),this,SLOT(toleft()));
        button->setGeometry(col*50+10,row*50+10,50,50);
        setpic();
        emit aftermove();
    }
}
