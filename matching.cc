#include "matching.h"
#include "weight.h"
#include "weights.h"
#include "vessel.h"

w_union::operator void*(){
    return object;
}

static weight& iai(void* i,void* i2){
    return ((w_int*)i)->add(*(w_int*)i2);
}

static weight& iaf(void* i,void* f){
    return ((w_int*)i)->add(*(w_float*)f);
}

static weight& iav(void* i, void* v){
    return ((w_int*)i)->add(*(vessel*)v);
}

static weight& fai(void* f,void* i){
    return ((w_float*)f)->add(*(w_int*)i);
}

static weight& faf(void* f,void* f2){
    return ((w_float*)f)->add(*(w_float*)f2);
}

static weight& fav(void* f, void* v){
    return ((w_float*)f)->add(*(vessel*)v);
}

static weight& vai(void* v, void* i){
    return ((vessel*)v)->add(*(w_int*)i);
}

static weight& vaf(void* v, void* f){
    return ((vessel*)v)->add(*(w_float*)f);
}

static weight& vav(void* v, void* v2){
    return ((vessel*)v)->add(*(vessel*)v2);
}

static int ici(void* i, void* i2){
    return ((w_int*)i)->compare(*(w_int*)i2);
}

static int icf(void* i, void* f){
    return ((w_int*)i)->compare(*(w_float*)f);
}

static int icv(void* i, void* v){
    return ((w_int*)i)->compare(*(vessel*)v);
}

static int fci(void* f, void* i){
    return ((w_float*)f)->compare(*(w_int*)i);
}

static int fcf(void* f, void* f2){
    return ((w_float*)f)->compare(*(w_float*)f2);
}

static int fcv(void* f, void* v){
    return ((w_float*)f)->compare(*(vessel*)v);
}

static int vci(void* v, void* i){
    return ((vessel*)v)->compare(*(w_int*)i);
}

static int vcf(void* v, void* f){
    return ((vessel*)v)->compare(*(w_float*)f);
}

static int vcv(void* v, void* v2){
    return ((vessel*)v)->compare(*(vessel*)v2);
}

static weight& (*addspatch[3][3])(void*,void*) = {{&iai, &iaf, &iav}, {&fai, &faf, &fav}, {&vai, &vaf, &vav}};
static int (*compspatch[3][3])(void*,void*) = {{&ici, &icf, &icv}, {&fci, &fcf, &fcv}, {&vci, &vcf, &vcv}};

void matching::insert(w_int& w){
    if(l){
        r._class = 1;
        r.object = &w;
    }
    else{
        l._class = 1;
        l.object = &w;
    }
}

void matching::insert(w_float& w){
    if(l){
        r._class = 2;
        r.object = &w;
    }
    else{
        l._class = 2;
        l.object = &w;
    }
}

void matching::insert(vessel& v){
    if(l){
        r._class = 3;
        r.object = &v;
    }
    else{
        l._class = 3;
        l.object = &v;
    }
}

weight& matching::add(){
    return addspatch[l._class][r._class](l, r);
}

int matching::comp(){
    return compspatch[l._class][r._class](l, r);
}
