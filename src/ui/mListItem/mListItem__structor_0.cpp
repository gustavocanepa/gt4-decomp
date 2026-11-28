/* compiler: ee-gcc2.96-stl */
#include <stl_algobase.h>
#include <stl_alloc.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
#include <stl_vector.h>

typedef int s32;
typedef float f32;
typedef unsigned short u16;

/* mListBox: resizes the item list. The box keeps two item vectors and an
 * index of the live one; the new list is built in the spare vector, the index
 * is flipped under the render lock, and the widgets of the dropped items are
 * detached afterwards. */

extern "C" void *func_00326750(unsigned int size, int align, const char *name);
extern "C" void func_00326798(void *p, int size, int align, const char *name);
struct TypeInfo {
    const char *name;
};
extern "C" TypeInfo *MListItem__tf() throw();

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
        return (T *)func_00326750(n * sizeof(T), 4, MListItem__tf()->name);
    }
    void deallocate(T *p, size_type n) {
        func_00326798(p, n * sizeof(T), 4, MListItem__tf()->name);
    }
    size_type max_size() const throw() { return size_type(-1) / sizeof(T); }
    void construct(T *p, const T &v) { new (p) T(v); }
    void destroy(T *p) { p->~T(); }
};

extern char mListItem__vtable[];
extern char D_0069BDF8[]; /* "RefCounter" */

struct Widget;

struct RefCounter {
    s32 refCount;
    void *vtable;
    RefCounter() __asm__("func_00328420");
    static void *operator new(size_t n) { return func_00326750(n, 4, D_0069BDF8); }
};

struct mListItem : RefCounter {
    Widget *widget;
    f32 x, y, w, h;
    u16 id;
    unsigned active : 1;
    unsigned selected : 1;
    unsigned dirty : 1;
    mListItem() {
        vtable = mListItem__vtable;
        id = 0;
        active = 0;
        selected = 0;
        dirty = 0;
        widget = 0;
        x = 0;
        y = 0;
        w = 0;
        h = 0;
    }
};

extern "C" void func_003285A8(RefCounter *p);
extern "C" void func_003285F8(RefCounter *p);

/* plain pointer wrapper a counted reference is built from */
struct ItemPtr {
    mListItem *p;
    ItemPtr(mListItem *item) : p(item) {}
};

struct ItemRef {
    mListItem *p;
    ItemRef(const ItemPtr &item) __asm__("func_00328738");
    ItemRef(const ItemRef &) __asm__("func_002B5E58");
    ~ItemRef() __asm__("func_002B5E70");
    mListItem *get() const { return p; }
    ItemRef &operator=(const ItemRef &o) {
        if (this != &o) {
            mListItem *n = o.p;
            if (n) func_003285A8(n);
            if (p) func_003285F8(p);
            p = n;
        }
        return *this;
    }
};

typedef vector<ItemRef, GameAlloc<ItemRef> > ItemList;
template <>
void ItemList::insert(ItemRef *pos, size_t n, const ItemRef &x) __asm__("func_005E7F28");

struct Context {
    char pad[0x14];
    void *layout;
};
struct mListBox;
struct ContextRef {
    Context *p;
    ContextRef(mListBox *box) __asm__("func_0025A7E0");
    ContextRef(const ContextRef &);
    ~ContextRef() __asm__("func_0026A118");
    Context *operator->() const { return p; }
};

struct mListBox {
    char pad0[0xC8];
    ItemList items[2];
    s32 current;
    char padEC[0x38];
    s32 m124;
    char pad128[0x28];
    s32 m150;
};

extern char D_008381C8[];
extern "C" void func_00576788(void *lock);
extern "C" void func_005767C0(void *lock);
extern "C" void mListBox__setFocusIndex(mListBox *self, s32 arg);
extern "C" void func_002B4F40(mListBox *self, void *layout, Widget *widget);

extern "C" void mListItem__structor_0(mListBox *self, s32 count) {
    ItemList &old = self->items[self->current];
    s32 oldCount = old.size();
    if (oldCount == count) return;

    ItemList &list = self->items[1 - self->current];
    list.resize(count, ItemRef(ItemPtr(new mListItem)));
    for (s32 i = 0; i < count; i++) {
        if (i < oldCount)
            list[i] = old[i];
        else
            list[i] = ItemRef(ItemPtr(new mListItem));
    }

    func_00576788(D_008381C8);
    self->current = 1 - self->current;
    mListBox__setFocusIndex(self, self->m124);
    self->m150 = 1;
    func_005767C0(D_008381C8);

    void *layout = ContextRef(self)->layout;
    ItemList &dropped = self->items[1 - self->current];
    for (s32 i = count; i < oldCount; i++) {
        mListItem *item = dropped[i].get();
        Widget *widget = item->widget;
        item->widget = 0;
        if (widget) func_002B4F40(self, layout, widget);
    }
}
