#include "matching.h"
#include "weight.h"

static weight& iai(void* i,void* i2){
    return (w_int*)i->add(*(w_int*)i2);
}

static weight& iaf(void* i,void* f){
    return (w_int*)i->add(*(w_float*)f);
}

static weight& iav(void* i, void* v){
    return (w_int*)i->add(*(vessel*)v);
}

static weight& fai(void* f,void* i){
    return (w_float*)f->add(*(w_int*)i);
}

static weight& faf(void* f,void* f2){
    return (w_float*)f->add(*(w_float*)f2);
}

static weight fav(void* f, void* v){
    return (w_float*)f->add(*(vessel*)v);
}

static weight& vai(void* v, void* i){
    return (vessel*)v->add(*(w_int*)i);
}

static weight& vaf(void* v, void* f){
    return (vessel*)v->add(*(w_float*)f);
}

static weight& vav(void* v, void* v2){
    return (vessel*)v->add(*(vessel*)v2);
}

static int ici(void* i, void* i2){
    return (w_int*)i->compare(*(w_int*)i2);
}

static int icf(void* i, void* f){
    return (w_int*)i->compare(*(w_float*)f);
}

static int icv(void* i, void* v){
    return (w_int*)i->compare(*(vessel*)v);
}

static int fci(void* f, void* i){
    return (w_float*)f->compare(*(w_int*)i);
}

static int fcf(void* f, void* f2){
    return (w_float*)f->compare(*(w_float*)f2);
}

static int fcv(void* f, void* v){
    return (w_float*)f->compare(*(vessel*)v);
}

static int vci(void* v, void* i){
    return (vessel*)v->compare(*(w_int*)i);
}

static int vcf(void* v, void* f){
    return (vessel*)v->compare(*(w_float*)f);
}

static int vcv(void* v, void* v2){
    return (vessel*)v->compare(*(vessel*)v2);
}

const static weight& (addspatch[2][2])(void*,void*) = {{iai,iaf},{fai,faf}};
const static int (compspatch[2][2])(void*,void*) = {{ici,icf},{fci,fcf}};

void matching::insert(w_int& w){
    if(l.object){
	r._class = 1;
	r.object = &w;
    }
    else{
	l._class = 1;
	l.object = &w;
    }
}

void matching::insert(w_float& w){
    if(l.object){
	r._class = 2;
	r.object = &w;
    }
    else{
	l._class = 2;
	l.object = &w;
    }
}

void matching::insert(vessel& v){
    if(l.object){
	r._class = 3;
	r.object = &v;
    }
    else{
	l._class = 3;
	l.object = &v;
    }
}

weight& matching::add(){
    return addspatch[l._class][r._class]();
}

int matching::comp(){
    return compspatch[l._class][r._class]();
}
