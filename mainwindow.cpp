#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <QPainter>
//当前值
const int u =43;
//最大刻度
const int nMax = 100;
//最小刻度
const int nMin = 0;
//旋转角度
const double nPercentRotate = 40;
//
const int nMaxRadus = 200;
const int nMinRadus = 150;
const int nDistance = 50;
//最外面的大圆
const int nDistance2 = 70;
//原点
int nOrgXpos     = 0;
int nOrgYpos     = 0;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->mainToolBar->hide();

    nOrgXpos = width() / 2;
    nOrgYpos = height() / 2;
    l1 = new QLabel(this);
    l1->setText(QString("44"));
    l1->move(nOrgXpos   ,nOrgYpos );
    l2 = new QLabel(this);
    l3 = new QLabel(this);
    l2->setText(QString("Min"));
    //这个地方要注意
    l2->move(nOrgXpos - nMinRadus, nOrgYpos + nMinRadus );
    l3->setText(QString("Max"));
    l3->move(nOrgXpos  + (nMinRadus ) , nOrgYpos +  (nMinRadus ) );
}


MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QColor use(112,222,121);
    QColor nouse(223,123,111);
    QPainter p(this);

    double nRotate = (360.0 - 2 * nPercentRotate) / (nMax - nMin);

    p.setRenderHint(QPainter::Antialiasing);
    p.setRenderHint(QPainter::SmoothPixmapTransform);


    p.save();
    p.translate(nOrgXpos, nOrgYpos);
    p.rotate(nPercentRotate);
    p.setPen(use);
    for(int i = 0 ; i < u; i++){
        p.drawLine(0,nMinRadus,0,nMaxRadus);
        p.rotate(nRotate);
    }
    p.setPen(nouse);
    for(int i = u ; i < nMax ; i++){
        p.drawLine(0,nMinRadus,0,nMaxRadus);
        p.rotate(nRotate);
    }
    p.restore();

    /*
    p.setPen(QColor(11,22,33));
    p.drawEllipse(nOrgXpos - nMinRadus + nDistance/2  , nOrgYpos  - nMinRadus  + nDistance/2   , nMinRadus * 2 - nDistance , nMinRadus * 2 - nDistance );
    p.restore();
    p.setPen(QColor(11,22,33));
    p.drawEllipse(nOrgXpos -  nMaxRadus - nDistance2/2  , nOrgYpos  -  nMaxRadus -  nDistance2/2 , nMaxRadus * 2 + nDistance2, nMaxRadus * 2 + nDistance2);
    */

}
