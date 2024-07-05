#include "playscene.h"
#include"data.h"
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

    Data data;
    //初始化每个关卡的二维数组
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            this->gameArr[i][j]=data.mData[this->levelIndex][i][j];
        }}

    //显示金币背景图案
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            // QPixmap pix=QPixmap(":/res/BoardNode(1).png");
            // pix=pix.scaled(pix.width()*1.25,pix.height()*1.25);//要赋值给pix，不然不会变,因为scaled()产生了新对象
            // QLabel*l=new QLabel;
            // l->setGeometry(0,0,pix.width(),pix.height());
            // l->setPixmap(pix);
            // l->setParent(this);
            // l->move(0.5*(this->width()-pix.width()*4)+i*pix.width(),180+j*pix.height());
            QString str;
            if(this->gameArr[i][j]==1){
                str=":/res/Coin0001.png";
            }
            else{
                str=":/res/Coin0008.png";
            }
            Coin*coin=new Coin(str);
            coin->setParent(this);
            coin->move(0.5*(this->width()-(5+coin->width())*4)+i*(coin->width()+5)+2.5,190+j*(5+coin->height()));
            //给金币属性赋值
            coin->x=i;
            coin->y=j;
            coin->flag=this->gameArr[i][j];
            //将金币放入金币数组
            coinarr[i][j]=coin;
            //点击金币翻转
            connect(coin,&Coin::clicked,[=](){
                coin->changeflag();
                this->gameArr[i][j]=!this->gameArr[i][j];
                //翻转周围金币
                QTimer::singleShot(300,this,[=](){
                    if(coin->x+1<=3){
                        coinarr[coin->x+1][coin->y]->changeflag();
                        this->gameArr[coin->x+1][coin->y]=!this->gameArr[coin->x+1][coin->y];
                    }
                    if(coin->x-1>=0){
                        coinarr[coin->x-1][coin->y]->changeflag();
                        this->gameArr[coin->x-1][coin->y]=!this->gameArr[coin->x-1][coin->y];
                    }
                    if(coin->y+1<=3){
                        coinarr[coin->x][coin->y+1]->changeflag();
                        this->gameArr[coin->x][coin->y+1]=!this->gameArr[coin->x][coin->y+1];
                    }
                    if(coin->y- 1>=0){
                        coinarr[coin->x][coin->y-1]->changeflag();
                        this->gameArr[coin->x][coin->y-1]=!this->gameArr[coin->x][coin->y-1];
                    }
                });

            });

        }
    }
}
void PlayScene::paintEvent(QPaintEvent*){
    // QPainter painter(this);
    // QPixmap pix;
    // pix.load(":/res/OtherSceneBg.png");
    // painter.drawPixmap(0,0,this->width(),this->height(),pix);
    // pix.load(":/res/Title.png");
    // painter.drawPixmap((this->width()-pix.width())*0.5,30,pix.width(),pix.height(),pix);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    QPixmap pix;
    pix.load(":/res/OtherSceneBg.png");

    // 创建一个和原始背景一样大小的新背景
    QPixmap newPix(pix.size());

    // 开始绘制新背景
    QPainter p(&newPix);
    p.drawPixmap(0, 0, pix);  // 首先绘制原始背景

    // 设置一个半透明的颜色层，你可以改变alpha值（0-255）来调节深浅
    // alpha值越大，背景越深；alpha值越小，背景越浅
    QColor color(255, 255,255, 100);  // 参数分别为红，绿，蓝，alpha
    p.fillRect(newPix.rect(), color);  // 在原始背景上覆盖这个颜色层

    p.end();  // 结束绘制

    // 现在newPix就是调节深浅后的背景，你可以用它来设置背景
    painter.drawPixmap(0, 0, this->width(), this->height(), newPix);

    pix.load(":/res/Title.png");
    pix=pix.scaled(pix.width()*0.9,pix.height()*0.9);

    painter.drawPixmap((this->width()-pix.width())*0.5, 50, pix.width(), pix.height(), pix);

}
