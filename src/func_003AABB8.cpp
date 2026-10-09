extern "C" void *func_003A4280(void *arg0);
extern "C" char D_0067F108[];

extern "C" void func_003AABB8(void *arg0) {
    void *s0 = arg0;
    func_003A4280(s0);
    *(int *)((char *)s0 + 0x6C) = 0;
    *(int *)((char *)s0 + 0x68) = 0;
    *(void **)((char *)s0 + 0x14) = D_0067F108;
}
