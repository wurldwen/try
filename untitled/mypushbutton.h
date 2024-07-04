#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H
#include <QPushButton>
class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    //explicit MyPushButton(QWidget *parent = nullptr);
    MyPushButton(QString nImg,QString pImg="");

    QString nImg;
    QString pImg;

    void jump(char s,int length,int time);//跳跃·效果
    //重写按下和释放事件
    void mousePressEvent(QMouseEvent*e);
    void mouseReleaseEvent(QMouseEvent*e);

signals:
};

#endif // MYPUSHBUTTON_H
