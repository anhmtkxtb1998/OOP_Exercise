#ifndef TINTERFACE_H
#define TINTERFACE_H

#include <QWidget>
#include <QPushButton>
#include <QFileDialog>
#include <QFile>
#include <QSpinBox>
#include <QLabel>
#include <QMessageBox>
#include <QTextStream>
#include "canvas.h"
#include "stategraph.h"

class TInterface: public QWidget
{
    Q_OBJECT
    TCanvas * canvas;
    TStateGraph *g;
    QLabel * lb_matrix;
    QPushButton * btn_matrix;
    QLabel * lb_activeVertex;
    QSpinBox * sp_activeVertex;
    QPushButton * btn_show;

public:
    TInterface(QWidget * parent = nullptr);
    ~TInterface();
protected:
    void closeEvent(QCloseEvent *);
private slots:
    void OpenCanvas();
    void OpenFileStateMatrix();
    void ChangeActiveVertex(int);
    void SetActiveVertex(int);
public slots:
    void CloseCanvas();
signals:
    void ChangeGraph(TStateGraph);
};

#endif // TINTERFACE_H
