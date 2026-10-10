typedef void (*Done)(void *arg, int ok, const char *msg);
struct Req {
    char pad[0x3C];
    int m3C;
    char pad2[0x48 - 0x40];
    int state;
    Done done;
    void *arg;
    char pad3[0x6C - 0x54];
    void *handle;
};
extern "C" int func_005C1D28(void *h, int abort);
extern "C" char D_00693F50[];
extern "C" char D_00693F58[];

extern "C" void func_001CA5C8(Req *r)
{
    const char *msg = 0;
    if (func_005C1D28(r->handle, r->state != 2))
        msg = D_00693F50;
    if (r->done)
        r->done(r->arg, 0, msg ? msg : D_00693F58);
    r->m3C = 0;
    r->done = 0;
}
