/* compiler: ee-gcc2.96-no-strict-aliasing */
#include "types.h"

/* Class-define instruction of the script VM: resolves the class handle once
 * (name, then the super symbol), creating the class through the method named
 * by D_00841038 when only the super is found, and opens a frame on it.
 *
 * The constructors and destructors are the real out-of-line ones (the old ABI
 * passes the in-charge flag 2 itself): with inline wrappers around them the
 * code is the same but the `&cls` and temporary address pseudos swap their
 * saved registers (global-alloc priority 1190 against 1186). */

struct Heap {
    const char *name;
};

extern "C" Heap *func_005C11A8(void);
extern "C" void func_00326798(void *ptr, u32 size, s32 align, const char *name);
extern "C" u32 func_0057F260(const char *s);

struct Rep {
    u32 len;
    u32 res;
    u32 ref;
    u32 selfish;
    char *data() { return (char *)(this + 1); }
    inline char *grab();
    static void operator delete(void *p, u32 n) { func_00326798(p, n, 4, func_005C11A8()->name); }
    void release() {
        if (--ref == 0)
            operator delete(this, sizeof(Rep) + res);
    }
};

extern "C" char *func_005C2560(Rep *r);
extern Rep nilRep __asm__("D_00659FA8");

inline char *Rep::grab() {
    if (selfish)
        return func_005C2560(this);
    ++ref;
    return data();
}

struct String;
extern "C" String *func_005C2630(String *str, u32 pos, u32 n1, const char *s, u32 n2);

struct String {
    char *dat;
    char pad[0xC];
    Rep *rep() const { return (Rep *)dat - 1; }
    String(const char *s) : dat(nilRep.grab()) { assign(s); }
    ~String() { rep()->release(); }
    String &replace(u32 pos, u32 n1, const char *s, u32 n2) { return *func_005C2630(this, pos, n1, s, n2); }
    String &assign(const char *s, u32 n) { return replace(0, (u32)-1, s, n); }
    String &assign(const char *s) { return assign(s, func_0057F260(s)); }
};

extern "C" void func_003285A8(void *obj); /* strong reference ++ */
extern "C" void func_003285F8(void *obj); /* strong reference -- */
extern "C" void func_00328660(void *obj); /* weak reference ++ */
extern "C" void func_003286B8(void *obj); /* weak reference -- */
extern "C" int func_003284E8(void *obj);  /* still alive? */

/* A string object made from a String. */
struct StringRef {
    void *p;
    StringRef(const StringRef &);
    StringRef(const String &s) __asm__("func_00314B20");
    ~StringRef() __asm__("func_00312318");
};

struct ClassRef {
    void *p;
    ClassRef(const ClassRef &);
    ClassRef() __asm__("func_002F3A50");
    ~ClassRef() __asm__("func_002F2A08");
};

struct Value {
    void *p;
    Value(const Value &);
    Value() __asm__("func_0030BB18");
    ~Value() __asm__("func_00309378");
    void set(void **src) {
        if (&p != src) {
            void *n = *src;
            if (n) func_003285A8(n);
            if (p) func_003285F8(p);
            p = n;
        }
    }
    Value &operator=(const StringRef &o) { set((void **)&o.p); return *this; }
    Value &operator=(const ClassRef &o) { set((void **)&o.p); return *this; }
};

struct WeakClassRef {
    void *p;
    void *get() {
        int expired = 0;
        if (p == 0 || func_003284E8(p) == 0) expired = 1;
        void *v = 0;
        if (!expired) v = p;
        return v;
    }
    WeakClassRef &operator=(const ClassRef &o) {
        void *n = o.p;
        if (n) func_00328660(n);
        if (p) func_003286B8(p);
        p = n;
        return *this;
    }
};

struct Binding {
    void *p;
    Binding(const Binding &);
    ~Binding() __asm__("func_00323B60");
};

struct ClassDefine {
    s32 refCount;
    void *vtbl;
    s32 name;
    s32 super;
    char pad10[0xC];
    WeakClassRef cls;
};

extern const char D_00841038[];

extern "C" void *func_00322060(void *thread);
extern "C" void func_003069F8(void *context, Value *out, s32 *sym);
extern "C" int func_002F2AA8(ClassRef *out, Value *value);
extern "C" void func_00321EC8(void *thread, Value *out, s32 *sym);
extern "C" const char *HSymID__GetName(s32 sym);
extern "C" void *hClass__GetClassID(void);
extern "C" void hObject__send(void *receiver, ClassRef *result, const char *method, s32 argc, Value *argv);
extern "C" Binding func_00306638(void *context, ClassRef *cls);
extern "C" void HModuleFrame__structor_0(void *thread, void *cls);

extern "C" void mClassDefine__execute(ClassDefine *self, void *thread) {
    WeakClassRef *h = &self->cls;
    if (h->get() == 0) {
        void *context = func_00322060(thread);
        Value value;
        func_003069F8(context, &value, &self->name);
        ClassRef cls;
        if (func_002F2AA8(&cls, &value) == 0) {
            func_00321EC8(thread, &value, &self->super);
            if (func_002F2AA8(&cls, &value) != 0) {
                Value args[2];
                args[0] = StringRef(String(HSymID__GetName(self->name)));
                args[1] = cls;
                hObject__send(hClass__GetClassID(), &cls, D_00841038, 2, args);
                func_00306638(context, &cls);
            }
        }
        *h = cls;
    }
    HModuleFrame__structor_0(thread, h->get());
}
