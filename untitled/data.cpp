#include "data.h"

Data::Data(QObject *parent)
    : QObject{parent}
{
    int arr[4][4]={{1,1,1,1},
                      {1,1,0,1},
                      {1,0,0,0},
                     {1,1,0,1}};
    QVector<QVector<int>>v;
    for(int i=0;i<4;i++){
        QVector<int>v1;
        for(int j=0;j<4;j++){
            v1.push_back(arr[i][j]);
        }
        v.push_back(v1);
    }
    for(int i=1;i<=20;i++)
    mData.insert(i,v);

}
