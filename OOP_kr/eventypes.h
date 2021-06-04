#ifndef EVENTYPES_H
#define EVENTYPES_H
#include "paramdata.h"
#include "statedata.h"

enum EEvents
{
    PARAMCHANGE = 1,
    PARAMREQUEST,
    PARAMRESET,
    STATEREQUEST,
    RESET,
    NEWPROBLEM,
};

struct TEvent
{
    EEvents type;

    struct
    {
        TParamdata p;
        TStatedata s;
        quint32 order_problem;
    } data;

    TEvent(EEvents t){type = t;};
};

#endif // EVENTYPES_H
