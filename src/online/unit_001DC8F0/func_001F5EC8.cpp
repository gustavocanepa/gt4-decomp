/* Returns basic_string<char>(obj->name, 0x100) for the network library object D_00645570 (name at +0x60C); the second argument is unused. bastring.h members inline: (const char *, n) ctor = nilRep.grab() + assign(s, n) = replace(0, npos, s, n). The object pointer held in a local keeps the base address and the field offset as two adds. */
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
inline void Rep::operator delete(void *ptr) {
    func_00326798(ptr, sizeof(Rep) + reinterpret_cast<Rep *>(ptr)->res, 4, func_005C11A8()->name);
}
struct Obj { char pad[0x60C]; char name[0x100]; };
extern Obj D_00645570;
extern "C" String func_001F5EC8(void *) { Obj *o = &D_00645570; return String(o->name, 0x100); }
