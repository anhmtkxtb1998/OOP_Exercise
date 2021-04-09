#ifndef PARAMWINDOW_H
#define PARAMWINDOW_H

#include <QMainWindow>
#include <QCloseEvent>
#include "eventypes.h"

QT_BEGIN_NAMESPACE
namespace Ui { class TParamwindow; }
QT_END_NAMESPACE

class TParamwindow : public QMainWindow
{
    Q_OBJECT

public:
   explicit TParamwindow(QMainWindow *parent = nullptr);
    ~TParamwindow();
    void setCurrentParamdata(TEvent);

protected:
   void closeEvent(QCloseEvent *);
private slots:
   void ControlEvents();
   void Getinformation(int);
signals:
   void closing();
   void sendParamEvent(TEvent);

private:
    Ui::TParamwindow *ui;
};
#endif // PARAMWINDOW_H
