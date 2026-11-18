/* compiler: ee-gcc2.96-no-strict-aliasing */
/* pdistd-http request header builder. Strings are the unit's second basic_string instantiation
 * (nilRep D_00659E20, clone strobe__toUpper, replace strobe__Any__setMember, operator delete
 * func_00575DA0) with the gcc 2000-10-03 bastring.h members and operator+ written inline; the
 * header and cookie maps are SGI map<string, string>, the form parameters a list of pairs. */
typedef unsigned int u32;
extern "C" char *strobe__toUpper(struct Rep *);
extern "C" void func_00575DA0(void *) throw();
extern "C" u32 func_0057F260(const char *) throw();
struct Rep {
    u32 len, res, ref, selfish;
    char *data() { return (char *)(this + 1); }
    char &operator[](u32 s) { return data()[s]; }
    char *grab() { if (selfish) return strobe__toUpper(this); ++ref; return data(); }
    void release() { if (--ref == 0) func_00575DA0(this); }
};
extern Rep D_00659E20;
extern const char D_006BFF30[];   /* "" (c_str() of an empty string) */
struct Str;
extern "C" Str *strobe__Any__setMember(Str *, u32, u32, const char *, u32);
extern "C" Str *func_0060DC18(Str *, u32, u32, const Str *, u32, u32);
extern "C" void func_00605A98(Str *, u32, int);
struct Str {
    char *dat;
    Rep *rep() const { return ((Rep *)dat) - 1; }
    Str() : dat(D_00659E20.grab()) {}
    Str(const Str &s) : dat(s.rep()->grab()) {}
    Str(const char *s) : dat(D_00659E20.grab()) { assign(s); }
    ~Str() { rep()->release(); }
    u32 length() const { return rep()->len; }
    Str &assign(const char *s, u32 n) { return *strobe__Any__setMember(this, 0, (u32)-1, s, n); }
    Str &assign(const char *s) { return assign(s, func_0057F260(s)); }
    Str &operator=(const char *s) { return assign(s); }
    Str &append(const Str &s) { return *func_0060DC18(this, length(), 0, &s, 0, (u32)-1); }
    Str &append(const char *s, u32 n) { return *strobe__Any__setMember(this, length(), 0, s, n); }
    Str &append(const char *s) { return append(s, func_0057F260(s)); }
    Str &operator+=(const Str &s) { return append(s); }
    Str &operator+=(const char *s) { return append(s); }
    void alloc(u32 size, int save) { func_00605A98(this, size, save); }
    void unique() { if (rep()->ref > 1) alloc(length(), 1); }
    void selfish() { unique(); rep()->selfish = 1; }
    char &operator[](u32 pos) { selfish(); return (*rep())[pos]; }
    char *begin() { selfish(); return &(*this)[0]; }
    void terminate() const { (*rep())[length()] = 0; }
    const char *c_str() const {
        if (length() == 0)
            return D_006BFF30;
        terminate();
        return rep()->data();
    }
};
static inline Str operator+(const char *lhs, const Str &rhs) {
    Str str(lhs);
    str.append(rhs);
    return str;
}
static inline Str operator+(const Str &lhs, const Str &rhs) {
    Str str(lhs);
    str.append(rhs);
    return str;
}
static inline Str operator+(const Str &lhs, const char *rhs) {
    Str str(lhs);
    str.append(rhs);
    return str;
}

/* map<Str, Str> (red-black tree) and list<pair<Str, Str>> as the unit's other sources write them */
struct Pair { Str first, second; };
struct Node { int color; Node *parent, *left, *right; Pair value; };
struct ItBase {
    Node *n;
    void increment() {
        if (n->right != 0) { n = n->right; while (n->left != 0) n = n->left; }
        else { Node *y = n->parent; while (n == y->right) { n = y; y = y->parent; } if (n->right != y) n = y; }
    }
};
inline bool operator!=(const ItBase &a, const ItBase &b) { return a.n != b.n; }
/* SGI STL: iterator(const iterator &) is iterator's copy constructor (so iterator is passed in
   memory), but only a converting constructor for const_iterator. */
struct It : ItBase {
    It(Node *x) { n = x; }
    It(const It &x) { n = x.n; }
};
struct CIt : ItBase {
    CIt(Node *x) { n = x; }
    CIt(const It &x) { n = x.n; }
    const Pair *operator->() const { return &n->value; }
    CIt operator++(int) { CIt tmp = *this; increment(); return tmp; }
};
struct Map {
    int alloc; Node *header; u32 count;
    It begin() { return It(header->left); }
    It end() { return It(header); }
    u32 size() const { return count; }
};
struct LNode { LNode *next, *prev; Pair value; };
struct LItBase {
    LNode *n;
    bool operator!=(const LItBase &x) const { return n != x.n; }
};
struct LIt : LItBase {
    LIt(LNode *x) { n = x; }
    LIt(const LIt &x) { n = x.n; }
};
struct CLIt : LItBase {
    CLIt(LNode *x) { n = x; }
    CLIt(const LIt &x) { n = x.n; }
    const Pair *operator->() const { return &n->value; }
    CLIt operator++(int) { CLIt tmp = *this; n = n->next; return tmp; }
};
struct List {
    int alloc; LNode *node;
    LIt begin() { return LIt(node->next); }
    LIt end() { return LIt(node); }
};

struct URL { int kind; Str user, pass, host; int port; Str path; };
extern "C" Str func_004ECC98(const URL *u);

struct Http {
    int method;
    int pad04[2];
    Str agent;
    int pad10[8];
    int form;
    int keepAlive;
    int pad38[8];
    Map headers;
    int pad64;
    List params;
    int pad70[4];
    Map cookies;
    int pad8C;
    URL url;
    int padA8;
    Str proxyUser;
    Str proxyPass;
};

struct Base64 {};  /* the encoder object func_0060DD00 is a member of (no state) */
extern "C" int func_0060DD00(Base64 *, char *dst, const signed char *src, u32 len);
struct MD5 { char ctx[0x58]; };  /* init 57B850, update 57C718, final 57C808, hex 57C8B0 */
extern "C" void func_0057B850(MD5 *);
extern "C" void func_0057C718(MD5 *, const char *, u32);
extern "C" void func_0057C808(MD5 *, unsigned char *);
extern "C" char *func_0057C8B0(const unsigned char *, char *);
extern "C" int func_0057DA20(char *, const char *, ...);

extern const char *D_00645418[];   /* request methods: "GET ", "HEAD ", "POST " */
extern const char D_006BFFB8[];    /* " HTTP/1.1\r\n" */
extern const char D_006BFFC8[];    /* "Host: " */
extern const char D_006BFFD0[];    /* "\r\n" */
extern const char D_006BFFD8[];    /* "Accept: *\/*;q=0.01\r\n" */
extern const char D_006BFFF0[];    /* "Accept-Encoding:\r\n" */
extern const char D_006C0008[];    /* "Accept-Charset: iso-8859-1;q=0.01\r\n" */
extern const char D_006C0030[];    /* "User-Agent: " */
extern const char D_006C0040[];    /* "Connection: Keep-Alive\r\n" */
extern const char D_006C0060[];    /* ":" */
extern const char D_006C0068[];    /* "Proxy-Authorization: Basic " */
extern const char D_006C0088[];    /* ": " */
extern const char D_006C0090[];    /* "Cookie: " */
extern const char D_006BFF28[];    /* "" */
extern const char D_006BFF38[];    /* "=" */
extern const char D_006BFF40[];    /* "; " */
extern const char D_006C00A0[];    /* "&" */
extern const char D_006C00A8[];    /* "http://" */
extern const char D_006C00B0[];    /* "X-SVOMac: " */
extern const char D_006C00C0[];    /* "Content-Type: application/x-www-form-urlencoded\r\n" */
extern const char D_006C00F8[];    /* "Content-Length: %d\r\n" */

/* pdistd-http: writes the request header of h into out (request line, Host, Accept, User-Agent,
 * proxy authorization, extra headers, cookies; for a POST the form parameters with their
 * X-SVOMac digest, Content-Type and Content-Length, then the body). (inferred) */
extern "C" void func_004E8F58(Http *h, Str &out) {
    Str mac(h->url.path);

    out += D_00645418[h->method] + func_004ECC98(&h->url) + D_006BFFB8;
    out += D_006BFFC8 + h->url.host + D_006BFFD0;
    out += D_006BFFD8;
    out += D_006BFFF0;
    out += D_006C0008;
    out += D_006C0030 + h->agent + D_006BFFD0;
    if (h->keepAlive)
        out += D_006C0040;
    if (h->proxyUser.length()) {
        char buf[128];
        Str cred = h->proxyUser + D_006C0060 + h->proxyPass;
        Base64 enc;
        const signed char *src = (const signed char *)cred.begin();
        buf[func_0060DD00(&enc, buf, src, cred.length())] = 0;
        out += D_006C0068;
        out += buf;
        out += D_006BFFD0;
    }
    for (CIt it = h->headers.begin(); it != h->headers.end(); it++) {
        out += it->first;
        out += D_006C0088;
        out += it->second;
        out += D_006BFFD0;
    }
    if (h->cookies.size())
        out += D_006C0090;
    for (CIt it = h->cookies.begin(); it != h->cookies.end();) {
        out += it->first;
        out += D_006BFF38;
        out += it->second;
        mac += it->first;
        mac += D_006BFF38;
        mac += it->second;
        it++;
        if (it != h->cookies.end()) {
            out += D_006BFF40;
            mac += D_006BFF40;
        }
    }
    if (h->cookies.size())
        out += D_006BFFD0;
    if (h->method == 2) {
        Str body(D_006BFF28);
        for (CLIt it = h->params.begin(); it != h->params.end();) {
            body += it->first;
            body += D_006BFF38;
            body += it->second;
            mac += it->first;
            mac += D_006BFF38;
            mac += it->second;
            it++;
            if (it != h->params.end()) {
                body += D_006C00A0;
                mac += D_006C00A0;
            }
        }
        mac += D_006C00A8;
        {
            MD5 md5;
            unsigned char digest[16];
            char hex[33];
            func_0057B850(&md5);
            func_0057C718(&md5, mac.c_str(), mac.length());
            func_0057C808(&md5, digest);
            mac = func_0057C8B0(digest, hex);
        }
        out += D_006C00B0;
        out += mac;
        out += D_006BFFD0;
        if (h->form)
            out += D_006C00C0;
        char line[32];
        func_0057DA20(line, D_006C00F8, body.length());
        out += line;
        out += D_006BFFD0;
        out += body;
    }
    out += D_006BFFD0;
}
