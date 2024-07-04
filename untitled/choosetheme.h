#ifndef CHOOSETHEME_H
#define CHOOSETHEME_H
#include"playscene.h"
class choosetheme : public QMainWindow
{
    Q_OBJECT
public:
    explicit choosetheme(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent*);//此处为重写虚函数，不能改名
    PlayScene*play=NULL;
signals:
    //写一个自定义信号，告诉主场景返回
    void cback();
};

#endif // CHOOSETHEME_H
