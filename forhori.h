#ifndef FORHORI_H
#define FORHORI_H
#include "Destroy.h"
#include "block.h"
#include "for3.h"
#include "for4.h"
#include "for5.h"
#include "forlort.h"
#include "fornine.h"
#include "forvertical.h"
#include "game.h"
class forhori :public Destroy
{
public:
    forhori();
    virtual~forhori();
    virtual void getsomething(block *blk[10][10],block *clicked,int more);
    virtual void toclear(block *blk[10][10],block *clicked,int moreclear);
    virtual int ifmore(block *blk[10][10],block *clicked);

};

#endif // FORHORI_H
