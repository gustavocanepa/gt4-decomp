/* compiler: ee-gcc2.96-stl */
/* SGI STL (include/stl/stl_list.h) list<pair<Str2, Str2>, PlainAlloc10>::clear (_List_base) */
#include <stl_algobase.h>
#include <stl_alloc.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
#include <stl_pair.h>
#include <stl_list.h>

extern "C" void *func_00326750(int size, int align, const char *name);
extern "C" void func_00326798(void *p, int size, int align, const char *name);
extern "C" void *func_00575E60(int heap, int size);
extern "C" void free(void *p);

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
        free(p);
    }
    size_type max_size() const throw() { return size_t(-1) / sizeof(T); }
    void construct(T *p, const T &v) { new (p) T(v); }
    void destroy(T *p) { p->~T(); }
};

struct Rep {
    int len;
    int cap;
    int ref;
    int sel;
};

extern "C" char *strobe__toUpper(Rep *rep);

/* the game's string with the second allocator (knowledge/gt4.md, SGI STL section) */
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
            free(r);
        }
    }
};

typedef pair<Str2, Str2> Elem;
typedef _List_base<Elem, PlainAlloc10<Elem> > Base;

template void Base::clear();
