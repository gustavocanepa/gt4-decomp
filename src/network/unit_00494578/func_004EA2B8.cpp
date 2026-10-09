/* compiler: ee-gcc2.96-no-strict-aliasing */
/* pdistd-http: reset a connection: clear the request string (second basic_string<char>
 * instantiation: replace func_005D2C20) and the header map (an SGI _Rb_tree: clear() with
 * _M_erase func_0060D830 inline), then reopen. */
typedef unsigned int u32;

extern "C" u32 func_0057F260(const char *s);

struct String2;
extern "C" String2 *func_005D2C20(String2 *str, u32 pos, u32 n1, const char *s, u32 n2);

struct String2 {
    char *dat;
    String2 &replace(u32 pos, u32 n1, const char *s, u32 n2) { return *func_005D2C20(this, pos, n1, s, n2); }
    String2 &assign(const char *s, u32 n) { return replace(0, (u32)-1, s, n); }
    String2 &assign(const char *s) { return assign(s, func_0057F260(s)); }
    String2 &operator=(const char *s) { return assign(s); }
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

extern char D_006BFF28[];
extern "C" int func_00575DC8(int);
extern "C" void func_004EB830(void *);
extern "C" void func_004EB7D0(void *);

struct Http {
    int pad0[2];
    int heap;
    char pad0C[0x40];
    int buffer;
    int pad50;
    String2 request;
    char pad58[0x18];
    Tree headers;
    char pad7C[0x4C];
    int keep_alive;
    int fCC;
    int fD0;
    int padD4[4];
    int fE4;
};

extern "C" int func_004EA2B8(Http *h) {
    h->fCC = 0;
    h->fD0 = 0;
    h->fE4 = 0;
    h->request = D_006BFF28;
    h->headers.clear();
    h->buffer = func_00575DC8(h->heap);
    if (h->keep_alive == 0) {
        func_004EB830(h);
        return 1;
    }
    func_004EB7D0(h);
    return 1;
}
