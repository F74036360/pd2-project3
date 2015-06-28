#ifndef VERTICAL_H
#define VERTICAL_H

#include "Destroy.h"
#include "horizontal.h"
#include "nineblock.h"
#include "heart.h"
#include "block.h"
class vertical:public Destroy
{
public:
    vertical();
    virtual ~vertical();
    virtual void spwan(block *blk[10][10],block *click,int mode);
    virtual void eliminate(block *blk[10][10],block *click);
    virtual int condition(block *blk[10][10],block *click);
};

#endif // VERTICAL_H
