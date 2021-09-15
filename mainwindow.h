#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <sculptor.h>
#include <plotter.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_pushButton_clicked();

    void on_button_putvoxel_clicked();

private:
    Ui::MainWindow *ui;
    Sculptor *q;
    float r,g,b;
    int tamX;
    int tamY;
    int tamZ;
    Plotter *tela;

};
#endif // MAINWINDOW_H
