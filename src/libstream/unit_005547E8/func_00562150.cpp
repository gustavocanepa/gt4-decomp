extern "C" void func_00576788(void *lock);
extern "C" void func_005767C0(void *lock);
extern "C" void func_00577F80(void);
extern "C" int func_0058D818(void *p);
extern "C" char D_00654D40[];

extern "C" int func_00562150(void *p)
{
    int r;
    func_00576788(D_00654D40);
    while ((r = func_0058D818(p)) < 0)
        func_00577F80();
    func_005767C0(D_00654D40);
    return r;
}
