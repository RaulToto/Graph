#include "mainwindow.h"
#include <graph.h>
#include <graph.cpp>
#include <vertex.h>
#include <vertex.cpp>
#include <QApplication>

int main(int argc, char *argv[])
{
    //QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    Graph<string,int> s;
    s.insertVertex("ada");
    //s.insertVertex("aed");
    //s.print();
    //return a.exec();
}
