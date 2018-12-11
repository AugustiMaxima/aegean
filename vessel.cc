#include "vessel.h"
#include "matching.h"
#include "wessel.h"

vessel::mx_add_base = square<std::function<vessel&(vessel&,vessel&)>>{};
vessel::mx_cmp_base = square<std::function<int(vessel&,vessel&)>>{};
vessel::mx_add = &vessel::mx_add_base;
vessel::mx_cmp = &vessel::mx_cmp_base;

square<std::function<vessel&(vessel&,vessel&)>>& vessel::getmx_add(bool base){
    if (base)
        return mx_add_base;
    return *mx_add;
}
square<<std::function<int<vessel&,vessel&>>& vessel::getmx_cmp(bool base){
    if (base)
        return mx_cmp_base;
    return *mx_cmp;
}

vessel::vessel(void* core,int type):core(core), type(type){}

vessel& vessel::add(vessel& operand){
    return getmx_add(*this, operand);
}
int vessel::compare(vessel& operand){
    return getmx_cmp(*this, operand);
}

weight& vessel::add(weight& operand){
    matching m;
    m.insert(*this);
    operand.match(m);
    return m.add();
}
int vessel::compare(weight& operand){
    matching m;
    m.insert(*this);
    operand.match(m);
    return m.comp();
}
void vessel::match(matching& m){
    m.insert(*this);
}

void vessel::setmx_add(square<std::function<vessel&(vessel&,vessel&)>>& mx){
    mx_add = &mx;
}

void vessel::setmx_cmp(square<std::function<int(vessel&,vessel&)>>& mx){
    mx_cmp = &mx;
}

void vessel::resetmx_add(){
    mx_add = &mx_add_base;
}
void vessel::resetmx_cmp(){
    mx_add = &mx_cmp_base;
}

//as these two functions are not concerned with the raw pointer, we are able to virtualize the getmx calls to skip the virtual implementation
void ins_mx_add(std::function<vessel&(vessel&,vessel&)& add, int i, int j, bool base=false){
    this->getmx_add(base)[i][j] = add;
}
void ins_mx_cmp(std::function<int(vessel&,vessel&)>& cmp, int, int, bool base=false){
    this->getmx_cmp(base)[i][j] = cmp;
}

vessel::~vessel(){
    delete core;
}

weight& vessel::add(w_int& wi){
    return WESSEL::vaint(*this, wi);
}
weight& add(w_float& wf){
    return WESSEL::vafloat(*this, wf);
}
int compare(w_int& wi){
    return WESSEL::vcint(*this, wi);
}
int compare(w_float&){
    return WESSEL::vcfloat(*this, wf)
}