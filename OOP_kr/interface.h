#ifndef INTERFACE_H
#define INTERFACE_H

#include <QMainWindow>
#include <QCloseEvent>
#include "paramwindow.h"
#include "controlwindow.h"
#include "statewindow.h"
#include "eventypes.h"

namespace Ui
{
    class TInterface;
}

class TInterface : public QMainWindow
{
    Q_OBJECT

public:
    explicit TInterface(QWidget *parent = nullptr);
    ~TInterface();
public slots:
    void recevieInterfaceEvent(TEvent);
protected:
    void closeEvent(QCloseEvent *);
private slots:
    void openParamwindow();
    void openStatewindow();
    void openControlwindow();
public slots:
    void closeParamwindow();
    void closeStatewindwow();
    void closeControlwindow();
signals:
    void sendInterfaceEvent(TEvent);
private:
    Ui::TInterface *ui;
    TParamwindow * paramwindow;
    TStatewindow * statewindow;
    TControlwindow * controlwindow;
};

#endif // INTERFACE_H
