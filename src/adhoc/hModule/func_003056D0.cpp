/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Returns the dotted path of a node: its parent's path (recursively), "." and its own name,
 * or the name alone at the root. Written with gcc 2.96 bastring.h members inline: default and
 * copy constructors (Rep::grab), destructor (Rep::release), operator=(const basic_string &),
 * operator=(const char *) = assign = replace(0, npos, s, n), and
 * operator+(const basic_string &, const char *) = copy + append = replace(length(), 0, s, n).
 * strlen and hModule__getName (defined above in the unit) are declared throw(), as reorg saw them. */
typedef unsigned int u32;

struct Heap { const char *name; };

extern "C" Heap *func_005C11A8(void);
extern "C" void func_00326798(void *ptr, int size, int align, const char *name);
extern "C" u32 func_0057F260(const char *s) throw();

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
extern Rep D_00659FA8;

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
    String() : dat(D_00659FA8.grab()) {}
    String(const String &str) : dat(str.rep()->grab()) {}
    ~String() { rep()->release(); }
    u32 length() const { return rep()->len; }
    String &replace(u32 pos, u32 n1, const char *s, u32 n2) { return *func_005C2630(this, pos, n1, s, n2); }
    String &append(const char *s, u32 n) { return replace(length(), 0, s, n); }
    String &append(const char *s) { return append(s, func_0057F260(s)); }
    String &assign(const char *s, u32 n) { return replace(0, (u32)-1, s, n); }
    String &assign(const char *s) { return assign(s, func_0057F260(s)); }
    String &operator=(const char *s) { return assign(s); }
    String &operator=(const String &str) {
        if (&str != this) {
            rep()->release();
            dat = str.rep()->grab();
        }
        return *this;
    }
};

inline String operator+(const String &lhs, const char *rhs) {
    String str(lhs);
    str.append(rhs);
    return str;
}

extern char D_0069DC48[]; /* "." */
extern "C" void *func_003055C8(void *node);
extern "C" const char *hModule__getName(void *node) throw();

extern "C" String func_003056D0(void *node) {
    String r;
    if (func_003055C8(node)) {
        r = func_003056D0(func_003055C8(node)) + D_0069DC48 + hModule__getName(node);
    } else {
        r = hModule__getName(node);
    }
    return r;
}

