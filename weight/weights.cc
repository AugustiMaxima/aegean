#include "weights.h"
#include "matching.h"
#include "vessel.h"
#include "wessel.h"
#include <cmath>

float w_float::tolerance = 0.001;

int cmp_float(float base, float dl){
    if(dl<base*w_float::tolerance)
	    return 0;
    else if(signbit(dl))
	    return -1;
    else
	    return 1;
}

w_int::w_int(int i):w(i){}

int w_int::compare(weight& w){
    matching m;
    m.insert(*this);
    w.match(m);
    return m.comp();
}

int w_int::compare(w_int& wi){
    return w - wi.w;
}

int w_int::compare(w_float& wf){
    float dl = float(w) - wf.w;
    return cmp_float(float(w), dl);
}

int w_int::compare(vessel& v){
    return WESSEL::intcv[v.type](*this,v);
}

weight& w_int::add(weight& w){
    matching m;
    m.insert(*this);
    w.match(m);
    return m.add();
}

weight& w_int::add(w_int& wi){
    return w_int{wi.w+w};
}

weight& w_int::add(w_float& wf){
    return w_float{wf.w+(float)w};
}

weight& w_int::add(vessel& v){
    return WESSEL::intav[v.type](*this,v);
}

void w_int::match(matching& m){
    m.insert(*this);
}

w_int::~w_int(){}

w_float::w_float(float w):w(w){}

int w_float::compare(weight& w){
    matching m;
    m.insert(*this);
    w.match(m);
    return m.comp();
}

int w_float::compare(w_int& wi){
    float dl = w - float(wi.w);
    return cmp_float(w, dl);
}

int w_float::compare(w_float& wf){
    float dl = w - wf.w;
    return cmp_float(w, dl);
}

int w_float::compare(vessel& v){
    return WESSEL::floatcv(*this, v);
}

weight& w_float::add(weight& w){
    matching m;
    m.insert(*this);
    w.match(m);
    return m.add();
}

weight& w_float::add(w_int& wi){
    return w + float(wi.w);
}
weight& w_float::add(w_float& wf){
    return w + wf.w;
}
weight& w_float::add(vessel& v){
    return WESSEL.floatav(*this,v);
}

void w_float::match(matching& m){
    m.insert(*this);
}

w_float::~w_float(){}