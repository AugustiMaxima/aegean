#ifndef WEIGHT
#define WEIGHT

class matching;
//A conductor of double polymorphic matched dispatch

//The generic case for weights
//This is going to be a bit of a compromise
//There is no way to fully seamlessly extend the types of weights without (extremely) minor extesions to the base class signature
//they will be pure virtual so it isn't intolerably more work
class weight{
    public:
    weight();
    virtual int compare(weight&) = 0;
    virtual weight& add(weight&) = 0;
    virtual void match(matching&) = 0;
    virtual ~weight();
}

#endif
