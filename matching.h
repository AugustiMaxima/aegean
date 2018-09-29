#ifndef MATCHER
#define MATCHER

class weight;
class w_int;
class w_float;

struct w_union{
    int _class;
    void* object = NULL;
}

class matching{
    w_union l;
    w_union r;
    public:
    void insert(w_int&);
    void insert(w_float&);
    void insert(vessel&);
    weight& add();
    int comp();
}

#endif
