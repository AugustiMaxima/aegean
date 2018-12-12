#ifndef ATLAS
#define ATLAS

#include "../collections/hector/hector.h"

class symbol;

struct hash_chain{
    symbol* key;
    int value;
    hash_chain* next;
};

//A cartographer of sort. registers a link between an unique id and the symbol used to represent it
//We will use chainning because this makes rehashing much more managable with customizable hashing algorithms
class atlas{
    int size;
    int n;
    int exp;
    hector<hash_chain*> table;
    int index(int);
    //valid exp make atlas use a more performant implementation of the indexing algorithm, but can only output in domains of 0->2^exp-1.
    //This can lead to low utilization rate of the table if size is not configured optimally. We recommend increments of 2s
    void rehash(int, int);
    public:
    atlas(int=64, bool=true);
    int retrieval(symbol&);
    void insertion(symbol&, int);
    hash_chain& operator[](symbol&);
};

/*additional note:
    Atlas is the backend of the hash table engine, but it isn't the complete package. It requires that the type itself has competent assertion capabilities
    The stock hash&equality check will work for primitive types, but we cannot reason about pointers and its contents without explicitly knowing about the function type
    As such, unique hasing and equality for complex types with pointers should be handled with care
*/
#endif