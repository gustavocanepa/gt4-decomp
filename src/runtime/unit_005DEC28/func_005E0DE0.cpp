/* compiler: ee-gcc2.96-no-strict-aliasing */
/* SGI STL uninitialized_copy (__uninitialized_copy_aux, non-POD) of a 44-byte element whose two
   vectors have user copy constructors; placement new keeps its null check (throw()). */
typedef unsigned int size_t;
inline void *operator new(size_t, void *p) throw() { return p; }

struct Vec4 {
    float x, y, z, w;
    Vec4(const Vec4 &o) : x(o.x), y(o.y), z(o.z), w(o.w) {}
};

struct Item {
    int a;
    int b;
    Vec4 p;
    Vec4 q;
    int c;
};

template <class T1, class T2> inline void construct(T1 *p, const T2 &value) { new (p) T1(value); }

extern "C" Item *func_005E0DE0(Item *first, Item *last, Item *result) {
    Item *cur = result;
    for (; first != last; ++first, ++cur)
        construct(&*cur, *first);
    return cur;
}
