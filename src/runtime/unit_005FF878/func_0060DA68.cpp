/* compiler: ee-gcc2.96-stl */
/* SGI STL (include/stl/stl_tree.h) instantiated by tools/stl.py:
   _Rb_tree<Str2, pair<const Str2, Str2>, _Select1st, less<Str2>, GameAlloc>::insert_unique */
#include <stl_tree.h>

extern "C" void *func_00575E60(int heap, int size);
extern "C" void func_00575DA0(void *p, int size);


struct Rep {
    int len;
    int cap;
    int ref;
    int sel;
};

struct HeapName {
    const char *name;
};

extern "C" int func_00608D98(const void *self, const void *other, unsigned int pos, unsigned int n);
extern "C" char *strobe__toUpper(Rep *rep);
extern "C" void stl_unknown_release(void *p, int size);

/* the game's string: libstdc++ v2 basic_string (knowledge/runtime-types.md); the pointer is func_005AE2E8 and
   written as an int so the representation's counters can alias it */
struct Str2 {
    char *p;
    Str2(const Str2 &o) {
        int q = *(int *)&o.p;
        Rep *r = (Rep *)(q - 0x10);
        int d = q;
        if (r->sel != 0) {
            d = (int)strobe__toUpper(r);
        } else {
            r->ref = r->ref + 1;
        }
        *(int *)&p = d;
    }
    ~Str2() {
        Rep *r = (Rep *)(*(int *)&p - 0x10);
        if (--r->ref == 0) {
            int size = r->cap + 0x10;
            stl_unknown_release(r, size);
        }
    }
    bool operator<(const Str2 &o) const { return func_00608D98(this, &o, 0, (unsigned int)-1) < 0; }
};


/* gcc 2.96's type_info: the name first, the vtable pointer after it */
struct TypeInfo {
    const char *name;
};

/* typeid(T).name() of the types this source allocates, without typeid: the game's own __tf getter */
template <class T> struct TypeTag;

/* the game's allocator: every block is tagged with the name of its type */
template <class T>
class GameAlloc {
public:
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    typedef T *pointer;
    typedef const T *const_pointer;
    typedef T &reference;
    typedef const T &const_reference;
    typedef T value_type;
    template <class U> struct rebind { typedef GameAlloc<U> other; };
    GameAlloc() throw() {}
    GameAlloc(const GameAlloc &) throw() {}
    template <class U> GameAlloc(const GameAlloc<U> &) throw() {}
    ~GameAlloc() throw() {}
    T *allocate(size_type n, const void * = 0) {
        return (T *)func_00575E60(0x10, n * sizeof(T));
    }
    void deallocate(T *p, size_type n) {
        func_00575DA0(p, n * sizeof(T));
    }
    size_type max_size() const throw() { return size_t(-1) / sizeof(T); }
    void construct(T *p, const T &v) { new (p) T(v); }
    void destroy(T *p) { p->~T(); }
};

typedef Str2 Key;
typedef pair<const Str2, Str2> Value;
typedef _Rb_tree_node<Value> Node;


typedef _Rb_tree<Key, Value, _Select1st<Value>, less<Key>, GameAlloc<Value> > Tree;

template pair<Tree::iterator, bool> Tree::insert_unique(const Value &);
