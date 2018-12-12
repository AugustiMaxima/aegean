#ifndef VESSEL_WEIGHT_ADAPTER
#define VESSEL_WEIGHT_ADAPTER

#include <functional>
#include "vessel.h"
#include "../collections/hector.h"


//essentially a static container for implementing new methods
//each subclass of vessel will need a corresponding class of this type if interface with static types are needed
class WESSEL{
    static hector<std::function<weight&(w_int&,vessel&)>> intav;
    static hector<std::function<weight&(w_float&,vessel&)>> floatav;
    static hector<std::function<int(w_int&,vessel&)>> intcv;
    static hector<std::function<int(w_float&,vessel&)>> floatcv;
    static hector<std::function<weight&(vessel&,w_int&)>> vaint;
    static hector<std::function<weight&(vessel&,w_float&)>> vafloat;
    static hector<std::function<int(vessel&,w_int&)>> vcint;
    static hector<std::function<int(vessel&,w_float&)>> vcfloat;
    friend class vessel;
};

#endif
