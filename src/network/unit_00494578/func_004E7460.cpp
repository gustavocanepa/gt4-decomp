/* compiler: ee-gcc2.96-no-strict-aliasing */
/* pdistd-http: resolve a host name to its dotted address (a string of the second basic_string<char>
 * instantiation: nilRep D_00659E20, clone strobe__toUpper, operator delete func_00575DA0). */
typedef unsigned int u32;

struct Rep2 {
    u32 len;
    u32 res;
    u32 ref;
    u32 selfish;
    char *data() { return (char *)(this + 1); }
    char &operator[](u32 s) { return data()[s]; }
    inline char *grab();
    static void operator delete(void *p, u32 n);
    void release() {
        if (--ref == 0)
            operator delete(this, sizeof(Rep2) + res);
    }
};

extern "C" char *strobe__toUpper(Rep2 *r);
extern "C" void func_00575DA0(void *p);
extern Rep2 D_00659E20;

inline void Rep2::operator delete(void *p, u32 n) { func_00575DA0(p); }

inline char *Rep2::grab() {
    if (selfish)
        return strobe__toUpper(this);
    ++ref;
    return data();
}

extern "C" u32 func_0057F260(const char *s);

extern char D_006BFF30[]; /* "" */

struct String2;
extern "C" String2 *strobe__Any__setMember(String2 *str, u32 pos, u32 n1, const char *s, u32 n2);

struct String2 {
    char *dat;
    char pad[0xC];
    Rep2 *rep() const { return (Rep2 *)dat - 1; }
    String2(const char *s) : dat(D_00659E20.grab()) { assign(s); }
    String2(const String2 &str) : dat(str.rep()->grab()) {}
    u32 length() const { return rep()->len; }
    char *data() const { return rep()->data(); }
    void terminate() const { (*rep())[length()] = 0; }
    const char *c_str() const {
        if (length() == 0)
            return D_006BFF30;
        terminate();
        return data();
    }
    ~String2() { rep()->release(); }
    String2 &replace(u32 pos, u32 n1, const char *s, u32 n2) { return *strobe__Any__setMember(this, pos, n1, s, n2); }
    String2 &assign(const char *s, u32 n) { return replace(0, (u32)-1, s, n); }
    String2 &assign(const char *s) { return assign(s, func_0057F260(s)); }
    String2 &operator=(const String2 &str) {
        if (&str != this) {
            rep()->release();
            dat = str.rep()->grab();
        }
        return *this;
    }
};

struct Address {
    unsigned char bytes[8];
};

extern char D_006BFF28[]; /* "" */
extern "C" int func_004E7408(const String2 *);
extern "C" int func_00523190(const char *, Address *);
extern "C" int func_005223B8(char *, Address);

struct Http {
    char pad[0x48];
    int error;
};

extern "C" String2 func_004E7460(Http *h, const String2 &host) {
    if (func_004E7408(&host)) {
        return host;
    }
    char text[0x20];
    Address address;
    h->error = func_00523190(host.c_str(), &address);
    func_005223B8(text, address);
    if (h->error == 0) {
        return String2(text);
    }
    return String2(D_006BFF28);
}
