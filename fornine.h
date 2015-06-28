#ifndef FORNINE_H
#define FORNINE_H

#include "Destroy.h"
#include "block.h"
#include "for3.h"
#include "for4.h"
#include "for5.h"
#include "forhori.h"
#include "forlort.h"
#include "game.h"

class fornine:public Destroy
{
public:
    fornine();
    virtual~fornine();
    virtual void getsomething(block *blk[10][10],block *clicked,int more);
    virtual void toclear(block *blk[10][10],block *clicked,int moreclear);
    virtual int ifmore(block *blk[10][10],block *clicked);

};

#endif // FORNINE_H
