/* compiler: ee-gcc2.96-no-strict-aliasing */
/* mSelectBox virtual 63: refreshes the base (mSceneViewFace__virtual_63), copies two floats from the linked object (func_00206868) into +0xE4/+0xE8, then passes func_003166B8(basic_string<char>(D_0069CE08)) to func_003069F8(this, this + 0xF4, &v). bastring.h members inline (ctor = nilRep.grab() + assign(s, strlen(s)), dtor = rep()->release() -> Rep::operator delete -> deallocate(p, sizeof(Rep) + res)); needs -fno-strict-aliasing for the register choice of the grab. */
typedef unsigned int u32;
typedef int s32;
typedef unsigned int size_t;
struct Heap { const char *name; };
extern "C" Heap *func_005C11A8(void);
extern "C" void func_00326798(void *ptr, size_t size, size_t align, const char *name);
extern "C" size_t func_0057F260(const char *s);
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
    size_t length() const { return rep()->len; }
};
struct GameAlloc {
    static void deallocate(void *p, size_t n) { func_00326798(p, n, 4, func_005C11A8()->name); }
};
inline void Rep::operator delete(void *ptr) {
    GameAlloc::deallocate(ptr, sizeof(Rep) + reinterpret_cast<Rep *>(ptr)->res);
}
extern char D_0069CE08[];
extern "C" void mSceneViewFace__virtual_63(void *a);
extern "C" void *func_00206868(void *a);
extern "C" float func_0025B370(void *a);
extern "C" float func_0025B3D0(void *a);
extern "C" s32 func_003166B8(String *s);
extern "C" void func_003069F8(void *obj, void *h, s32 *val);
extern "C" void mSelectBox__virtual_63(char *a0) {
    s32 v[8];
    mSceneViewFace__virtual_63(a0);
    void *o = func_00206868(a0);
    if (o) {
        *(float *)(a0 + 0xE4) = func_0025B370(o);
        *(float *)(a0 + 0xE8) = func_0025B3D0(o);
    }
    String s(D_0069CE08);
    v[0] = func_003166B8(&s);
    func_003069F8(a0, a0 + 0xF4, v);
}
