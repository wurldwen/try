#ifndef DATA_H
#define DATA_H

#include <QObject>
#include<QMap>
#include<QVector>

class Data : public QObject
{
    Q_OBJECT
public:
    explicit Data(QObject *parent = nullptr);
    QMap<int,QVector<QVector<int>>>mData;
signals:
};

#endif // DATA_H
