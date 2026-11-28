/* compiler: ee-gcc2.96-stl */
#include <stl_algobase.h>
#include <stl_alloc.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
#include <stl_vector.h>

typedef int s32;

/* hArray::toString(): header with the element count, then the elements'
 * own strings separated by commas, cut short once the text passes 128
 * characters. */

extern "C" void *func_00326750(unsigned int size, int align, const char *name);
extern "C" void func_00326798(void *p, int size, int align, const char *name);

struct TypeInfo {
    const char *name;
};
extern "C" TypeInfo *func_005C11A8(void);
extern "C" TypeInfo *HObject__tf(void);

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
        return (T *)func_00326750(n * sizeof(T), 4, TypeTag<T>::tf()->name);
    }
    void deallocate(T *p, size_type n) {
        func_00326798(p, n * sizeof(T), 4, TypeTag<T>::tf()->name);
    }
    size_type max_size() const throw() { return size_t(-1) / sizeof(T); }
    void construct(T *p, const T &v) { new (p) T(v); }
    void destroy(T *p) { p->~T(); }
};

/* the game's string: libstdc++ v2 basic_string */
struct Rep {
    unsigned len, res, ref;
    bool selfish;
    char *data() { return (char *)(this + 1); }
    inline char *grab();
    static void operator delete(void *p, unsigned n) { func_00326798(p, n, 4, func_005C11A8()->name); }
    void release() {
        if (--ref == 0) operator delete(this, sizeof(Rep) + res);
    }
};
extern "C" char *func_005C2560(Rep *r);
inline char *Rep::grab() {
    if (selfish) return func_005C2560(this);
    ++ref;
    return data();
}
struct String {
    char *dat;
    Rep *rep() const { return (Rep *)dat - 1; }
    String(const String &str) : dat(str.rep()->grab()) {}
    ~String() { rep()->release(); }
    unsigned length() const { return rep()->len; }
};

struct StringStream {
    String text;
    s32 pad[3];
    StringStream() __asm__("func_0032B5C0");
    StringStream &operator<<(const char *s) __asm__("func_0032B808");
    StringStream &operator<<(int n) __asm__("func_0032B6D8");
    StringStream &operator<<(const String &s) __asm__("func_0032B658");
    String &str() __asm__("func_0032B8C0");
};

struct VEntry {
    short delta;
    short index;
    String (*toString)(void *);
};
struct Object {
    s32 refCount;
    VEntry *vtbl;
    String toString() {
        VEntry *e = &vtbl[3];
        return e->toString((char *)this + e->delta);
    }
};
struct Value {
    Object *p;
    Value(const Value &);
    ~Value();
    bool isNull() const { return p == 0; }
    Object *operator->() const { return p; }
};
template <> struct TypeTag<Value> { static TypeInfo *tf() { return HObject__tf(); } };
typedef vector<Value, GameAlloc<Value> > ValueList;

struct hArray {
    char pad[0x10];
    ValueList items;
};

extern char D_0069D480[], D_0069D490[], D_0069D498[], D_0069D4A0[], D_0069D4A8[];
extern char D_0069D4B0[], D_0069D4B8[], D_0069D4C0[], D_0069D4C8[];

extern "C" String hArray__toString(hArray *self) {
    StringStream ss;
    ss << D_0069D480;
    ss << D_0069D490 << (int)self->items.size() << D_0069D498;
    ss << D_0069D4A0;
    /* isNull() has to be the bool accessor: its compare-to-value insn makes the loop 62 insns
       long in the first loop pass, so the second string's high part is hoisted only by the
       second pass, after the temporary's address (the original's preheader order). */
    for (ValueList::iterator it = self->items.begin(); it != self->items.end(); ++it) {
        if (it != self->items.begin()) ss << D_0069D4A8;
        if (it->isNull())
            ss << D_0069D4B0;
        else
            ss << (*it)->toString();
        if (ss.str().length() > 0x80) {
            ss << D_0069D4B8;
            break;
        }
    }
    ss << D_0069D4C0;
    ss << D_0069D4C8;
    return ss.str();
}
