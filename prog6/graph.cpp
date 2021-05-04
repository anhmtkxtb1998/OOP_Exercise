#include "graph.h"
#include <math.h>
#include <QDebug>
#include <QVector>

TGraph::TGraph(int n, TMatrix m){
    count = n;
    matrix = m;
}

TGraph::~TGraph(){

}
void TGraph::setCount(int c)
{
    count = c;
}
void TGraph::setMatrix(TMatrix m)
{
    matrix = m;
}
void TGraph::draw(QPainter *p, QRect r, QColor c)
{
    qreal cw = 0.5*r.width();
    qreal ch = 0.5*r.height();
    qreal cr = 0.9*(cw>ch?ch:cw);
    qreal a = 2.0*acos(-1.0)/count;

    qreal rad = 20;
    qreal arrowSize = 10;

//    qDebug() << "r.width " << r.width();
//    qDebug() << "r.height " << r.height();
//    qDebug() << "cw " << cw;
//    qDebug() << "ch " << ch;
//    qDebug() << "acos " << acos(-1.0);
//    qDebug() << "count " << count;
//    qDebug() << "a " << a;

    QRectF *t = new QRectF[count];
    for (int i=0; i<count; i++)
    {
        t[i] = QRectF(cw+cr*sin(i*a) - rad, ch-cr*cos(i*a) - rad, 2*rad, 2*rad);
    }
    QPen pen = QPen(Qt::black);
    pen.setStyle(Qt::DashLine);
    p->setPen(pen);
//    p->setPen(QPen(QBrush(Qt::black), 1, Qt::DashLine));
//    p->setBrush(QBrush(c));
//    p->drawPolygon(t,count);
    //p->drawEllipse(QPointF(cw, ch), qreal(cr), qreal(cr));

    pen.setStyle(Qt::SolidLine);
    p->setPen(pen);




    p->setBrush(QBrush(c));

    QFont font;
    qreal cf = 0.5*rad;
    font.setPointSize(cf);
    font.setBold(true);
    p->setFont(font);

    for (int i=0; i<count; i++)
    {
        p->drawEllipse(t[i]);
        p->drawText(t[i], QString().setNum(i+1), QTextOption(Qt::AlignCenter));
    }

    for (int i=0; i<count; i++)
    {
        for (int j=0; j<count; j++)
        {
            if (i != j && matrix.Get()[i][j] == 1)
            {
                QLineF line(t[i].center(), t[j].center());
                double angle = atan2(-line.dy(), line.dx());

                qDebug() << "atan2 " << angle;
                qDebug() << "angle " << line.angle() * M_PI/180;

                line.setP1(line.p1() + QPoint(+rad*cos(angle), -rad*sin(angle)));
                line.setP2(line.p2() - QPoint(+rad*cos(angle), -rad*sin(angle)));

                QPointF arrowP1 = line.p1() + QPointF(sin(angle + M_PI / 3) * arrowSize,
                                                    cos(angle + M_PI / 3) * arrowSize);
                QPointF arrowP2 = line.p1() + QPointF(sin(angle + M_PI - M_PI / 3) * arrowSize,
                                                cos(angle + M_PI - M_PI / 3) * arrowSize);
                QPolygonF arrowHead;
                arrowHead << line.p1() << arrowP1 << arrowP2;

                p->drawLine(line);
                p->drawPolygon(arrowHead);
            }
        }
    }


    delete [] t;
}
