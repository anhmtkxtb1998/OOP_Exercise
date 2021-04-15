#ifndef TCOMPUTER_H
#define TCOMPUTER_H

#include <QObject>
#include "eventypes.h"

class TComputer: public QObject
{

    TParamdata param;
    TStatedata state;
public:
    TComputer();
    TComputer(TParamdata, TStatedata);
    TComputer(const TComputer&);
    ~TComputer();
    void setparam(TParamdata);
    TParamdata get_param();
    void setstate(TStatedata);
    TStatedata get_state();
};

#endif // TCOMPUTER_H
