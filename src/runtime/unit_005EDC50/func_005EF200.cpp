/* compiler: ee-gcc2.96-stl */
/* SGI STL (include/stl/stl_tree.h) instantiated by tools/stl.py:
   _Rb_tree<HSymID, pair<const HSymID, Val_00323B48>, _Select1st, less<HSymID>, GameAlloc>::erase(first, last) */
#include <stl_tree.h>

extern "C" void *func_00326750(int size, int align, const char *name);
extern "C" void func_00326798(void *p, int size, int align, const char *name);
extern "C" void *func_005EFEA0(void);

struct HSymID {
    int w[1];
    bool operator<(const HSymID &o) const { return w[0] < o.w[0]; }
};

extern "C" void func_00323B48(void *self, const void *other);
extern "C" void func_00323B60(void *self, int in_charge);

struct Val_00323B48 {
    int w[1];
    Val_00323B48(const Val_00323B48 &o) { func_00323B48(this, &o); }
    ~Val_00323B48() { func_00323B60(this, 2); }
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

typedef HSymID Key;
typedef pair<const HSymID, Val_00323B48> Value;
typedef _Rb_tree_node<Value> Node;
template <> struct TypeTag<Node> { static void *tf() { return func_005EFEA0(); } };

typedef _Rb_tree<Key, Value, _Select1st<Value>, less<Key>, GameAlloc<Value> > Tree;

template void Tree::erase(Tree::iterator, Tree::iterator);
