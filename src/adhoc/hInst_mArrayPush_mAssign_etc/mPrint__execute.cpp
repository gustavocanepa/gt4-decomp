/* compiler: ee-gcc2.96-stl */
#include <stl_algobase.h>
#include <stl_alloc.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
#include <stl_vector.h>

typedef int s32;

/* mPrint::execute: pops `count` values into a vector, formats them into an
 * output object (which the retail build then drops), and pushes the count. */

extern "C" void *func_00326750(unsigned int size, int align, const char *name);
extern "C" void func_00326798(void *p, int size, int align, const char *name);

struct TypeInfo {
    const char *name;
};
extern "C" TypeInfo *HObject__tf(void);
extern "C" TypeInfo *func_005C11A8(void);

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

extern char D_0069E420[]; /* "nil" */
extern char D_0069E428[]; /* "" */
extern char D_0069E430[]; /* "%s" */

/* the game's string: libstdc++ v2 basic_string */
struct Rep {
    unsigned len, res, ref;
    bool selfish;
    char *data() { return (char *)(this + 1); }
    static void operator delete(void *p, unsigned n) { func_00326798(p, n, 4, func_005C11A8()->name); }
    void release() {
        if (--ref == 0) operator delete(this, sizeof(Rep) + res);
    }
};
struct String {
    char *dat;
    String(const String &);
    Rep *rep() const { return (Rep *)dat - 1; }
    unsigned length() const { return rep()->len; }
    void terminate() const { dat[length()] = 0; }
    const char *c_str() const {
        if (length() == 0) return D_0069E428;
        terminate();
        return dat;
    }
    ~String() { rep()->release(); }
};

struct Object;
extern "C" void func_003285A8(Object *p);
extern "C" void func_003285F8(Object *p);

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
    Value() __asm__("func_0030BB18");
    Value(const Value &);
    ~Value() __asm__("func_00309378");
    Object *get() const { return p; }
    Value &operator=(const Value &o) {
        if (this != &o) {
            Object *n = o.p;
            if (n) func_003285A8(n);
            if (p) func_003285F8(p);
            p = n;
        }
        return *this;
    }
};
struct Int : Value {
    Int(s32 v) __asm__("func_002FE278");
    ~Int() __asm__("func_002FC870");
};

extern "C" void *func_005D84B0(void *first, size_t n, const void *x, int);
template <> struct TypeTag<Value> { static TypeInfo *tf() { return HObject__tf(); } };
template <> inline Value *__uninitialized_fill_n_aux(Value *first, size_t n, const Value &x, __false_type) {
    return (Value *)func_005D84B0(first, n, &x, 0);
}
typedef vector<Value, GameAlloc<Value> > ValueList;

struct Out {
    s32 m0;
    s32 m4;
    String str;
    Out() __asm__("func_0030C2C8");
    void printf(const char *fmt, ...) __asm__("func_0030C378");
};

struct Stack {
    char pad[0x10];
    ValueList items;
    s32 count;
    Value &pop() { return items[--count]; }
    void push(const Value &v) { items[count] = v; ++count; }
};
struct Thread {
    char pad[0x2C];
    Stack *stack;
    void push(const Value &v) { stack->push(v); }
};
struct mPrint {
    s32 refCount;
    void *vtbl;
    s32 count;
};

extern "C" void mPrint__execute(mPrint *self, Thread *thread) {
    if (self->count > 0) {
        Out out;
        ValueList args(self->count);
        for (int i = self->count - 1; i >= 0; --i)
            args[i] = thread->stack->pop();
        for (int i = 0; i < self->count; i++) {
            Object *o = args[i].get();
            if (o == 0)
                out.printf(D_0069E420);
            else
                out.printf(D_0069E430, o->toString().c_str());
        }
    }
    thread->push(Int(self->count));
}
