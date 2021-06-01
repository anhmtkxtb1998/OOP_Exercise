#include "circle.h"

TCircle::TCircle(double r):TEllipse(r, r)
{
  className = "Окружность";
}
TCircle* TCircle::create(double r)
{
    if(r <= 0)
        return NULL;
    return(new TCircle(r));
}
