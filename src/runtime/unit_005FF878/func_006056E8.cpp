/* compiler: ee-gcc2.96-stl */
#include <stl_algobase.h>

/* SGI STL __lower_bound(first, last, val, comp, Distance *) (stl_algo.h) instantiated for a
   4-byte element with a short key; distance()/advance() from the real headers keep len and
   middle in memory. */

struct Elem {
    short key;
    short val;
};
struct Comp {
    char c;
    bool operator()(const Elem &e, const int &v) const { return e.key < v; }
};

extern "C" Elem *func_006056E8(Elem *__first, Elem *__last, const int &__val, Comp __comp, int *)
{
    int __len = 0;
    distance(__first, __last, __len);
    int __half;
    Elem *__middle;

    while (__len > 0) {
        __half = __len >> 1;
        __middle = __first;
        advance(__middle, __half);
        if (__comp(*__middle, __val)) {
            __first = __middle;
            ++__first;
            __len = __len - __half - 1;
        } else
            __len = __half;
    }
    return __first;
}
