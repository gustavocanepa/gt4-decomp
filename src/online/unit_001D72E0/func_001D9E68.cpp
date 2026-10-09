/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Unless *(a1 + 0x188) is set: formats *(a1 + 0x1CC) into a buffer (func_0057DA20), builds
 * D_00695900 + String(a1 + 0x18C) + D_00695908 + String(buf) + D_00695910 and passes it, as a
 * string of the second basic_string instantiation (nilRep D_00659E20, clone func_005D2B58,
 * replace func_005D2C20, operator delete func_00575DA0), to func_004EC078(a0 + 0x10 + 0xA8).
 * gcc 2.96 bastring.h members inline: constructors, destructor, append, operator+, c_str(). */
typedef unsigned int u32;

struct Heap { const char *name; };

extern "C" Heap *func_005C11A8(void);
extern "C" void func_00326798(void *ptr, int size, int align, const char *name);
extern "C" u32 func_0057F260(const char *s);

struct Rep {
    u32 len;
    u32 res;
    u32 ref;
    u32 selfish;
    char *data() { return (char *)(this + 1); }
    char &operator[](u32 s) { return data()[s]; }
    inline char *grab();
    static void operator delete(void *p, u32 n) { func_00326798(p, n, 4, func_005C11A8()->name); }
    void release() {
        if (--ref == 0)
            operator delete(this, sizeof(Rep) + res);
    }
};

extern "C" char *func_005C2560(Rep *r);
extern Rep D_00659FA8;

inline char *Rep::grab() {
    if (selfish)
        return func_005C2560(this);
    ++ref;
    return data();
}

struct String;
extern "C" String *func_005C2630(String *str, u32 pos, u32 n1, const char *s, u32 n2);
extern "C" String *func_005CE388(String *str, u32 pos1, u32 n1, const String *s, u32 pos2, u32 n2);
extern char D_006957A8[]; /* "" */

struct String {
    char *dat;
    char pad[0xC];
    Rep *rep() const { return (Rep *)dat - 1; }
    String(const char *s) : dat(D_00659FA8.grab()) { assign(s); }
    String(const String &str, u32 pos, u32 n = (u32)-1) : dat(D_00659FA8.grab()) { assign(str, pos, n); }
    String(const String &str) : dat(str.rep()->grab()) {}
    ~String() { rep()->release(); }
    u32 length() const { return rep()->len; }
    char *data() const { return rep()->data(); }
    void terminate() const { (*rep())[length()] = 0; }
    const char *c_str() const {
        if (length() == 0)
            return D_006957A8;
        terminate();
        return data();
    }
    String &replace(u32 pos, u32 n1, const char *s, u32 n2) { return *func_005C2630(this, pos, n1, s, n2); }
    String &replace(u32 pos1, u32 n1, const String &str, u32 pos2, u32 n2) {
        return *func_005CE388(this, pos1, n1, &str, pos2, n2);
    }
    String &append(const String &str, u32 pos = 0, u32 n = (u32)-1) { return replace(length(), 0, str, pos, n); }
    String &append(const char *s, u32 n) { return replace(length(), 0, s, n); }
    String &append(const char *s) { return append(s, func_0057F260(s)); }
    String &assign(const String &str, u32 pos = 0, u32 n = (u32)-1) { return replace(0, (u32)-1, str, pos, n); }
    String &assign(const char *s, u32 n) { return replace(0, (u32)-1, s, n); }
    String &assign(const char *s) { return assign(s, func_0057F260(s)); }
};

inline String operator+(const char *lhs, const String &rhs) {
    String str(lhs);
    str.append(rhs);
    return str;
}

inline String operator+(const String &lhs, const char *rhs) {
    String str(lhs);
    str.append(rhs);
    return str;
}

inline String operator+(const String &lhs, const String &rhs) {
    String str(lhs);
    str.append(rhs);
    return str;
}


struct Rep2 {
    u32 len;
    u32 res;
    u32 ref;
    u32 selfish;
    char *data() { return (char *)(this + 1); }
    inline char *grab();
    static void operator delete(void *p, u32 n);
    void release() {
        if (--ref == 0)
            operator delete(this, sizeof(Rep2) + res);
    }
};

extern "C" char *func_005D2B58(Rep2 *r);
extern "C" void func_00575DA0(void *p);
extern Rep2 D_00659E20;

inline void Rep2::operator delete(void *p, u32 n) { func_00575DA0(p); }

inline char *Rep2::grab() {
    if (selfish)
        return func_005D2B58(this);
    ++ref;
    return data();
}

struct String2;
extern "C" String2 *func_005D2C20(String2 *str, u32 pos, u32 n1, const char *s, u32 n2);

struct String2 {
    char *dat;
    char pad[0xC];
    Rep2 *rep() const { return (Rep2 *)dat - 1; }
    String2(const char *s) : dat(D_00659E20.grab()) { assign(s); }
    ~String2() { rep()->release(); }
    String2 &replace(u32 pos, u32 n1, const char *s, u32 n2) { return *func_005D2C20(this, pos, n1, s, n2); }
    String2 &assign(const char *s, u32 n) { return replace(0, (u32)-1, s, n); }
    String2 &assign(const char *s) { return assign(s, func_0057F260(s)); }
};

extern char D_006958F8[];
extern char D_00695900[];
extern char D_00695908[];
extern char D_00695910[];
extern "C" void func_0057DA20(char *buf, const char *fmt, ...);
extern "C" void func_004EC078(void *obj, String2 *s);

extern "C" void func_001D9E68(char *a0, char *a1) {
    if (*(int *)(a1 + 0x188) != 0)
        return;
    char buf[0x20];
    func_0057DA20(buf, D_006958F8, *(int *)(a1 + 0x1CC));
    String r = D_00695900 + String(a1 + 0x18C) + D_00695908 + String(buf) + D_00695910;
    char *p = a0 + 0x10;
    String2 t(r.c_str());
    func_004EC078(p + 0xA8, &t);
}
