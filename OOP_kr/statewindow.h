#ifndef STATEWINDOW_H
#define STATEWINDOW_H

#include <QMainWindow>
#include <QCloseEvent>
#include "eventypes.h"

namespace Ui
{
    class TStatewindow;
}

class TStatewindow : public QMainWindow
{
    Q_OBJECT
    QTimer * p_timer;

public:
    explicit TStatewindow(QMainWindow *parent = nullptr);
    ~TStatewindow();
    void setCurrentState(TEvent);

protected:
    void closeEvent(QCloseEvent *);

private slots:
    void GetStateByOrder(int);
    void ChangedState();

private:
    Ui::TStatewindow *ui;

signals:
    void closing();
    void sendStateEvents(TEvent);
};

#endif // STATEWINDOW_H
