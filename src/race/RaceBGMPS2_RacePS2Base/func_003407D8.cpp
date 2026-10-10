/* compiler: ee-gcc2.96-no-strict-aliasing */
/* SGI STL sort(first, last, comp) inlined: __VALUE_TYPE takes first by reference (kept on the stack),
   __lg loop, then the out-of-line __introsort_loop and __final_insertion_sort. */
struct Elem {
    int a;
    int b;
};

struct Obj {
    Elem items[6];
    int count;
};

typedef bool (*Cmp)(const Elem &, const Elem &);

extern "C" bool func_005F4838(const Elem &x, const Elem &y);
extern "C" void func_005F3F28(Elem *first, Elem *last, Elem *, int depth_limit, Cmp comp);
extern "C" void func_005F40A0(Elem *first, Elem *last, Cmp comp);

template <class T> inline T *value_type(T *const &) { return (T *)0; }

template <class Size> inline Size lg(Size n) {
    Size k;
    for (k = 0; n != 1; n >>= 1)
        ++k;
    return k;
}

inline void sort(Elem *first, Elem *last, Cmp comp) {
    if (first != last) {
        func_005F3F28(first, last, value_type(first), lg(last - first) * 2, comp);
        func_005F40A0(first, last, comp);
    }
}

extern "C" void func_003407D8(Obj *o) {
    sort(o->items, o->items + o->count, func_005F4838);
}
