#ifndef AEGEAN
#define AEGEAN

#include "collections/square.h"
#include "weight/weight.h"
#include "symbolic/atlas.h"
#include "symbolic/symbolic.h"
//Where it all comes together
//Under heavy construction


class Graph{
    int n;
    //denotes the list of vertice ids -> flattened since ids are linear
    square<weight> edges;
    //adjacency list with nullability
    //symbolic represnetation of vertice names
    atlas map;
    hector<symbol*> symbol_lookup;
    public:
    Graph();
    Graph(int, square<weight>&);
    Graph(int, square<weight>&&);
    void insert_vid(int);
    void insert_vid(int,int);
    //vid will incur the explicit and faster raw vertice id without symbol lookup
    template<class symb> void insert(symb&);
    template<class sym1, class sym2> void insert(sym1&, sym2&);
    //attempts at making a generalized generic type for symbolic lookup
    bool edge_exist_vid(int, int);
    template<class sym1, class sym2> bool edge_exist(sym1&, sym2&);
    weight& edge_weight_vid(int, int);
    template<class sym1, class sym2> weight& edge_weight(sym1&, sym2&);

    ~Graph();

    //I think I might make graph computation algorithms and other deemed not essential as separate functions. I will need to declare them friendly, likely
};

#endif