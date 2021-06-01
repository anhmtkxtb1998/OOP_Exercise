#ifndef TCIRCLE_H
#define TCIRCLE_H
#include "ellipse.h"

class TCircle : public TEllipse
{
     TCircle(double);
public:
     static TCircle * create(double);
};

#endif // TCIRCLE_H
