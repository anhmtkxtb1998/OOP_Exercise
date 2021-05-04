#include <QApplication>
#include "graph.h"
#include "canvas.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TGraph g(7);
    TCanvas w(&g);
    w.show();

    return a.exec();
}
