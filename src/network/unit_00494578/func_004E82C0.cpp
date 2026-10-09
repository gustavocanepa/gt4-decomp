/* compiler: ee-gcc2.96-no-strict-aliasing */
/* pdistd-http: set the URL (a string of the second basic_string<char>
 * instantiation: nilRep D_00659E20, clone func_005D2B58, operator delete func_00575DA0). */
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

extern "C" u32 func_0057F260(const char *s);

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
    String2 &operator=(const String2 &str) {
        if (&str != this) {
            rep()->release();
            dat = str.rep()->grab();
        }
        return *this;
    }
};

struct Node {
    int color;
    Node *parent;
    Node *left;
    Node *right;
};

struct Tree;
extern "C" void func_0060D830(Tree *t, Node *x);

struct Tree {
    int alloc;
    Node *header;
    u32 node_count;
    Node *&root() { return header->parent; }
    Node *&leftmost() { return header->left; }
    Node *&rightmost() { return header->right; }
    void clear() {
        if (node_count != 0) {
            func_0060D830(this, root());
            leftmost() = header;
            root() = 0;
            rightmost() = header;
            node_count = 0;
        }
    }
};

extern "C" void func_004EA4B0(void *, String2 *);

struct Http {
    char pad[0x80];
    Tree params;
};

extern "C" void func_004E82C0(Http *h, const char *url) {
    h->params.clear();
    String2 s(url);
    func_004EA4B0(h, &s);
}
