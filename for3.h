#ifndef FOR3_H
#define FOR3_H
#include "Destroy.h"
#include "block.h"
#include "forlort.h"
#include "for4.h"
#include "for5.h"
#include "forhori.h"
#include "fornine.h"
#include "forvertical.h"

class for3:public Destroy
{
public:
    for3();
    virtual~for3();
    virtual void getsomething(block *blk[10][10],block *clicked,int more);
    virtual void toclear(block *blk[10][10],block *clicked, int moreclear);
    virtual int ifmore(block *blk[10][10],block *clicked);

};

#endif // FOR3_H
