/* compiler: ee-gcc2.96-stl */
/* SGI STL (include/stl/stl_vector.h) instantiated by tools/stl_vector.py: vector<E_0013BD50, GameAlloc> ufill_n_aux */
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

extern "C" void func_0013BD50(void *self, const void *other);

struct T_0013BD50 {
    int w;
    T_0013BD50() {}
    T_0013BD50(const T_0013BD50 &o) { func_0013BD50(this, &o); }
};
extern "C" void *func_005C1368(void);
template <> struct TypeTag<unsigned short> { static void *tf() { return func_005C1368(); } };
struct E_0013BD50 {
    T_0013BD50 a;
    struct V {
        vector<unsigned short, GameAlloc<unsigned short> > v;
    } v;
};
typedef E_0013BD50 Elem;
extern "C" void *stl_tf(void);
template <> struct TypeTag<Elem> { static void *tf() { return stl_tf(); } };
typedef vector<Elem, GameAlloc<Elem> > Vec;

template Elem *__uninitialized_fill_n_aux(Elem *, unsigned int, const Elem &, __false_type);
