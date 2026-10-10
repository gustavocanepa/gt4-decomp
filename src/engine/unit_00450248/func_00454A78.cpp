/* compiler: ee-gcc2.96-no-strict-aliasing */
/* A find_if over (value, id) pairs: SGI STL's inline find_if(first, last, pred) passes
   __ITERATOR_CATEGORY(first) (first taken by reference, hence its stack slot) to the
   random-access instantiation func_00604698. */
struct Entry {
    int value;
    int id;
};

struct IdEquals {
    int id;
    IdEquals(int i) : id(i) {}
};

struct random_access_iterator_tag {};

extern "C" Entry *func_00604698(Entry *first, Entry *last, IdEquals pred, random_access_iterator_tag);

static inline random_access_iterator_tag iterator_category(Entry *const &) {
    return random_access_iterator_tag();
}

static inline Entry *find_if(Entry *first, Entry *last, IdEquals pred) {
    return func_00604698(first, last, pred, iterator_category(first));
}

struct Obj {
    char pad[0x2A];
    unsigned short count;
    char pad2C[0x2C];
    Entry *entries;
};

extern "C" int func_00454A78(Obj *o, int id) {
    Entry *first = o->entries;
    if (first == 0)
        return 0;
    Entry *last = first + o->count;
    Entry *it = find_if(first, last, IdEquals(id));
    int value = 0;
    if (it != last)
        value = it->value;
    return value;
}
