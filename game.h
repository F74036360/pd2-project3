#ifndef GAME_H
#define GAME_H

#include <QMainWindow>
#include "block.h"
#include "Destroy.h"
#include <cstdlib>
#include <ctime>
#include <QFont>
#include <QString>
#include "for3.h"
#include "for4.h"
#include "for5.h"
#include "forhori.h"
#include "fornine.h"
#include "forvertical.h"
#include "forlort.h"
#include <QTimer>
#include "win.h"
namespace Ui {
class game;
}

class game : public QMainWindow
{
    Q_OBJECT

public:
    explicit game(QWidget *parent = 0);
    ~game();
    int board[12][12];
    int ori[10][10];
    void renewpic();
    int score;
private slots:
    void blkclick(int row,int col);
    void forzero();
    void counttime();

private:
    Ui::game *ui;
    block *blk[10][10];
    int i,j;
    int rblk1,cblk1;
    bool ifclicked;
    void start();
    void setclickpic(block *b);
    bool judge(int r1,int c1,int r2,int c2);
    bool For5(int row,int col);
    bool For3(int row,int col);
    bool For4(int row,int col);
    void Forstar(int r1,int c1,int r2,int c2);
    bool ForLT(int row,int col);
    void fall();
    bool check();
    void tofill();
    void randverse2();
    QTimer *ttt;
    int count;
    QString str;
    QString str1;
    int stone5;
    int stone4;
    int stoneL;
    QString forstone4;
    QString forstone5;
    QString forstoneL;


};
    #endif // GAME_H
