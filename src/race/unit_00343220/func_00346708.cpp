typedef int s32;

extern s32 D_0062023C;
extern "C" void *func_003466B8(void *);
extern "C" void *memcpy(void *, const void *, unsigned int);

extern "C" void func_00346708(void *dst, void *src) {
    void *d = func_003466B8(dst);
    memcpy(d, func_003466B8(src), D_0062023C);
}
