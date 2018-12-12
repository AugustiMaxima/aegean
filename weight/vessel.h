#ifndef VESSEL
#define VESSEL

#include <functional>
#include "weight.h"
#include "../collections/square.h"

//The basic implementation of dynamic weight objects
//No need to define a new data type, just implement the cross addition and comparison rules
//To hot swap the add/cmp matrix, just reassign the mx_add and mx_cmp squares
//To have two distinct classes of cross addition and cross comparison matrix so that similar types may engage in different rules, implement a 
class vessel : public weight{
    //To allow for hot swap, we will use a pointer for the actual operations
    //But we will also retain a base set of interaction matrix so we can reset to base behavior
    static square<std::function<vessel&(vessel&,vessel&)>>* mx_add;
    static square<std::function<int(vessel&,vessel&)>>* mx_cmp;
    void* core;
    int type;
    virtual square<std::function<vessel&(vessel&,vessel&)>>& getmx_add(bool=false);
    virtual square<std::function<int(vessel&,vessel&)>>& getmx_cmp(bool=false);
    protected:
    static square<std::function<vessel&(vessel&,vessel&)>> mx_add_base;
    static square<std::function<int(vessel&,vessel&)>> mx_cmp_base;
    public:
    vessel(void*,int);
    vessel& add(vessel&);
    int compare(vessel&);
    weight& add(weight&) override;
    int compare(weight&) override;
    void match(matching&) override;
    virtual void setmx_add(square<std::function<vessel&(vessel&,vessel&)>>&);
    virtual void setmx_cmp(square<std::function<int(vessel&,vessel&)>>&);
    virtual void resetmx_add();
    virtual void resetmx_cmp();
    void ins_mx_add(std::function<vessel&(vessel&,vessel&)>&,int,int,bool=false);
    void ins_mx_cmp(std::function<int(vessel&,vessel&)>&,int,int,bool=false);
    ~vessel();
    virtual weight& add(w_int&);
    virtual weight& add(w_float&);
    virtual int compare(w_int&);
    virtual int compare(w_float&);
}

#endif
