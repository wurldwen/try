#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    this->setMinimumSize(800,500);
    QPushButton*shouye=new QPushButton();
    QPushButton*chaxun=new QPushButton();
    QPushButton*wode=new QPushButton();
    wode->setMinimumSize(400,80);
    shouye->setMinimumSize(400,80);
    chaxun->setMinimumSize(310,40);
    QPushButton*feiji=new QPushButton();
    QPushButton*huoche=new QPushButton();
    QPushButton*qiche=new QPushButton();
    feiji->setMinimumSize(120,60);
    huoche->setMinimumSize(120,60);
    qiche->setMinimumSize(120,60);
    QLineEdit*sousuo=new QLineEdit();
    sousuo->setMinimumSize(270,40);
    QLineEdit*chufa=new QLineEdit();
    QLineEdit*mudi=new QLineEdit();
    QLineEdit*shijian=new QLineEdit();
    chufa->setMinimumSize(170,40);
    mudi->setMinimumSize(170,40);
    shijian->setMinimumSize(435,40);
    QWidget *centralWidget = new QWidget(this);
    QHBoxLayout*h1=new QHBoxLayout();
    h1->addItem(new QSpacerItem(284, 40, QSizePolicy::Minimum, QSizePolicy::Expanding));  // 添加弹簧
    h1->addWidget(sousuo,1);
    h1->addItem(new QSpacerItem(250, 40, QSizePolicy::Minimum, QSizePolicy::Expanding));  // 添加弹簧
    QHBoxLayout*chepiao=new QHBoxLayout();
    chepiao->addItem(new QSpacerItem(125, 60, QSizePolicy::Minimum, QSizePolicy::Expanding));  // 添加弹簧
    chepiao->addWidget(qiche);
    chepiao->addWidget(huoche);
    chepiao->addWidget(feiji);
    chepiao->addItem(new QSpacerItem(125, 60, QSizePolicy::Minimum, QSizePolicy::Expanding));  // 添加弹簧
    QHBoxLayout*didian=new QHBoxLayout();
    didian->addItem(new QSpacerItem(220, 35, QSizePolicy::Minimum, QSizePolicy::Expanding));  // 添加弹簧
    didian->addWidget(chufa);
    didian->addWidget(mudi);
    didian->addItem(new QSpacerItem(220, 35, QSizePolicy::Minimum, QSizePolicy::Expanding));  // 添加弹簧
    QHBoxLayout*h2=new QHBoxLayout();
    h2->addItem(new QSpacerItem(220, 35, QSizePolicy::Minimum, QSizePolicy::Expanding));  // 添加弹簧
    h2->addWidget(shijian);
    h2->addItem(new QSpacerItem(220, 35, QSizePolicy::Minimum, QSizePolicy::Expanding));  // 添加弹簧
    QHBoxLayout*h3=new QHBoxLayout();
    h3->addItem(new QSpacerItem(240, 40, QSizePolicy::Minimum, QSizePolicy::Expanding));  // 添加弹簧
    h3->addWidget(chaxun);
    h3->addItem(new QSpacerItem(240, 40, QSizePolicy::Minimum, QSizePolicy::Expanding));  // 添加弹簧
    QHBoxLayout*dibu=new QHBoxLayout();
    dibu->addWidget(shouye);
    dibu->addWidget(wode);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);
    layout->addItem(new QSpacerItem(800, 20, QSizePolicy::Minimum, QSizePolicy::Expanding));  // 添加弹簧

    layout->addLayout(h1);
    layout->addItem(new QSpacerItem(800, 80, QSizePolicy::Minimum, QSizePolicy::Expanding));  // 添加弹簧

    layout->addLayout(chepiao);
    layout->addLayout(didian);
    layout->addLayout(h2);
    layout->addItem(new QSpacerItem(800, 20, QSizePolicy::Minimum, QSizePolicy::Expanding));  // 添加弹簧

    layout->addLayout(h3);
    layout->addItem(new QSpacerItem(800, 105, QSizePolicy::Minimum, QSizePolicy::Expanding));  // 添加弹簧

    layout->addLayout(dibu);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);
}
void MainWindow::paintEvent(QPaintEvent*){
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing,true);
    QPixmap pix;
    pix.load(":/HomePage/CarBackground.jpg");
    painter.drawPixmap(0,0,width(),this->height(),pix);
}
MainWindow::~MainWindow()
{
    delete ui;
}
// QWidget *centralWidget = new QWidget(this);
// QVBoxLayout *layout = new QVBoxLayout(centralWidget);

// QPushButton *button1 = new QPushButton("Button 1", centralWidget);
// QPushButton *button2 = new QPushButton("Button 2", centralWidget);
// QPushButton *button3 = new QPushButton("Button 3", centralWidget);

// layout->addWidget(button1);
// layout->addWidget(button2);
// layout->addWidget(button3);

// centralWidget->setLayout(layout);
// setCentralWidget(centralWidget);
