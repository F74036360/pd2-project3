#ifndef WIN_H
#define WIN_H
#include <QLabel>
#include <QWidget>
#include "game.h"
namespace Ui {
class win;
}

class win :public QWidget
{
    Q_OBJECT
public:
    explicit win(QWidget *parent = 0);
    ~win();
    void check(int score);

private slots:
    void on_pushButton_clicked();

private:
    Ui::win *ui;

};

#endif // WIN_H
