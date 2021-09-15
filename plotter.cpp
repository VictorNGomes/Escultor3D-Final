#include "plotter.h"
#include "QPainter"
#include "QBrush"
#include "QPen"
#include "sculptor.h"
#include "mainwindow.h"

Plotter::Plotter(QWidget *parent) : QWidget(parent)
{


    s = new Sculptor(x,y,z);

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

    painter.drawRect(0,0,width(),height());

    float countx = width()/x;
    float county = height()/y;

    for(int i=0; i<=x; i++){
        for(int j=0; j<=y; j++){
            painter.drawRect(countx*i,county*j,width()/x,height()/y);

        }

    }



}


