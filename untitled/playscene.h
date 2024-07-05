#ifndef PLAYSCENE_H
#define PLAYSCENE_H
#include<QMenuBar>
#include<QPainter>
#include<QMainWindow>
#include<QLabel>
#include<mypushbutton.h>
#include"coin.h"
class PlayScene : public QMainWindow
{
    Q_OBJECT
public:
    //explicit PlayScene(QWidget *parent = nullptr);
    PlayScene(int levelnum);
    int levelIndex;
    void paintEvent(QPaintEvent*);
    int gameArr[4][4];//维护每个关卡具体数据
    Coin*coinarr[4][4];
    bool iswin;
signals:
    void cback();
};

#endif // PLAYSCENE_H
