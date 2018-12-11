#ifndef WEIGHTS
#define WEIGHTS

#include "weight.h"

struct  w_int: public weight{
    int w;
    w_int(int);
    int compare(weight&) override;
    int compare(w_int&);
    int compare(w_float&);
    int compare(vessel&);
    weight& add(weight&) override;
    weight& add(w_int&);
    weight& add(w_float&);
    weight& add(vessel&);
    void match(matching&) override;
    ~w_int();
}

struct w_float: public weight{
    static float tolerance;
    float w;
    w_float(float);
    int compare(weight&) override;
    int compare(w_int&);
    int compare(w_float&);
    int compare(vessel&);
    weight& add(weight&) override;
    weight& add(w_int&);
    weight& add(w_float&);
    weight& add(vessel&);
    void match(matching&) override;
    ~w_float();
}

#endif
