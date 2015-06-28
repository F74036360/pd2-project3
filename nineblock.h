#ifndef NINEBLOCK_H
#define NINEBLOCK_H


#include "Destroy.h"
#include "horizontal.h"
#include "block.h"
#include "heart.h"
#include "vertical.h"
class nineblock :public Destroy
{
public:
    nineblock();
    virtual ~nineblock();

    virtual void spwan(block *blk[10][10],block *click,int mode);
    virtual void eliminate(block *blk[10][10],block *click);
    virtual int condition(block *blk[10][10],block *click);
};

#endif // NINEBLOCK_H
