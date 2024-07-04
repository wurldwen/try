#ifndef PLAYSCENE_H
#define PLAYSCENE_H
#include<QMenuBar>
#include<QPainter>
#include<QMainWindow>
#include<QTimer>
#include<QLabel>
#include<mypushbutton.h>
class PlayScene : public QMainWindow
{
    Q_OBJECT
public:
    //explicit PlayScene(QWidget *parent = nullptr);
    PlayScene(int levelnum);
    int levelIndex;
    void paintEvent(QPaintEvent*);
signals:
    void cback();
};

#endif // PLAYSCENE_H
