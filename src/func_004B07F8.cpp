extern "C" void func_004B06D0(void *);
extern "C" void func_00578908(void *);
extern void *D_006318C0;
extern void *D_006318C4;
extern char D_006318D0[];

static inline void release(void **p)
{
    if (*p) {
        func_00578908(*p);
        *p = 0;
    }
}

extern "C" void func_004B07F8(void)
{
    func_004B06D0(D_006318D0);
    release(&D_006318C0);
    release(&D_006318C4);
}
