#include "plotter.h"
#include "QPainter"
#include "QBrush"
#include "QPen"
#include "sculptor.h"
#include "mainwindow.h"
#include <QMouseEvent>
#include <iostream>

Plotter::Plotter(QWidget *parent) : QWidget(parent)
{


    s = new Sculptor(x,y,z);

    r = 0;
    g = 0;
    b = 0;
}

void Plotter::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QBrush brush;
    QPen pen; 




    brush.setColor(QColor(255,255,255) );
    brush.setStyle(Qt::SolidPattern);

    pen.setColor(QColor(0,0,0));
    pen.setWidth(2);
    painter.setBrush(brush);
    painter.setPen(pen);

    painter.setBrush(brush);

    largura = width()/x;
    altura = height()/y;

    for(int i=0; i<x; i++){
        for(int j=0; j<y; j++){
            painter.drawRect(largura*i,altura*j,width()/x,height()/y);
        }

    }



    for(int i=0; i<x; i++){
        for(int j=0; j<y; j++){
            if(s->VoxelIsOn(i,j,z_atual)){

               brush.setColor(QColor(s->getColorR(),s->getColorG(),s->getColorB()));
               painter.setBrush(brush);
               painter.drawRect(largura*i,altura*j,width()/x,height()/y);
            }
        }
  }



}

void Plotter::mouseMoveEvent(QMouseEvent *event)
{
    emit mudouX(event->x());
    emit mudouY(event->y());

    emit posX((event->x())/largura);
    emit posY((event->y())/altura);

    int x1 = (event->x())/largura;
    int y1 = (event->y())/altura;

    PaintPlane(x1,y1,z_atual);
    std:: cout << "Paint Plane called"<< std::endl;

    repaint();

//    if(event->button() == Qt::LeftButton){ ;

//    }
}

void Plotter::PaintPlane(int x, int y, int z)
{
    s->setColor((r/255.0),(g/255.0),(b/255.0),1);

    std::cout << r << std :: endl;

    s->putVoxel(x,y,z);
    repaint();

}

void Plotter::slideR(int r)
{
    this->r = r;

}

//vector<vector<Voxel> > Plotter::PaintPlane(int x, int y)
//{
//    vector<vector<Voxel>> Maux;
//    Maux[0].resize(y);
//    Maux.resize(x);

//    Maux[x][y].isOn = true;
//    Maux[x][y].r = 255;
//    Maux[x][y].g = 200;
//    Maux[x][y].b = 0;
//    Maux[x][y].a = 255;

//    return Maux;
//}







