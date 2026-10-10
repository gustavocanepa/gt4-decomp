/* SGI STL uninitialized_fill_n (stl_uninitialized.h) for a 16-byte, byte-aligned element: placement new (null-checked) copies x into n slots. */
struct T16 { char b[16]; };

inline void *operator new(unsigned int, void *p) throw() { return p; }

extern "C" T16 *func_005F3050(T16 *first, unsigned int n, const T16 &x) {
    T16 *cur = first;
    for (; n > 0; --n, ++cur)
        new (cur) T16(x);
    return cur;
}
