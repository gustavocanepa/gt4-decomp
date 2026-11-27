/* compiler: ee-gcc2.96-stl */
/*
 * mOSKeyboard::initialize (GT HD name; everything else inferred): loads the on-screen keyboard's
 * layout from the script module "OSKeyboard" and its "/config/OSK_US" file. OSK_SIZE gives the
 * page count, the columns and the rows; the key table is sized to pages * columns * rows and
 * filled from OSK_TABLE (each entry: four [label, code] pairs, one per shift state), then again
 * from OSK_TABLE2 (each entry: [enabled, four [label, code] pairs], labels translated through the
 * owner's localizer when a translation exists). The handles are cleared at the end.
 *
 * What decided the code: the module handle is built by a converting constructor (the GT HD
 * name HModule::dynamicAssign) through copy-initialization, whose temporary takes a stack slot
 * of its own; the handle tests go through a bool inline (isNull), which makes reorg fill their
 * delay slots from the branch target; the loop bound is recomputed after resize().
 */
#include <stl_algobase.h>
#include <stl_alloc.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
#include <stl_vector.h>

typedef int s32;
typedef unsigned int u32;

/* libstdc++ v2 basic_string<char> (bastring.h), the parts used here */
struct Rep;
extern "C" char *func_005C2560(Rep *src) throw();  /* Rep::clone */
struct Rep {
    s32 len;
    s32 cap;
    s32 ref;
    s32 sel;
    char *data() { return (char *)(this + 1); }
    char *grab() {
        if (sel)
            return func_005C2560(this);
        ++ref;
        return data();
    }
};

struct Heap {
    const char *name;
};

extern Rep D_00659FA8;  /* nilRep */
extern "C" Heap *func_005C11A8(void) throw();
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" s32 func_0057F260(const char *s) throw();  /* strlen */
struct Str;
extern "C" void *func_005C2630(Str *s, u32 pos, u32 n1, const char *src, u32 n2);  /* replace */

struct Str {
    char *p;
    Rep *rep() const { return (Rep *)p - 1; }
    Str() : p(D_00659FA8.grab()) {}
    Str(const char *s) : p(D_00659FA8.grab()) { assign(s); }
    Str(const Str &o) : p(o.rep()->grab()) {}
    ~Str() {
        Rep *q = rep();
        if (--q->ref == 0) {
            s32 cap = q->cap + 0x10;
            func_00326798(q, cap, 4, func_005C11A8()->name);
        }
    }
    void assign(const char *s, u32 n) { func_005C2630(this, 0, (u32)-1, s, n); }
    void assign(const char *s) { assign(s, func_0057F260(s)); }
    Str &operator=(const Str &o) {
        if (&o != this) {
            Rep *q = rep();
            if (--q->ref == 0) {
                s32 cap = q->cap + 0x10;
                func_00326798(q, cap, 4, func_005C11A8()->name);
            }
            p = o.rep()->grab();
        }
        return *this;
    }
};

/* One key of the on-screen keyboard: an enabled flag, then a label and a code per shift state
   (the element of the vector whose insert(position, n, x) is func_005E8E40). */
struct Key {
    s32 enabled;
    Str label[4];
    s32 code[4];
};

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
    T *allocate(size_type n, const void * = 0);
    void deallocate(T *p, size_type n);
    size_type max_size() const throw() { return size_t(-1) / sizeof(T); }
};

typedef vector<Key, GameAlloc<Key> > KeyVec;

/* vector<Key>::insert(position, n, x), matched out of line as func_005E8E40 */
extern "C" void func_005E8E40(KeyVec *v, Key *position, unsigned int n, const Key &x);
template <> inline void KeyVec::insert(Key *position, unsigned int n, const Key &x) {
    func_005E8E40(this, position, n, x);
}

/* Script values (hObject, virtual slots as in include/gt4/hObject.h) and their handles */
struct hObject;
struct HObject {
    hObject *p;
    HObject(const HObject &) __asm__("func_00309360");
    ~HObject() __asm__("func_00309378");
    hObject *operator->() { return p; }
};

struct hObject {
    s32 refCount;
    virtual ~hObject();
    virtual void cleanup();
    virtual Str toString();
    virtual s32 rc_class();
    virtual s32 rc_size();
    virtual void weak_inc();
    virtual void weak_dec();
    virtual s32 weak_count();
    virtual void deepCopy();
    virtual s32 getClassID();
    virtual s32 toInt();
    virtual float toFloat();
    virtual const HObject &getElement(u32 index) const;
    virtual HObject &getElement(u32 index);
};

extern "C" void func_003285A8(void *object);  /* retain */
extern "C" void func_003285F8(void *object);  /* release */

/* A handle that a module lookup fills in */
struct Handle {
    hObject *p;
    Handle() __asm__("func_002EFBF0");
    Handle(hObject *const &object) __asm__("func_002ED590");
    Handle(const Handle &);
    ~Handle() __asm__("func_002ED5C0");
    hObject *operator->() { return p; }
    bool isNull() const { return p == 0; }
    Handle &operator=(const Handle &o) {
        if (this != &o) {
            hObject *q = o.p;
            if (q)
                func_003285A8(q);
            if (p)
                func_003285F8(p);
            p = q;
        }
        return *this;
    }
};

extern "C" s32 HSymID__GetID(const Str *name);
struct SymID {
    s32 id;
    SymID(const Str &name) : id(HSymID__GetID(&name)) {}
    SymID(const SymID &o) : id(o.id) {}
};

struct hModule {
    s32 load(const Str &path) __asm__("func_00305CF8");
    void getValue(Handle &out, const SymID &name) __asm__("func_003069F8");
    const char *getName() __asm__("hModule__getName");
};

struct Module {
    hModule *p;
    Module(const SymID &name) __asm__("HModule__dynamicAssign");  /* finds or creates the module */
    Module(hModule *const &module) __asm__("func_00304188");
    Module(const Module &);
    ~Module() __asm__("func_003041B8");
    hModule *operator->() { return p; }
    Module &operator=(const Module &o) {
        if (this != &o) {
            hModule *q = o.p;
            if (q)
                func_003285A8(q);
            if (p)
                func_003285F8(p);
            p = q;
        }
        return *this;
    }
};

struct Localizer;
extern "C" Localizer *func_0025C110(hModule *root);
/* the translation of a label for a module, or 0 */
extern "C" const char *func_00229D40(Localizer *localizer, const char *module, Str *label);

struct Owner {
    char pad[0x1D08];
    hModule *root;
};

struct mOSKeyboard {
    char pad0[0x30];
    s32 pages;
    s32 pad34;
    s32 rows;
    s32 pad3c;
    s32 cols;
    s32 pad44;
    KeyVec keys;
    s32 keyCount() const { return rows * cols * pages; }
};

extern char D_0069C5B0[]; /* "OSKeyboard" */
extern char D_0069C5C0[]; /* "/config/OSK_US" */
extern char D_0069C5D0[]; /* "OSK_SIZE" */
extern char D_0069C5E0[]; /* "OSK_TABLE" */
extern char D_0069C5F0[]; /* "OSK_TABLE2" */

extern "C" void mOSKeyboard__initialize(mOSKeyboard *self, Owner *owner) {
    Module module = SymID(Str(D_0069C5B0));
    if (module->load(Str(D_0069C5C0))) {
        Handle size;
        module->getValue(size, SymID(Str(D_0069C5D0)));
        if (!size.isNull()) {
            self->pages = size->getElement(0)->toInt();
            self->cols = size->getElement(1)->toInt();
            self->rows = size->getElement(2)->toInt();
        }

        Handle table;
        module->getValue(table, SymID(Str(D_0069C5E0)));
        if (!table.isNull()) {
            self->keys.resize(self->keyCount());
            s32 count = self->keyCount();
            for (s32 i = 0; i < count; i++) {
                self->keys[i].enabled = 1;
                for (s32 j = 0; j < 4; j++) {
                    HObject cell = table->getElement(i * 4 + j);
                    self->keys[i].label[j] = cell->getElement(0)->toString();
                    self->keys[i].code[j] = cell->getElement(1)->toInt();
                }
            }
        }

        module->getValue(table, SymID(Str(D_0069C5F0)));
        if (!table.isNull()) {
            hModule *root = owner->root;
            Localizer *localizer = func_0025C110(root);
            self->keys.resize(self->keyCount());
            s32 count = self->keyCount();
            for (s32 i = 0; i < count; i++) {
                HObject row = table->getElement(i);
                self->keys[i].enabled = row->getElement(0)->toInt() != 0;
                if (self->keys[i].enabled) {
                    for (s32 j = 0; j < 4; j++) {
                        HObject cell = row->getElement(j + 1);
                        Str label = cell->getElement(0)->toString();
                        const char *text = func_00229D40(localizer, root->getName(), &label);
                        if (text)
                            label.assign(text);
                        self->keys[i].label[j] = label;
                        self->keys[i].code[j] = cell->getElement(1)->toInt();
                    }
                }
            }
        }

        size = Handle(0);
        table = Handle(0);
        module = Module(0);
    }
}
