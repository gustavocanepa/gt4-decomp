extern "C" void func_00387EF0(void *arg0, int arg1, int arg2);
extern "C" void func_0012BFC0(void *arg0);
extern "C" void func_0012BFD0(int arg0);
extern "C" void func_0010FE40(const char *arg0);

struct VEntry {
    short delta;
    short pad;
    void (*fn)(void *);
};

extern "C" void func_0011B248(void *arg0) {
    void *s1 = *(void **)((char *)arg0 + 0x6C);
    *(int *)((char *)s1 + 0xDC) = 1;
    *(int *)((char *)arg0 + 0xD48) = 1;
    func_00387EF0(arg0, 4, 1);
    func_0012BFC0(arg0);
    func_0012BFD0(1);
    func_0010FE40("quick-mt");
    func_0012BFC0(0);

    void *vtbl = *(void **)((char *)arg0 + 0x64);
    VEntry *entry = (VEntry *)((char *)vtbl + 0x2C0);
    entry->fn((char *)arg0 + entry->delta);

    *(int *)((char *)arg0 + 0xD48) = 0;
    *(int *)((char *)s1 + 0xDC) = 0;
}
