/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
typedef int s32;
typedef unsigned int size_t;
struct Heap { const char *name; };
extern "C" Heap *func_005C11A8(void) throw();
extern "C" void func_00326798(void *ptr, size_t size, size_t align, const char *name) throw();
extern "C" size_t func_0057F260(const char *s) throw();
struct Rep;
extern "C" char *func_005C2560(Rep *r);
struct traits {
    static size_t length(const char *s) { return func_0057F260(s); }
};
struct Rep {
    size_t len, res, ref;
    bool selfish;
    char *data() { return reinterpret_cast<char *>(this + 1); }
    char *grab() { if (selfish) return clone(); ++ref; return data(); }
    void release() { if (--ref == 0) delete this; }
    inline static void operator delete(void *);
    char *clone() { return func_005C2560(this); }
};
extern Rep D_00659FA8;
struct String;
extern "C" String *func_005C2630(String *str, size_t pos, size_t n1, const char *s, size_t n2);
struct String {
    char *dat;
    Rep *rep() const { return reinterpret_cast<Rep *>(dat) - 1; }
    String &replace(size_t pos, size_t n1, const char *s, size_t n2) { return *func_005C2630(this, pos, n1, s, n2); }
    String &assign(const char *s, size_t n) { return replace(0, (size_t)-1, s, n); }
    String &assign(const char *s) { return assign(s, traits::length(s)); }
    String(): dat(D_00659FA8.grab()) {}
    String(const String &str): dat(str.rep()->grab()) {}
    String(const char *s, size_t n): dat(D_00659FA8.grab()) { assign(s, n); }
    String(const char *s): dat(D_00659FA8.grab()) { assign(s); }
    ~String() { rep()->release(); }
    String &operator=(const String &str) {
        if (&str != this) { rep()->release(); dat = str.rep()->grab(); }
        return *this;
    }
    String &operator=(const char *s) { return assign(s); }
    s32 length() const { return rep()->len; }
};
struct GameAlloc {
    static void deallocate(void *p, size_t n) { func_00326798(p, n, 4, func_005C11A8()->name); }
};
inline void Rep::operator delete(void *ptr) {
    GameAlloc::deallocate(ptr, sizeof(Rep) + reinterpret_cast<Rep *>(ptr)->res);
}

struct Obj { s32 unk0; char *vtable; };
struct VEnt { short delta; short index; void (*fn)(void *, const String &); };
struct Module { Obj *object; };

extern "C" const char *hModule__getName(Obj *);
extern "C" void hObject__send(Obj *, void *, const void *, s32, s32);

struct H;
extern "C" void func_002556B0(H *);
extern "C" void func_002550A0(H *, const H *);
extern "C" void func_002550B8(H *, s32);
struct H {
    Obj *p;
    H() { func_002556B0(this); }
    H(const H &o) { func_002550A0(this, &o); }
    ~H() { func_002550B8(this, 2); }
    bool isValid() const { return p != 0; }
};

struct Pair {
    String key;
    H val;
    Pair(const String &s, const H &h) : key(s), val(h) {}
};
struct Node;
struct Iter {
    Node *p;
    Iter(Node *n) : p(n) {}
    Iter(const Iter &o) : p(o.p) {}
};
struct InsertResult { Iter pos; bool inserted; };
struct Map;
extern "C" InsertResult func_005D8BE8(Map *, const Pair &) asm("func_005D8BE8");
struct Map {
    s32 count;
    Node *header;
    InsertResult insert(const Pair &v) { return func_005D8BE8(this, v); }
};
struct MManager { char pad0[0x10]; Map prototypes; };

extern char D_0082B4E0[];

/* Asks the module's root object for its widget prototype; when there is one, names it after the
   module (virtual slot 50, a `const String &` setter) and registers it in the manager's
   name -> prototype map.
   The null test goes through H::isValid(): the bool it returns reaches the branch as an
   `sltu`, so the branch gets an even probability and reorg fills its delay slot from the
   target (`daddu $a0, $sp`), as retail does; a bare `h.p != 0` is predicted not taken and
   takes the fall-through's `lui` instead. */
extern "C" void func_002127E8(MManager *self, Module *module) {
    H h;
    hObject__send(module->object, &h, D_0082B4E0, 0, 0);
    if (h.isValid()) {
        Obj *o = h.p;
        VEnt *e = (VEnt *)(o->vtable + 0x190);
        void *adjusted = (char *)o + e->delta;
        e->fn(adjusted, String(hModule__getName(module->object)));
        self->prototypes.insert(Pair(String(hModule__getName(h.p)), h));
    }
}
