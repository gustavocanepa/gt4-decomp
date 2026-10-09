/* Calls mSceneViewFace__virtual_63(a0), then a basic_string<char>(D_0069CF50) temporary (nilRep.grab() + assign(s, strlen(s))) passed to func_003166B8, whose result goes to func_003069F8(a0, a0 + 0xC8, &v) and destroyed (rep()->release(): --ref, Rep::operator delete -> func_00326798(p, sizeof(Rep) + res, 4, heap name)); the value slot is 0x20 bytes in the original frame */
typedef unsigned int u32;
typedef int s32;

struct StringRep { u32 len; u32 res; u32 ref; u32 selfish; };
struct String { char *dat; };
struct Heap { const char *name; };

extern StringRep D_00659FA8;

extern "C" char *func_005C2560(StringRep *r);
extern "C" String *func_005C2630(String *str, u32 pos, u32 n1, const char *s, u32 n2);
extern "C" u32 func_0057F260(const char *s);
extern "C" Heap *func_005C11A8(void);
extern "C" void func_00326798(void *p, u32 n, u32 align, const char *name);
extern char D_0069CF50[];
extern "C" void mSceneViewFace__virtual_63(void *a);
extern "C" s32 func_003166B8(String *s);
extern "C" void func_003069F8(void *obj, void *h, s32 *val);

static inline char *grab(StringRep *r) {
    if (r->selfish)
        return func_005C2560(r);
    ++r->ref;
    return (char *)(r + 1);
}

static inline String &assign(String *str, const char *s, u32 n) {
    return *func_005C2630(str, 0, (u32)-1, s, n);
}

static inline String &assign(String *str, const char *s) {
    return assign(str, s, func_0057F260(s));
}

static inline void construct(String *str, const char *s, u32 n) {
    str->dat = grab(&D_00659FA8);
    assign(str, s, n);
}

static inline void construct(String *str, const char *s) {
    str->dat = grab(&D_00659FA8);
    assign(str, s);
}

static inline StringRep *rep(const String *str) { return (StringRep *)str->dat - 1; }
static inline void deallocate(void *p, u32 n) { func_00326798(p, n, 4, func_005C11A8()->name); }
static inline void rep_delete(void *ptr) { deallocate(ptr, sizeof(StringRep) + ((StringRep *)ptr)->res); }
static inline void release(StringRep *r) { if (--r->ref == 0) rep_delete(r); }
static inline void destroy(String *str) { release(rep(str)); }

extern "C" void mSliderBar__virtual_63(char *a0) {
    s32 v[8];
    String s;
    mSceneViewFace__virtual_63(a0);
    construct(&s, D_0069CF50);
    v[0] = func_003166B8(&s);
    func_003069F8(a0, a0 + 0xC8, v);
    destroy(&s);
}
