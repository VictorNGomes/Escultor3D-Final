#ifndef PLOTTER_H
#define PLOTTER_H

#include <QWidget>
#include "sculptor.h"
#include <vector>
#include <QMouseEvent>

using namespace std;

class Plotter : public QWidget
{
    Q_OBJECT
public:

    Sculptor *s;
    int x = 10;
    int y = 10;
    int z = 10;
    int z_atual = 0;
    //bool click;
    int r,g,b;


    int largura;
    int altura;



    vector<vector<Voxel>>Mvoxels;



    explicit Plotter(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void PaintPlane(int x, int y, int z);
    void ErasedPlane(int x, int y, int z);


//    void mouseReleaseEvent(QMouseEvent *event);
//    void mousePressEvent(QMouseEvent *event);




public slots:
    void slideR(int r);
    void slideG(int g);
    void slideB(int b);
    void slideZ(int dimz);
    void salvar();




signals:
    void mudouX(int);
    void mudouY(int);
    void posX(int);
    void posY(int);

};

#endif // PLOTTER_H
