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

private:
    Ui::TInterface *ui;
    TParamwindow * paramwindow;
    TStatewindow * statewindow;
    TControlwindow * controlwindow;

public:
    explicit TInterface(QMainWindow *parent = nullptr);
    ~TInterface();

public slots:
    void recevieInterfaceEvent(TEvent);
    void closeParamwindow();
    void closeStatewindwow();
    void closeControlwindow();

protected:
    void closeEvent(QCloseEvent *);

private slots:
    void openParamwindow();
    void openStatewindow();
    void openControlwindow();

signals:
    void sendInterfaceEvent(TEvent);
};

#endif // INTERFACE_H
