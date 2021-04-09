#ifndef CONTROLWINDOW_H
#define CONTROLWINDOW_H

#include <QMainWindow>
#include <QCloseEvent>
#include <QPushButton>
#include <QMessageBox>
#include "eventypes.h"

namespace Ui
{
    class TControlwindow;
}

class TControlwindow : public QMainWindow
{
    Q_OBJECT
static quint32 order;
public:
    explicit TControlwindow(QMainWindow *parent = nullptr);
    ~TControlwindow();
protected:
    void closeEvent(QCloseEvent*);
private slots:
    void ControlEvents();
signals:
    void closing();
    void sendControlEvent(TEvent);
private:
    Ui::TControlwindow *ui;
};

#endif // CONTROLWINDOW_H
