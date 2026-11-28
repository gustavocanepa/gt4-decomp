/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

/* mKeytopBox activation: sends this key top's action to the input field of
 * the keyboard box it sits in. Kind 0 types the key's "ch" attribute (the
 * part after a '/' if there is one), the others are editing commands. */

extern "C" s32 func_0057F260(const char *s) throw();
extern "C" char *func_005A609C(char *dst, const char *src);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
struct TypeName {
    const char *name;
};
extern "C" TypeName *func_005C11A8(void);

/* the game's string: libstdc++ v2 basic_string */
struct Rep {
    s32 len, res, ref, selfish;
    char *data() { return (char *)(this + 1); }
    char *clone() __asm__("func_005C2560");
    char *grab() {
        if (selfish) return clone();
        ++ref;
        return data();
    }
    void release() {
        if (--ref == 0) {
            s32 size = res + 0x10;
            func_00326798(this, size, 4, func_005C11A8()->name);
        }
    }
};
extern Rep D_00659FA8;
extern char D_0069BD50[]; /* "" */

struct String {
    char *dat;
    Rep *rep() const { return (Rep *)dat - 1; }
    s32 length() const { return rep()->len; }
    void terminate() const { rep()->data()[length()] = 0; }
    String &replace(s32 pos, s32 n, const char *s, s32 len) __asm__("func_005C2630");
    String(const char *s) : dat(D_00659FA8.grab()) { replace(0, -1, s, func_0057F260(s)); }
    String(const String &);
    ~String() { rep()->release(); }
    const char *c_str() const {
        if (length() == 0) return D_0069BD50;
        terminate();
        return rep()->data();
    }
};

extern "C" s32 HSymID__GetID(const String *name);
struct SymID {
    s32 id;
    SymID(const String &name) : id(HSymID__GetID(&name)) {}
    SymID(const SymID &);
};

struct Object;
struct Value {
    Object *p;
    Value() __asm__("func_0030BB18");
    Value(const Value &);
    ~Value() __asm__("func_00309378");
    Object *get() const { return p; }
};

struct MString;
extern "C" const String *func_002450D0(MString *s);
struct MStringRef {
    MString *p;
    MStringRef(const Value &v) __asm__("func_002434C8");
    MStringRef(const MStringRef &);
    ~MStringRef() __asm__("func_00243470");
    const String &str() const { return *func_002450D0(p); }
};

struct mInputField;
extern "C" void func_002A7A40(mInputField *field, const char *text);
extern "C" void func_002A7AA0(mInputField *field);
extern "C" void func_002A7B80(mInputField *field);
extern "C" void func_002A7BB8(mInputField *field);

struct VEntry {
    short delta;
    short index;
    s32 fn;
};
struct mWidget {
    s32 refCount;
    VEntry *vtbl;
};
struct InputRef {
    mInputField *p;
    mInputField *get() const { return p; }
};
struct mKeyboardBox {
    char pad[0xB0];
    InputRef input;
};
struct mKeytopBox {
    char pad[0xB0];
    s32 kind;
};

extern char mKeyboardBox__tf[];
extern char mComposite__tf[];
extern "C" void *__dynamic_cast_2(s32, void *, s32, void *, void *, void *);
extern "C" mWidget *func_0025C2A0(mKeytopBox *self);
extern "C" void func_003069F8(mKeytopBox *self, Value *out, const SymID *name);

static inline mKeyboardBox *keyboard_of(mWidget *w) {
    mKeyboardBox *box = 0;
    if (w != 0) {
        VEntry *e = w->vtbl;
        box = (mKeyboardBox *)__dynamic_cast_2(e->fn, mKeyboardBox__tf, 0, (char *)w + e->delta, mComposite__tf, w);
    }
    return box;
}

extern "C" s32 mKeytopBox__on_activate(mKeytopBox *self) {
    mKeyboardBox *box = keyboard_of(func_0025C2A0(self));
    if (box == 0) return 2;
    if (box->input.get() == 0) return 2;

    switch (self->kind) {
    case 0: {
        Value v;
        func_003069F8(self, &v, &SymID(String("ch")));
        if (v.get() == 0) return 2;
        MStringRef text(v);
        char buf[128];
        func_005A609C(buf, text.str().c_str());
        char *p = buf;
        s32 n = func_0057F260(buf);
        s32 i;
        for (i = 0; i < n; i++) {
            if (buf[i] == '/') break;
        }
        if (i < n) p = buf + i + 1;
        func_002A7A40(box->input.get(), p);
        break;
    }
    case 1:
        func_002A7AA0(box->input.get());
        break;
    case 4:
        func_002A7B80(box->input.get());
        break;
    case 7:
        func_002A7BB8(box->input.get());
        break;
    case 2:
    case 3:
    case 5:
    case 6:
    case 8:
        break;
    }
    return 2;
}
