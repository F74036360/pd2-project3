#include "win.h"
#include "ui_win.h"

win::win(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::win)
{
    ui->setupUi(this);

    ui->star3->hide();
    ui->star3_2->hide();
    ui->star3_3->hide();
    ui->star2->hide();
    ui->star2_2->hide();
    ui->star1->hide();
    ui->string->hide();
    ui->string->setAlignment(Qt::AlignCenter);

}

win::~win()
{
    delete ui;
}
void win::check(int score)
{
    ui->score->setAlignment(Qt::AlignCenter);
    QString scoretxt=QString::number(score,10);//int to string
    ui->score->setText(scoretxt);
    if(score>=30000)
    {
        QString str="Perfect";
        ui->string->setText(str);
        ui->string->show();
        ui->star3->show();
        ui->star3_2->show();
        ui->star3_3->show();
    }
    else if(score<30000&&score>=10000)
    {
        ui->star2->show();
        ui->star2_2->show();
        QString str="good ?";
        ui->string->setText(str);
        ui->string->show();
    }
    else if(score<10000)
    {
        ui->star1->show();
        QString str="BADDD!";
        ui->string->setText(str);
        ui->string->show();
    }

}

void win::on_pushButton_clicked()
{
    game *g=new game;
    g->show();
    this->close();
}
