#ifndef COIN_H
#define COIN_H
#include<QTimer>
#include <QPushButton>
//需要现在.pro文件中+=multimedia
//#include<QSound>
class Coin : public QPushButton
{
    Q_OBJECT
public:
    //explicit Coin(QWidget *parent = nullptr);

    Coin(QString bImg);
    int x,y;
    bool flag=false;//正反
    void changeflag();
    QTimer*time1;
    QTimer*time2;
    int min=1;
    int max=8;

    bool animationing=false;
    void mousePressEvent(QMouseEvent*e);
    bool iswin=false;
signals:
};

#endif // COIN_H
