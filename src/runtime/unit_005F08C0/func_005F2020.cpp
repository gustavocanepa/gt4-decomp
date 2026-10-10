/* compiler: ee-gcc2.96-stl */
/* SGI STL (include/stl/stl_tree.h) instantiated by tools/stl.py:
   _Rb_tree<Str, pair<const Str, Pod4_005F2690>, _Select1st, less<Str>, GameAlloc>::_M_erase */
#include <stl_tree.h>

extern "C" void *func_00326750(int size, int align, const char *name);

extern "C" void *func_005F2690(void);

struct Rep {
    int len;
    int cap;
    int ref;
    int sel;
};

struct HeapName {
    const char *name;
};

extern "C" int func_005C2A50(const void *self, const void *other, unsigned int pos, unsigned int n);
extern "C" char *func_005C2560(Rep *rep);
extern "C" HeapName *func_005C11A8(void);
extern "C" void func_00326798(void *p, int size, int align, const char *name);

/* the game's reference-counted string (knowledge/runtime-types.md): the pointer is func_005AE2E8 and
   written as an int so the representation's counters can alias it */
struct Str {
    char *p;
    Str(const Str &o) {
        int q = *(int *)&o.p;
        Rep *r = (Rep *)(q - 0x10);
        int d = q;
        if (r->sel != 0) {
            d = (int)func_005C2560(r);
        } else {
            r->ref = r->ref + 1;
        }
        *(int *)&p = d;
    }
    ~Str() {
        Rep *r = (Rep *)(*(int *)&p - 0x10);
        if (--r->ref == 0) {
            int size = r->cap + 0x10;
            func_00326798(r, size, 4, func_005C11A8()->name);
        }
    }
    bool operator<(const Str &o) const { return func_005C2A50(this, &o, 0, (unsigned int)-1) < 0; }
};

struct Pod4_005F2690 {
    int w[1];
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
        return (T *)func_00326750(n * sizeof(T), 4, ((TypeInfo *)TypeTag<T>::tf())->name);
    }
    void deallocate(T *p, size_type n) {
        func_00326798(p, n * sizeof(T), 4, ((TypeInfo *)TypeTag<T>::tf())->name);
    }
    size_type max_size() const throw() { return size_t(-1) / sizeof(T); }
    void construct(T *p, const T &v) { new (p) T(v); }
    void destroy(T *p) { p->~T(); }
};

typedef Str Key;
typedef pair<const Str, Pod4_005F2690> Value;
typedef _Rb_tree_node<Value> Node;
template <> struct TypeTag<Node> { static void *tf() { return func_005F2690(); } };

typedef _Rb_tree<Key, Value, _Select1st<Value>, less<Key>, GameAlloc<Value> > Tree;

template void Tree::_M_erase(Tree::_Link_type);
