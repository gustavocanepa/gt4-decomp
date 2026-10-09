/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Builds "A" + date.substr(0, 4) + "B" + date.substr(5, 3) + "C" + date.substr(8, 2) from the
 * date string D_0068BB00 and passes its c_str() to func_00101BD8. Written with gcc 2.96
 * bastring.h members inline: (const char *) and (const basic_string &, pos, n) constructors
 * (nilRep.grab() + assign = replace), copy constructor (Rep::grab), destructor (Rep::release),
 * append(const basic_string &) = replace(length(), 0, str, 0, npos) (func_005CE388),
 * append(const char *) = replace(length(), 0, s, strlen(s)), operator+ and c_str(). */
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
extern char D_00692E68[]; /* "" */

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
            return D_00692E68;
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

extern char D_0068BB00[];
extern char D_00692E48[];
extern char D_00692E58[];
extern char D_00692E60[];
extern "C" void func_00101BD8(const char *s);

extern "C" void MSystem__Reboot(void) {
    String date(D_0068BB00);
    String y(date, 0, 4);
    String m(date, 5, 3);
    String d(date, 8, 2);
    String r = D_00692E48 + y + D_00692E58 + m + D_00692E60 + d;
    func_00101BD8(r.c_str());
}
