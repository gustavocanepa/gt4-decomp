/* compiler: ee-gcc2.96-stl */
/* SGI STL (include/stl/stl_vector.h) instantiated by tools/stl_vector.py: vector<int, GameAlloc> insert_fill */
#include <stl_algobase.h>
#include <stl_alloc.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
#include <stl_vector.h>

extern "C" void *func_00326750(int size, int align, const char *name);
extern "C" void func_00326798(void *p, int size, int align, const char *name);

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

extern "C" void func_003285A8(int);
extern "C" void func_003285F8(int);
struct Elem { int p;
 Elem() __asm__("func_0030BB18");
 Elem(int) __asm__("func_0030BA08");
 Elem(const Elem &);
 ~Elem() __asm__("func_00309378");
 Elem &operator=(const Elem &x) {
  if (this != &x) { int q=x.p; if(q) func_003285A8(q); if(p) func_003285F8(p); p=q; } return *this;
 }
};
extern "C" void *func_005C1100(void);
template <> struct TypeTag<Elem> { static void *tf() { return func_005C1100(); } };
typedef vector<Elem, GameAlloc<Elem> > Vec;
extern "C" void func_005D8510(Vec *, Elem *, unsigned, const Elem &);
template <> inline void Vec::insert(Elem *p, size_type n, const Elem &x) { func_005D8510(this,p,n,x); }
struct VT { short delta; short pad; void *fn; };
struct Src { char pad[4]; VT *vt; };
struct Self { char pad[0x10]; Vec v; };
extern char hArray__tf[], hObject__tf[];
extern "C" void *__dynamic_cast_2(void *, void *, int, void *, void *, void *);
extern "C" void hArray__deepCopy(Self *self, Src *src) {
 Self *r=0;
 if(src) { VT *vt=src->vt; r=(Self *)__dynamic_cast_2(vt->fn,hArray__tf,0,(char *)src+vt->delta,hObject__tf,src); }
 if(r) {
  unsigned n=r->v.size();
  self->v.resize(n);
  for(unsigned i=0;i<n;++i) self->v[i]=Elem(r->v[i].p);
 }
}
