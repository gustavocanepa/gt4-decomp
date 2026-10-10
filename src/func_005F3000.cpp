typedef unsigned int size_t;
inline void *operator new(size_t, void *p) throw() { return p; }

struct Item {
    int w[4];
};

extern "C" Item *func_005F3000(const Item *first, const Item *last, Item *dest) {
    for (; first != last; ++first, ++dest) {
        new (dest) Item(*first);
    }
    return dest;
}
