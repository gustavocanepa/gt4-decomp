extern "C" void func_00387EF0(void *arg0, int arg1, int arg2);
extern "C" void func_0012BFC0(void *arg0);
extern "C" void func_0012BFD0(int arg0);
extern "C" void func_0010FE40(const char *arg0);

struct VEntry {
    short delta;
    short pad;
    void (*fn)(void *);
};

struct func_00119890_arg0 {
    char pad0[0x64];
    void *unk64;
    char pad68[0xCE0];
    int unkD48;
};

extern "C" void func_00119890(void *arg0) {
    *(int *)((char *)*(void **)((char *)arg0 + 0x6C) + 0xDC) = 1;
    ((struct func_00119890_arg0 *)arg0)->unkD48 = 1;
    func_00387EF0(arg0, 4, 1);
    func_0012BFC0(arg0);
    func_0012BFD0(1);
    func_0010FE40("quick-practice");
    func_0012BFC0(0);

    void *vtbl = ((struct func_00119890_arg0 *)arg0)->unk64;
    VEntry *entry = (VEntry *)((char *)vtbl + 0x2C0);
    entry->fn((char *)arg0 + entry->delta);

    ((struct func_00119890_arg0 *)arg0)->unkD48 = 0;
    *(int *)((char *)*(void **)((char *)arg0 + 0x6C) + 0xDC) = 0;
}
