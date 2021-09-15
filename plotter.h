#ifndef PLOTTER_H
#define PLOTTER_H

#include <QWidget>
#include "sculptor.h"

class Plotter : public QWidget
{
    Q_OBJECT
public:
    explicit Plotter(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);


   Sculptor *s;
   int x = 10;
   int y = 10;
   int z = 10;


signals:


};

#endif // PLOTTER_H
