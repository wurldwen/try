#ifndef MAINWINDOW_H
#define MAINWINDOW_H
//登录界面
#include <QMainWindow>
#include<QLineEdit>
#include<QPushButton>
#include <QVBoxLayout>
#include<QHBoxLayout>
#include<QTimer>
#include<QPainter>
#include"signin.h"
#include"userscene.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent*);

    SignIn*signIn;
    UserScene*userscene;
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
