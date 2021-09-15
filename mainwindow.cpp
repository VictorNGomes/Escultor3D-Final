#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <sculptor.h>
#include <iostream>
#include <plotter.h>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);




}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked() //botão que cria nova scultura
{
    bool ok;

    QString x = ui->x->text();
    QString y = ui->y->text();
    QString z = ui->z->text();

    tamX = x.toInt(&ok,10);
    tamY = y.toInt(&ok,10);
    tamZ = z.toInt(&ok,10);

    ui->widget->x = tamX;
    ui->widget->y = tamY;
    ui->widget->z = tamZ;

    ui->widget->repaint();


    std::cout << tamX << " " <<tamY << " " <<tamZ << " "<< std::endl;




}




void MainWindow::on_button_putvoxel_clicked()
{

}

