#ifndef FOR4_H
#define FOR4_H

#include "Destroy.h"
#include "block.h"
#include "for3.h"
#include "forlort.h"
#include "for5.h"
#include "forhori.h"
#include "fornine.h"
#include "forvertical.h"

class for4:public Destroy
{
public:
    for4();
    virtual~for4();
    virtual void getsomething(block *blk[10][10],block *clicked,int more);
    virtual void toclear(block *blk[10][10],block *clicked,int moreclear);
    virtual int ifmore(block *blk[10][10],block *clicked);
    int center;
};
#endif // FOR4_H
