#ifndef HORIZONTAL_H
#define HORIZONTAL_H


#include "Destroy.h"
#include "block.h"
#include "nineblock.h"
#include "heart.h"
#include "vertical.h"
class horizontal : public Destroy
{
public:
    horizontal();
    virtual ~horizontal();

    virtual void spwan(block *blk[10][10],block *click,int mode);
    virtual void eliminate(block *blk[10][10],block *click);
    virtual int condition(block *blk[10][10],block *click);
};

#endif // HORIZONTAL_H
