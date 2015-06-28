#ifndef DESTROY_H
#define DESTROY_H

#include "block.h"

class Destroy
{
public:
    Destroy();
    virtual void getsomething(block *blk[10][10],block *clicked,int more)=0;
    virtual void toclear(block *blk[10][10],block *clicked,int moreclear)=0;
    virtual int ifmore(block *blk[10][10],block *clicked)=0;
    virtual ~Destroy();

};

#endif // DESTROY_H
