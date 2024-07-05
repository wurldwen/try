#include "coin.h"

Coin::Coin(QString bImg){
    QPixmap pix;
    bool ret=pix.load(bImg);
    if(!ret){
        QString str=QString("path%1load failed").arg(bImg);
        qDebug()<<str;
        return;
    }
    //使用平滑变化防止清晰度受损
    pix=pix.scaled(pix.width()*1.25,pix.height()*1.25 ,Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    //设置图片固定大小
    this->setFixedSize(pix.width(),pix.height());
    //设置不规则图片样式
    this->setStyleSheet("QPushButton{border:0px}");
    //设置图标
    this->setIcon(pix);
    //设置图标大小
    this->setIconSize(QSize(pix.width(),pix.height()));
    //初始化定时器
    time1=new QTimer(this);
    time2=new QTimer(this);
    //监听正面翻反面信号
    connect(time1,&QTimer::timeout,[=](){
        QPixmap pix;
        QString str=QString(":res/Coin000%1.png").arg(this->min++);
        pix.load(str);
        pix=pix.scaled(pix.width()*1.25,pix.height()*1.25 ,Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
        //设置图片固定大小
        this->setFixedSize(pix.width(),pix.height());
        //设置不规则图片样式
        this->setStyleSheet("QPushButton{border:0px}");
        //设置图标
        this->setIcon(pix);
        //设置图标大小
        this->setIconSize(QSize(pix.width(),pix.height()));
        if(this->min>this->max){
            this->min=1;
            animationing=false;
            time1->stop();
        }
    });
    //监听反面翻正面信号
    connect(time2,&QTimer::timeout,[=](){
        QPixmap pix;
        QString str=QString(":res/Coin000%1.png").arg(this->max--);
        pix.load(str);
        pix=pix.scaled(pix.width()*1.25,pix.height()*1.25 ,Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
        //设置图片固定大小
        this->setFixedSize(pix.width(),pix.height());
        //设置不规则图片样式
        this->setStyleSheet("QPushButton{border:0px}");
        //设置图标
        this->setIcon(pix);
        //设置图标大小
        this->setIconSize(QSize(pix.width(),pix.height()));
        if(this->min>this->max){
            this->max=8;
            animationing=false;
            time2->stop();
        }
    });
}
void Coin::changeflag(){
    animationing=true;
    if(this->flag){
        time1->start(30);
        this->flag=false;
    }
    else{
        time2->start(30);
        this->flag=true;
    }
}
void Coin::mousePressEvent(QMouseEvent*e){
    if(this->animationing||this->iswin)return;
    else return QPushButton::mousePressEvent(e);
}

