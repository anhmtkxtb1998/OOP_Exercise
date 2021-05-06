#include "canvas.h"
#include <QPainter>
#include <math.h>
#include <QVector>

TCanvas::TCanvas(TGraph *f, QWidget *parent) : QWidget(parent)
{
    g = f;
    setFixedSize(400,400);
}

TCanvas::~TCanvas()
{

}

void TCanvas::paintEvent(QPaintEvent*)
{
    QPainter p;
    p.begin(this);

    int count = g->getCount();

    qreal cw = 0.5*rect().width();
    qreal ch = 0.5*rect().height();
    qreal cr = 0.9*(cw>ch?ch:cw);
    qreal a = 2.0*M_PI/count;

    qreal rad = 0.05*(cw>ch?ch:cw);
    qreal arrowSize = 0.8*rad;

    QRectF *t = new QRectF[count];
    for (int i=0; i<count; i++)
    {
        t[i] = QRectF(cw+cr*sin(i*a)-rad, ch-cr*cos(i*a)-rad, 2*rad, 2*rad);
    }

    QPen pen = QPen(Qt::black);
    pen.setStyle(Qt::SolidLine);
    p.setPen(pen);

    p.setBrush(QBrush(Qt::black));

    for (int i=0; i<count; i++)
    {
        for (int j=0; j<count; j++)
        {
            if (g->getMatrix().at(i, j) == 1)
            {
                if (i == j)
                {
                    QBrush old_brush = p.brush();
                    p.setBrush(QBrush(Qt::NoBrush));

                    QLineF line(t[i].center(), rect().center());
                    double angle = atan2(-line.dy(), line.dx());

                    QPointF p1 = line.p1() + QPoint(-rad*cos(angle), +rad*sin(angle));
                    qreal r0 = 0.75*rad;

                    p.drawEllipse(line.p1() + QPoint(-rad*cos(angle), +rad*sin(angle)), r0, r0);

                    qreal d = QLineF(t[i].center(), p1).length();
                    qreal l = (rad*rad - r0*r0 + d*d)/(2*d);
                    qreal h = sqrt(rad*rad - l*l);
                    QPointF p2 = t[i].center() + l*(p1-t[i].center())/d;

                    QPointF o = QPointF(p2.rx() + h*(p1.ry()-t[i].center().ry())/d, p2.ry() - h*(p1.rx()-t[i].center().rx())/d);

                    line.setP2(o);
                    angle = atan2(-line.dy(), line.dx()) - M_PI / 3;

                    QPointF arrowP1 = o + QPointF(sin(angle + M_PI / 3) * arrowSize, cos(angle + M_PI / 3) * arrowSize);
                    QPointF arrowP2 = o + QPointF(sin(angle + M_PI - M_PI / 3) * arrowSize, cos(angle + M_PI - M_PI / 3) * arrowSize);

                    QPolygonF arrowHead;
                    arrowHead << o << arrowP1 << arrowP2;

                    p.setBrush(old_brush);

                    p.drawPolygon(arrowHead);
                }
                else
                {
                    QLineF line(t[i].center(), t[j].center());
                    double angle = atan2(-line.dy(), line.dx());

                    line.setP1(line.p1() + QPoint(+rad*cos(angle), -rad*sin(angle)));
                    line.setP2(line.p2() - QPoint(+rad*cos(angle), -rad*sin(angle)));

                    QPointF arrowP1 = line.p1() + QPointF(sin(angle + M_PI / 3) * arrowSize, cos(angle + M_PI / 3) * arrowSize);
                    QPointF arrowP2 = line.p1() + QPointF(sin(angle + M_PI - M_PI / 3) * arrowSize, cos(angle + M_PI - M_PI / 3) * arrowSize);
                    QPolygonF arrowHead;
                    arrowHead << line.p1() << arrowP1 << arrowP2;

                    p.drawLine(line);
                    p.drawPolygon(arrowHead);
                }
            }
        }
    }

    p.setBrush(QBrush(Qt::white));

    QFont font;
    qreal cf = 0.5*rad;
    font.setPointSize(cf);
    font.setBold(true);
    p.setFont(font);

    for (int i=0; i<count; i++)
    {
        p.drawEllipse(t[i]);
        p.drawText(t[i], QString().setNum(i+1), QTextOption(Qt::AlignCenter));
    }

    delete [] t;

    p.end();
}

void TCanvas::closeEvent(QCloseEvent* event)
{
    emit closing();
    event->accept();
}

void TCanvas::ChangeGraph(TGraph * t)
{
    g = t;
    this->repaint();
}
