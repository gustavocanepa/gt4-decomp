/* compiler: ee-gcc2.96-stl */
#include <stl_algobase.h>
#include <stl_alloc.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
#include <stl_vector.h>

typedef int s32;

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
    T *allocate(size_type, const void * = 0);
    void deallocate(T *, size_type);
    size_type max_size() const throw() { return size_type(-1) / sizeof(T); }
    void construct(T *p, const T &v) { new (p) T(v); }
    void destroy(T *p) { p->~T(); }
};

/* Per-frame page bookkeeping of the render context: merges the pages queued
 * from other threads, rebuilds the list of live pages, notifies the root when
 * the top page changed, updates every live page, then moves focus and the
 * enter/leave events to the new top page. */

struct Context;
struct VEntry {
    short delta;
    short pad;
    void (*fn)(void *, Context *);
};
struct PageObj {
    s32 refCount;
    VEntry *vtbl;
};

typedef vector<PageObj *, GameAlloc<PageObj *> > PageList;

struct Root {
    char pad[0xE0];
    s32 mE0;
};

struct Event {
    char data[0x10];
};
struct LeaveEvent : Event {
    LeaveEvent(Context *ctx, void *w) __asm__("func_00295260");
    ~LeaveEvent() __asm__("func_00294F88");
};
struct EnterEvent : Event {
    EnterEvent(Context *ctx, void *w) __asm__("func_002946B8");
    ~EnterEvent() __asm__("func_002943E0");
};

struct Context {
    char pad0[0x10];
    Root *root;
    PageList pages;
    PageList active;
    PageList pending;
    s32 hasPending;
    char lock[0x694];
    s32 m6DC;
    s32 m6E0;
    s32 m6E4;
    s32 m6E8;
    char pad6EC[0x1654];
    s32 m1D40;
    s32 m1D44;
    s32 m1D48;
};

extern "C" int func_005767A8(void *lock);
extern "C" void func_005767C0(void *lock);
extern "C" PageObj *func_002319C0(Context *);
extern "C" int func_00233D28(PageObj *);
extern "C" void *mCrossingEvent__GetClassID(void);
extern "C" void *mWindowEvent__GetClassID(void);
extern "C" void func_00250B98(Root *, void *);
extern "C" void func_00251838(Root *, int);
extern "C" void func_002321F0(Context *);
extern "C" void *func_0022F000(Context *);
extern "C" void *func_00235C00(PageObj *);
extern "C" void func_00250CE0(Root *, const Event *);
extern "C" void func_0022F080(Context *, void *);
extern "C" void func_0022F178(Context *, void *);
extern "C" int func_0022F0F8(Context *);
extern "C" void func_0022F3A8(Context *, int);

template <>
void PageList::_M_insert_aux(PageObj **pos, PageObj *const &x) __asm__("func_005DAE00");
extern "C" void func_005DAF98(PageList *dst, const PageList *src);
static inline void assign(PageList &dst, const PageList &src) {
    if (&dst != &src) func_005DAF98(&dst, &src);
}

extern "C" void func_0022FBE0(Context *self) {
    if (func_005767A8(self->lock)) {
        if (self->hasPending) {
            self->hasPending = 0;
            for (PageList::iterator it = self->pending.begin(), end = self->pending.end(); it != end; ++it)
                self->pages.push_back(*it);
            self->pending.clear();
        }
        PageObj *before = func_002319C0(self);
        self->active.clear();
        for (PageList::iterator it = self->pages.begin(), end = self->pages.end(); it != end; ++it) {
            if (!func_00233D28(*it))
                self->active.push_back(*it);
        }
        assign(self->pages, self->active);
        if (func_002319C0(self) != before) {
            Root *root = self->root;
            func_00250B98(root, mCrossingEvent__GetClassID());
            func_00250B98(root, mWindowEvent__GetClassID());
            root->mE0 = 0;
            s32 flags = self->m6E8;
            if (flags & 1) func_00251838(root, 0);
            if (flags & 2) func_00251838(root, 1);
        }
        func_005767C0(self->lock);
    }
    if (self->m6E0 == 0) {
        for (PageList::iterator it = self->active.begin(), end = self->active.end(); it != end; ++it) {
            PageObj *p = *it;
            VEntry *e = &p->vtbl[92];
            e->fn((char *)p + e->delta, self);
        }
    }
    func_002321F0(self);
    PageObj *page = func_002319C0(self);
    if (page) {
        if (self->m6DC) {
            if (func_0022F000(self) != func_00235C00(page)) {
                if (func_0022F000(self)) {
                    Root *root = self->root;
                    func_00250CE0(root, &LeaveEvent(self, func_0022F000(self)));
                }
                func_0022F080(self, func_00235C00(page));
                if (func_0022F000(self)) {
                    Root *root = self->root;
                    func_00250CE0(root, &EnterEvent(self, func_0022F000(self)));
                    func_0022F178(self, func_0022F000(self));
                } else {
                    func_0022F178(self, 0);
                }
            }
        }
    } else {
        func_0022F080(self, 0);
        func_0022F178(self, 0);
    }
    if (self->m1D48 == 0 || self->m1D40 != 0)
        func_0022F3A8(self, func_0022F0F8(self));
}
