#ifndef VESSEL
#define VESSEL

#include <functional>
#include "weight.h"

class vessel:weight{
    static sqaure<std::function<vessel&(vessel&,vessel&)>> mx_add;
    static square<std::function<int(vessel&,vessel&)>> mx_cmp;
    void* core;
    int type;
    public:
    vessel(void*,int);
    vessel& add(vessel&);
    int compare(vessel&);
    weight& add(weight&) override;
    int compare(weight&) override;
    weight& add(w_int&);
    weight& add(w_float&);
    int compare(w_int&);
    int compare(w_float&);
    ~vessel();
}

#endif
