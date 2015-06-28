#ifndef FORVERTICAL_H
#define FORVERTICAL_H

#include "Destroy.h"
#include "block.h"
#include "for3.h"
#include "for4.h"
#include "for5.h"
#include "forhori.h"
#include "fornine.h"
#include "forlort.h"
#include "game.h"

class forvertical:public Destroy
{
public:
    forvertical();
    virtual~forvertical();
    virtual void getsomething(block *blk[10][10],block *clicked,int more);
    virtual void toclear(block *blk[10][10],block *clicked,int moreclear);
    virtual int ifmore(block *blk[10][10],block *clicked);

};
#endif // FORVERTICAL_H
