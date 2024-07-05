#include "choosetheme.h"


choosetheme::choosetheme(QWidget *parent)
    : QMainWindow{parent}
{
    //配置关卡场景
    this->setFixedSize(320,588);
    //设置图标
    this->setWindowIcon(QPixmap(":/res/Coin0001.png"));
    //设置标题
    this->setWindowTitle("选择关卡");
    //创建菜单栏;
    QMenuBar*bar=menuBar();
    setMenuBar(bar);
    //创建开始菜单
    QMenu*start=bar->addMenu("开始");
    //创建退出菜单项
    QAction*quit=start->addAction("退出");
    connect(quit,&QAction::triggered,[=](){this->close();});
    //返回按钮
    MyPushButton*back=new MyPushButton(":/res/BackButton.png",":/res/BackButtonSelected.png");
    back->setParent(this);
    back->move(this->width()-back->width(),this->height()-back->height());
    //点击返回
    connect(back,&MyPushButton::clicked,[=](){ cback();});
    //关卡按钮
    for(int i=0;i<20;i++){
        MyPushButton*levelb=new MyPushButton(":/res/LevelIcon.png");
        levelb->setParent(this);
        levelb->move(25+(i%4)*70,160+(i/4)*70);

        connect(levelb,&MyPushButton::clicked,[=](){
            //QString str=QString("您选择的是第%1关").arg(i+1);
            play=new PlayScene(i+1);

            this->hide();
            play->show();
            //要创建后才能connect
            connect(play,&PlayScene::cback,[=](){

                play->hide();
                this->show();delete play;


            });
        });
        QLabel*label=new QLabel;
        label->setParent(this);
        label->setFixedSize(levelb->width(),levelb->height());
        label->setText(QString::number(i+1));
        label->move(25+(i%4)*70,160+(i/4)*70);
        //对齐
        label->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        //设置让鼠标进行穿透，不然关卡按钮检测不到鼠标
        label->setAttribute(Qt::WA_TransparentForMouseEvents);
    }
}
void choosetheme::paintEvent(QPaintEvent*){
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    QPixmap pix;
    pix.load(":/res/OtherSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
    pix.load(":/res/Title.png");
    painter.drawPixmap((this->width()-pix.width())*0.5,30,pix.width(),pix.height(),pix);
}
