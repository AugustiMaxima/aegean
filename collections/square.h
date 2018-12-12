#ifndef SQUARE_H
#define SQUARE_H

#include "hector/hector.h"

//Dynamic square, with more segmented allocs and hopefully a good compromise in speed and space

template<class C>
class unum{
    bool& valid;
    C& value;
    public:
    unum(bool&,C&);
};

template<class C>
class row{
    int n;
    hector<C> rc;
    hector<bool> ind;
    public:
    row(int=4);
    unum<C>& operator[](int);
    void resize(int,bool = true);
};

template<class C>
class square{
    int n;
    hector<bool> ind;
    hector<row<C>> sqs;
    public:
    square(int=1);
    row<C>& operator[](int);
    void resize(int,bool = true);
};

template<class C>
row<C>::row(int n): n{n}, rc{hector<C>{n}}, ind{hector<bool>{n,true}}{}
//quasi-constant initialization, important for maintaining quasi constant insertion rate


//delay initialization as much as possible
//a nice analogy to my approach to my personal duties
template<class C>
unum<C>& row<C>::operator[](int i){
    if(i>=n){
	    resize(i+1,true);
    }
    return unum<C>{ind[i],rc[i]};
}

// useful operation to run in the down time
// properly initialize by advertised size, rather than delayed initialization
template<class C>
void row<C>::resize(int nt,bool move){
    if(nt>n){
	    n = nt;
	    ind.resize(nt,move);
	    rc.resize(nt,move);
    }
}


template<class C>
square<C>::square(int n): n{n}, sqs{hector<row<C>>{n}}, ind{hector<bool>{n,true}}{}

template<class C>
row<C>& square<C>::operator[](int i){
    if(i>=n){
	    resize(i+1,true);
    }
    if(!ind[i]){
	    sqs[i] = row<C>{n};
	    ind[i] = true;
    }
    return sqs[i];
}

//resize upwards, not down
template<class C>
void square<C>::resize(int nt, bool move){
    if(nt>n){
	    n = nt;
	    sqs.resize(nt,move);
	    ind.resize(nt,move);
    }
}

#endif
