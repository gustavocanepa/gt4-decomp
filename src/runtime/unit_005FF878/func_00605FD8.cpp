/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

inline void *operator new(unsigned int, void *p) throw() { return p; }

struct T12 {
    s32 a, b, c;
};

extern "C" T12 *func_00605FD8(T12 *first, T12 *last, T12 *result) {
    for (; first != last; ++first, ++result) {
        new (result) T12(*first);
    }
    return result;
}
