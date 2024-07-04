#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //配置主场景

    //设置固定大小
    setFixedSize(320,588);

    //设置图标
    setWindowIcon(QIcon(":/res/Coin0001.png"));

    //设置标题
    setWindowTitle("翻金币主场景");

    //退出按钮实现
    connect(ui->actionquit,&QAction::triggered,[=](){
        this->close();
    });

    //开始按钮实现
    MyPushButton*startButton=new MyPushButton(":/res/MenuSceneStartButton.png");
    startButton->setParent(this);
    startButton->move(this->width()*0.5-startButton->width()*0.5,this->height()*0.7);
    levelscene=new choosetheme;
    //监听选择关卡的返回按钮信号
    connect(levelscene,&choosetheme::cback,this,[=](){
        QTimer::singleShot(200,this,[=](){levelscene->hide();this->show();});});

    connect(startButton,&MyPushButton::clicked,[=](){
        //做弹起特效
        startButton->jump('d',20,200);
        //延时进入选择关卡
        QTimer::singleShot(500,this,[=](){
            this->hide();
            levelscene->show();
       });


    });

}
void MainWindow::paintEvent(QPaintEvent*){
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    //画背景上图标
    pix.load(":/res/Title.png");
    pix.scaled(pix.width()*0.5,pix.height()*0.5);
    painter.drawPixmap(10,30,pix);

}
MainWindow::~MainWindow()
{
    delete ui;
}
