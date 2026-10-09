/* Constructor of a text-style record: colour (func_00202C48(this, 0xFFD4D4D4), which returns its object), a basic_string<char>(D_006991A8) member (bastring.h: nilRep.grab() + assign(s, strlen(s))), flags/ints/floats in member-initialiser order, a shadow colour (0xFF000000) and more ints. Written as the C++ constructor with its mem-initialiser list, expanded through placement new so the symbol keeps its plain name. */
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
struct Color;
extern "C" Color *func_00202C48(Color *c, u32 rgba);
struct Color { u32 c[4]; Color(u32 rgba) { func_00202C48(this, rgba); } };
extern char D_006991A8[];
struct Style {
    Color color; String text;
    int a14, a18, a1C, a20, a24, a28;
    float s2C, s30, s34, s38;
    int a3C;
    Color shadow;
    int a50, a54, a58, a5C, a60;
    Style() : color(0xFFD4D4D4), text(D_006991A8), a14(1), a18(0), a1C(0), a20(1), a24(4), a28(1),
    s2C(1.0f), s30(1.0f), s34(1.0f), s38(1.0f), a3C(0), shadow(0xFF000000), a50(1), a54(0), a58(0), a5C(0), a60(0) {}
};
inline void *operator new(size_t, void *p) { return p; }
extern "C" void func_00246F58(Style *self) { new (self) Style; }
