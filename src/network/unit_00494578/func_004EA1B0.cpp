/* compiler: ee-gcc2.96-no-strict-aliasing */
/* pdistd-http: send the request with retries (built into a string of the second basic_string<char>
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

extern char D_006BFF30[]; /* "" */

struct String2 {
    char *dat;
    char pad[0xC];
    Rep2 *rep() const { return (Rep2 *)dat - 1; }
    String2() : dat(D_00659E20.grab()) {}
    ~String2() { rep()->release(); }
    u32 length() const { return rep()->len; }
    char *data() const { return rep()->data(); }
    void terminate() const { (*rep())[length()] = 0; }
    const char *c_str() const {
        if (length() == 0)
            return D_006BFF30;
        terminate();
        return data();
    }
};

extern "C" void func_004E8F58(void *, String2 *);
extern "C" int func_004E8608(void *);
extern "C" int func_00520EB0(int, const char *, u32, int *);
extern "C" void func_00520E60(int);

struct Http {
    char pad[0x20];
    void (*retry)(void *);
    void *retry_data;
    int retries;
    char pad2C[0xC];
    int socket;
    char pad3C[0xC];
    int error;
};

extern "C" int func_004EA1B0(Http *h) {
    String2 request;
    int i;

    func_004E8F58(h, &request);
    i = 0;
    if (h->retries > 0) {
        do {
            int sent = 0;
            if (func_004E8608(h)) {
                h->error = func_00520EB0(h->socket, request.dat, request.length(), &sent);
                if (h->error == 0) {
                    break;
                }
                func_00520E60(h->socket);
                h->socket = 0;
                if (h->retry) {
                    h->retry(h->retry_data);
                }
            }
        } while (++i < h->retries);
    }
    return h->error == 0;
}
