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
#include "derivegraph.h"

class TInterface: public QWidget
{
    Q_OBJECT
    TCanvas * canvas;
    TDerivesample *g;
    QLabel * lb_matrix;
    QPushButton * btn_matrix;
    QLabel * lb_activate;
    QSpinBox * sp_activate;
    QPushButton * btn_show;

public:
    TInterface(QWidget * parent = nullptr);
    ~TInterface();
protected:
    void closeEvent(QCloseEvent *);
private slots:
    void OpenCanvas();
//    void OpenFile();
    void OpenFileStateMatrix();
    void ChangeActiveEdge(int);
    void SetActivateEdge(int);
public slots:
    void CloseCanvas();
signals:
    void ChangeGraph(TDerivesample);
};

#endif // TINTERFACE_H
