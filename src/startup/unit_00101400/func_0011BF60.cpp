extern "C" void func_00387EF0(void *arg0, int arg1, int arg2);
extern "C" void func_0012BFC0(void *arg0);
extern "C" void func_0012BFD0(int arg0);
extern "C" void func_0010FE40(const char *arg0);

struct VEntry {
    short delta;
    short pad;
    void (*fn)(void *);
};

struct func_0011BF60_arg0 {
    char pad0[0x64];
    void *unk64;
    char pad68[0x4];
    void *unk6C;
    char pad70[0xCD8];
    int unkD48;
};
struct func_0011BF60_s1 {
    char pad0[0xDC];
    int unkDC;
};

extern "C" void func_0011BF60(void *arg0) {
    void *s1 = ((struct func_0011BF60_arg0 *)arg0)->unk6C;
    ((struct func_0011BF60_s1 *)s1)->unkDC = 1;
    ((struct func_0011BF60_arg0 *)arg0)->unkD48 = 1;
    func_00387EF0(arg0, 4, 1);
    func_0012BFC0(arg0);
    func_0012BFD0(1);
    func_0010FE40("quick-mt");
    func_0012BFC0(0);

    void *vtbl = ((struct func_0011BF60_arg0 *)arg0)->unk64;
    VEntry *entry = (VEntry *)((char *)vtbl + 0x2C0);
    entry->fn((char *)arg0 + entry->delta);

    ((struct func_0011BF60_arg0 *)arg0)->unkD48 = 0;
    ((struct func_0011BF60_s1 *)s1)->unkDC = 0;
}
