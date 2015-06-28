#ifndef FOR5_H
#define FOR5_H
#include "Destroy.h"
#include "block.h"
#include "for3.h"
#include "for4.h"
#include "forlort.h"
#include "forhori.h"
#include "fornine.h"
#include "forvertical.h"

class for5:public Destroy
{
public:
    for5();
    virtual~for5();
    virtual void getsomething(block *blk[10][10],block *clicked,int more);
    virtual void toclear(block *blk[10][10],block *clicked,int moreclear);
    virtual int ifmore(block *blk[10][10],block *clicked);

};
#endif // FOR5_H
