/* compiler: ee-gcc2.96-no-strict-aliasing */
/* pdistd-http: send the request (built into a string of the second basic_string<char>
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

extern char D_006BFF48[];
extern "C" void func_004E8E48(void *, String2 *);
extern "C" void func_00574D18(const char *, ...);
extern "C" int func_00520EB0(int, const char *, u32, int *);
extern "C" void func_00520E60(int);

struct Http {
    char pad[0x34];
    int connected;
    int socket;
    char pad3C[0xC];
    int error;
};

extern "C" int func_004E8D48(Http *h) {
    int ok = 1;

    if (h->connected) {
        String2 request;
        int sent;

        func_004E8E48(h, &request);
        func_00574D18(D_006BFF48, request.c_str());
        sent = 0;
        h->error = func_00520EB0(h->socket, request.dat, request.length(), &sent);
        ok = h->error == 0;
    }
    func_00520E60(h->socket);
    h->socket = 0;
    return ok;
}
