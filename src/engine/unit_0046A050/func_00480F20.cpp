/* compiler: ee-gcc2.96-stl */
/* vector<Val>::push_back (SGI STL stl_vector.h) inlined; _M_insert_aux stays out of line. */
#include <stl_algobase.h>
#include <stl_alloc.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
#include <stl_vector.h>

extern "C" void *func_00575E60(int heap, int size);
extern "C" void free(void *p);


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

/* the game's string: libstdc++ v2 basic_string (knowledge/runtime-types.md) */
struct Str2 {
    char *p;
    Rep *rep() const { return (Rep *)p - 1; }
    static char *grab(Rep *r) {
        if (r->sel)
            return strobe__toUpper(r);
        ++r->ref;
        return (char *)(r + 1);
    }
    Str2(const Str2 &o) : p(grab(o.rep())) {}
    ~Str2() {
        Rep *r = rep();
        if (--r->ref == 0)
            free(r);
    }
    bool operator<(const Str2 &o) const { return func_00608D98(this, &o, 0, (unsigned int)-1) < 0; }
};

extern "C" void func_00476768(void *self, const void *other);
extern "C" void stl_unknown_dtor(void *self, int in_charge);

extern "C" void func_004768C0(void *self);

/* the script value (named after its copy constructor, as in the map's other members) */
struct Val_00476768 {
    int type;
    int v;
    Val_00476768() : type(1) {}
    Val_00476768(const Val_00476768 &o) { func_00476768(this, &o); }
    ~Val_00476768() { func_004768C0(this); }
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
        free(p);
    }
    size_type max_size() const throw() { return size_t(-1) / sizeof(T); }
    void construct(T *p, const T &v) { new (p) T(v); }
    void destroy(T *p) { p->~T(); }
};

typedef Val_00476768 Val;
typedef vector<Val, GameAlloc<Val> > ValVector;

/* out of line at 0x006090E8 (config/stl_symbols.txt) */
template <> void ValVector::_M_insert_aux(Val *position, const Val &x);

extern "C" void func_00480F20(ValVector *v, const Val &x) {
    v->push_back(x);
}
