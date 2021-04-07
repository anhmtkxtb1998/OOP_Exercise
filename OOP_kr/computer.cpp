#include "computer.h"

TComputer::TComputer()
{

}
TComputer::TComputer(TParamdata p, TStatedata s){
    param = p;
    state = s;
}
TComputer ::TComputer(const TComputer& c){
    param = c.param;
    state = c.state;
}
TComputer::~TComputer(){}

void TComputer::setparam(TParamdata p){
    param = p;
}
TParamdata TComputer::get_param(){
    return param;
}
void TComputer::setstate(TStatedata s){
    state = s;
}
TStatedata TComputer::get_state(){
    return state;
}
