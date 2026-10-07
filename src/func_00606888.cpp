typedef int s32;

struct Elem {
    const char *key;
    s32 val;
};

extern "C" s32 func_0057F238(const char *a, const char *b);

static inline void distance(Elem *first, Elem *last, s32 *n) {
    *n += last - first;
}

static inline void advance(Elem **it, s32 n) {
    *it += n;
}

static inline bool less(const Elem *a, const Elem *b) {
    return func_0057F238(a->key, b->key) < 0;
}

extern "C" Elem *func_00606888(Elem *first, Elem *last, Elem *val) {
    s32 len = 0;
    s32 half;
    Elem *middle = first;

    distance(first, last, &len);
    while (len > 0) {
        half = len >> 1;
        middle = first;
        advance(&middle, half);
        if (less(middle, val)) {
            first = middle;
            ++first;
            len = len - half - 1;
        } else {
            len = half;
        }
    }
    return first;
}
