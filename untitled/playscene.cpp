#include "playscene.h"

PlayScene::PlayScene(int n)
{
    this->levelIndex=n;
    //设置固定大小
    setFixedSize(320,588);
    //设置图标
    setWindowIcon(QIcon(":/res/Coin0001.png"));
    //设置标题
    setWindowTitle("游戏场景");
    //创建菜单栏;
    QMenuBar*bar=menuBar();
    setMenuBar(bar);
    //创建开始菜单
    QMenu*start=bar->addMenu("开始");
    //创建退出菜单项
    QAction*quit=start->addAction("退出");
    connect(quit,&QAction::triggered,[=](){this->close();});
    MyPushButton*back=new MyPushButton(":/res/BackButton.png",":/res/BackButtonSelected.png");
    back->setParent(this);
    back->move(this->width()-back->width(),this->height()-back->height());
    //点击返回
    connect(back,&MyPushButton::clicked,[=](){QTimer::singleShot(200,this,[=](){cback();}) ;});
    //显示当前关卡数
    QLabel*label=new QLabel;
    label->setParent(this);
    QFont font;
    font.setFamily("华文新魏");
    font.setPointSize(20);
    QString str=QString("Level:%1").arg(this->levelIndex);
    //将字体设置到标签控件中
    label->setFont(font);

    label->setText(str);
    label->setGeometry(30,this->height()-50,120,50);
    //显示金币背景图案
    // for(int i=0;i<4;i++){
    //     for(int j=0;j<4;i++){
    //         QLabel*l=new QLabel;
    //         l->setGeometry(0,0,80,80);
    //         l->setPixmap(QPixmap(":/res/BoardNode(1).png"));
    //         l->setParent(this);
    //         l->move(57+i*80,200+j*80);
    //     }
    // }
}
void PlayScene::paintEvent(QPaintEvent*){
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/OtherSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
    pix.load(":/res/Title.png");
    painter.drawPixmap((this->width()-pix.width())*0.5,30,pix.width(),pix.height(),pix);

}
