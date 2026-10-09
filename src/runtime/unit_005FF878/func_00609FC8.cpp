/* compiler: ee-gcc2.96-stl */
/* SGI STL (include/stl/stl_vector.h) instantiated by tools/stl_vector.py: vector<unsigned int, PlainAlloc10> insert_fill */
#include <stl_algobase.h>
#include <stl_alloc.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
#include <stl_vector.h>

extern "C" void *func_00326750(int size, int align, const char *name);
extern "C" void func_00326798(void *p, int size, int align, const char *name);
extern "C" void *func_00575E60(int heap, int size);
extern "C" void func_00575DA0(void *p);

/* gcc 2.96's type_info: the name first, the vtable pointer after it */
struct TypeInfo {
    const char *name;
};

/* typeid(T).name() without typeid: the game's own __tf getter */
template <class T> struct TypeTag;

template <class T>
class PlainAlloc10 {
public:
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    typedef T *pointer;
    typedef const T *const_pointer;
    typedef T &reference;
    typedef const T &const_reference;
    typedef T value_type;
    template <class U> struct rebind { typedef PlainAlloc10<U> other; };
    PlainAlloc10() throw() {}
    PlainAlloc10(const PlainAlloc10 &) throw() {}
    template <class U> PlainAlloc10(const PlainAlloc10<U> &) throw() {}
    ~PlainAlloc10() throw() {}
    T *allocate(size_type n, const void * = 0) {
        return n == 0 ? 0 : (T *)func_00575E60(0x10, n * sizeof(T));
    }
    void deallocate(T *p, size_type n) {
        func_00575DA0(p);
    }
    size_type max_size() const throw() { return size_t(-1) / sizeof(T); }
    void construct(T *p, const T &v) { new (p) T(v); }
    void destroy(T *p) { p->~T(); }
};

typedef unsigned int Elem;

typedef vector<Elem, PlainAlloc10<Elem> > Vec;

template void Vec::insert(Vec::iterator, Vec::size_type, const Elem &);
