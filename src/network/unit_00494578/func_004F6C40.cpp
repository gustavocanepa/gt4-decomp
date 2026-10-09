typedef int s32;

struct Arg {
    s32 a[6];
    s32 result;
};

struct S004F87E8 {
    char pad[0x5A8];
};

extern S004F87E8 D_00645570;
extern char D_006C0750[];

extern "C" void func_004F0B08(S004F87E8 *arg0, Arg *arg1);
extern "C" s32 func_004F0C38(S004F87E8 *arg0, const char *arg1);
extern "C" void func_004F87E8(struct S004F87E8 *arg0, s32 arg1);

struct Guard {
    S004F87E8 *conn;
    Arg *arg;
    Guard(S004F87E8 *c, Arg *a) : conn(c), arg(a) {}
    ~Guard() { func_004F0B08(conn, arg); }
};

extern "C" void func_004F6C40(Arg *arg, S004F87E8 *conn) {
    if (conn == 0) {
        conn = &D_00645570;
    }
    Guard g(conn, arg);
    if (func_004F0C38(conn, D_006C0750) != 0) {
        return;
    }
    {
        s32 r = arg->result;
        bool done = false;
        if (r < 0 || r == 1) {
            func_004F87E8(conn, r);
            done = true;
        }
        if (done) {
            return;
        }
    }
    func_004F87E8(conn, arg->result);
}
