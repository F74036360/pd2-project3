#ifndef HEART_H
#define HEART_H

#include <QObject>
#include <QWidget>
#include "block.h"
#include "Destroy.h"
#include "horizontal.h"
#include "nineblock.h"
#include "vertical.h"
class heart :public Destroy
{
public:
    heart();
    virtual ~heart();
    virtual void spwan(block *blk[10][10],block *click,int mode);
    virtual void eliminate(block *blk[10][10],block *click);
    virtual int condition(block *blk[10][10],block *click);
};

#endif // HEART_H
