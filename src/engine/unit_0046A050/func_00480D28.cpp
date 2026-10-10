/* compiler: ee-gcc2.96-stl */
/* SGI STL list<Item *>::const_iterator walk over a list with an allocator instance (node at +4); a virtual call per element */
#include <stl_algobase.h>
#include <stl_alloc.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
#include <stl_list.h>

template <class T>
class Alloc {
public:
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    typedef T *pointer;
    typedef const T *const_pointer;
    typedef T &reference;
    typedef const T &const_reference;
    typedef T value_type;
    template <class U> struct rebind { typedef Alloc<U> other; };
    Alloc() throw() {}
    Alloc(const Alloc &) throw() {}
    template <class U> Alloc(const Alloc<U> &) throw() {}
    ~Alloc() throw() {}
    T *allocate(size_type n, const void * = 0);
    void deallocate(T *p, size_type n);
    size_type max_size() const throw() { return size_t(-1) / sizeof(T); }
    void construct(T *p, const T &v) { new (p) T(v); }
    void destroy(T *p) { p->~T(); }
};

struct ItemData { char pad[0x5C]; };
struct Item : ItemData {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void update();
};

struct Owner {
    char pad[0xA4];
    list<Item *, Alloc<Item *> > items;
};

extern "C" void func_00480D28(Owner *o) {
    for (list<Item *, Alloc<Item *> >::const_iterator it = o->items.begin(); it != o->items.end(); ++it) {
        (*it)->update();
    }
}
