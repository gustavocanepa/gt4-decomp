/* compiler: ee-gcc2.96-stl */
/* vector<Val>::clear() (SGI STL include/stl/stl_vector.h, erase(begin(), end()) inlined) on a list of script values. */
#include <stl_algobase.h>
#include <stl_alloc.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
#include <stl_vector.h>

typedef int s32;

struct Val;
extern "C" void func_004768C0(Val *);
extern "C" Val *func_00476768(Val *, const Val *);

struct Val {
    s32 type;
    s32 v;
    Val() : type(1) {}
    Val(const Val &o) { func_00476768(this, &o); }
    ~Val() { func_004768C0(this); }
};

extern "C" void *func_00575E60(int align, int size);
extern "C" void func_00575DA0(void *p);

template <class T>
class ValAlloc {
public:
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    typedef T *pointer;
    typedef const T *const_pointer;
    typedef T &reference;
    typedef const T &const_reference;
    typedef T value_type;
    template <class U> struct rebind { typedef ValAlloc<U> other; };
    ValAlloc() throw() {}
    ValAlloc(const ValAlloc &) throw() {}
    template <class U> ValAlloc(const ValAlloc<U> &) throw() {}
    ~ValAlloc() throw() {}
    T *allocate(size_type n, const void * = 0) { return (T *)func_00575E60(16, n * sizeof(T)); }
    void deallocate(T *p, size_type) { func_00575DA0(p); }
    size_type max_size() const throw() { return size_t(-1) / sizeof(T); }
    void construct(T *p, const T &v) { new (p) T(v); }
    void destroy(T *p) { p->~T(); }
};

struct List {

    vector<Val, ValAlloc<Val> > items;
};

extern "C" void func_00480EA0(List *l) {
    l->items.clear();
}
