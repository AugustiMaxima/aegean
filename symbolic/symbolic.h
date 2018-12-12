#ifndef SYMBOLIC
#define SYMBOLIC

//base symbolic class
class symbol{
    void* core;
    public:
    symbol(void*);
    virtual int hash();
    virtual int cmp();
};

class primitive : symbol{
    int size;
    public:
    primitive(void*, int);
    virtual int hash() override;
    virtual int cmp() override;
};
//On the off chance someone actually wants to reuse this, I've kindly made the functions also virtual. Enjoy

#endif