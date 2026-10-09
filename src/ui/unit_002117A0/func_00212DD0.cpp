/* Builds a handle h (func_002550A0, destroyed by func_002550B8(&h, 2)) and calls func_00212A68(this, h.v, basic_string<char>(D_00697A60)). The handle is a class whose constructor returns its object and whose destructor runs after the string's (reverse declaration order). bastring.h members inline ((const char *) ctor = nilRep.grab() + assign(s, strlen(s)), dtor = rep()->release() -> Rep::operator delete -> deallocate(p, sizeof(Rep) + res)). */
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
struct H;
extern "C" H *func_002550A0(H *h);
extern "C" void func_002550B8(H *h, s32 f);
struct H { s32 v; s32 pad[3]; H() { func_002550A0(this); } ~H() { func_002550B8(this, 2); } };
extern char D_00697A60[];
extern "C" void func_00212A68(void *a, s32 v, String *s);
extern "C" void func_00212DD0(void *a0) {
    H h;
    s32 v = h.v;
    String s(D_00697A60);
    func_00212A68(a0, v, &s);
}
