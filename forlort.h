#ifndef FORLORT_H
#define FORLORT_H

#include "Destroy.h"
#include "for3.h"
#include "for4.h"
#include "for5.h"
#include "forhori.h"
#include "fornine.h"
#include "forvertical.h"
#include "block.h"

class forLorT:public Destroy
{
public:
    forLorT();
    virtual~forLorT();
    virtual void getsomething(block *blk[10][10],block *clicked,int more);
    virtual void toclear(block *blk[10][10],block *clicked, int moreclear);
    virtual int ifmore(block *blk[10][10],block *clicked);
    int center;
};

#endif // FORLORT_H
