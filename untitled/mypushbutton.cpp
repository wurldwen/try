#include "mypushbutton.h"
#include<QDebug>
#include<QPropertyAnimation>
MyPushButton::MyPushButton(QString nImg,QString pImg){
    this->nImg=nImg;
    this->pImg=pImg;

    QPixmap pix;
    bool ret=pix.load(nImg);
    if(!ret){
        qDebug()<<"load failed";
        return;
    }
    //设置图片固定大小
    this->setFixedSize(pix.width(),pix.height());
    //设置不规则图片样式
    this->setStyleSheet("QPushButton{border:0px}");
    //设置图标
    this->setIcon(pix);
    //设置图标大小
    this->setIconSize(QSize(pix.width(),pix.height()));

}
void MyPushButton::jump(char s,int lenth,int time){
    static int count=0;

    if(count==2){
        count=0;
        return;
    }
    count++;
    QPropertyAnimation*animation=new QPropertyAnimation(this,"geometry");
    //动画时间间隔
    animation->setDuration(time);

    switch(s){
    case 'd':
        animation->setStartValue(QRect(this->x(),this->y()+count*lenth,this->width(),this->height()));
        animation->setEndValue(QRect(this->x(),this->y()-lenth+count*lenth,this->width(),this->height()));
        jump('u',lenth,time);
        break;
    case 'u':
        animation->setStartValue(QRect(this->x(),this->y()-count*lenth,this->width(),this->height()));
        animation->setEndValue(QRect(this->x(),this->y()+lenth-count*lenth,this->width(),this->height()));
        jump('d',lenth,time);
        break;
    case 'r':
        animation->setStartValue(QRect(this->x()+count*lenth,this->y(),this->width(),this->height()));
        animation->setEndValue(QRect(this->x()-lenth+count*lenth,this->y(),this->width(),this->height()));
        jump('l',lenth,time);
        break;
    case 'l':
        animation->setStartValue(QRect(this->x()-count*lenth,this->y(),this->width(),this->height()));
        animation->setEndValue(QRect(this->x()+lenth-count*lenth,this->y(),this->width(),this->height()));
        jump('r',lenth,time);
        break;
    default:
        qDebug()<<"Invalid Input to MypushButtonFunction call";
        break;
    }
    //设置弹跳曲线
    animation->setEasingCurve(QEasingCurve::OutBounce);
    //执行动画
    animation->start();
}
void MyPushButton::mousePressEvent(QMouseEvent*e)
{
    if(this->pImg!=""){
        QPixmap pix;
        bool ret=pix.load(pImg);
        if(!ret){
            qDebug()<<"load failed";
            return;
        }
        //设置图片固定大小
        this->setFixedSize(pix.width(),pix.height());
        //设置不规则图片样式
        this->setStyleSheet("QPushButton{border:0px}");
        //设置图标
        this->setIcon(pix);
        //设置图标大小
        this->setIconSize(QSize(pix.width(),pix.height()));
    }

    //让父类执行其它内容
    return QPushButton::mousePressEvent(e);
}

void MyPushButton::mouseReleaseEvent(QMouseEvent*e){
    if(this->pImg!=""){
        QPixmap pix;
        bool ret=pix.load(nImg);
        if(!ret){
            qDebug()<<"load failed";
            return;
        }
        //设置图片固定大小
        this->setFixedSize(pix.width(),pix.height());
        //设置不规则图片样式
        this->setStyleSheet("QPushButton{border:0px}");
        //设置图标
        this->setIcon(pix);
        //设置图标大小
        this->setIconSize(QSize(pix.width(),pix.height()));
    }

    //让父类执行其它内容
    return QPushButton::mouseReleaseEvent(e);
}
