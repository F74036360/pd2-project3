#ifndef BLOCK_H
#define BLOCK_H
#include <QString>
#include <QObject>
#include <QWidget>
#include <QIcon>
#include <QPushButton>
#include <cstdlib>
#include <ctime>
#include <QTimer>
class block : public QObject
{
    Q_OBJECT
public:
    explicit block(QWidget *parent, int row, int col);
    ~block();
    QPushButton *button;
    void Rand();
    void setpic();
    int getrand;
    void operator -(block *b);
    void operator |(block *b);
    int row,col;
signals:
    void Click(int row,int col);
    void aftermove();
    void tomove();
public slots:
    void click();
    void toleft();
    void toright();
    void toup();
    void todown();

private:
   // int row,col;
    int i,j;
    QTimer *time;
    int shift;
};


#endif // BLOCK_H
