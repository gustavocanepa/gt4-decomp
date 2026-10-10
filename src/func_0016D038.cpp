typedef int s32;

extern "C" void func_005A6AB0(void *arg0, void *arg1, s32 arg2);
extern "C" char D_00690A10[];

extern "C" void func_0016D038(void *arg0, void **arg1) {
    void *obj = *arg1;
    s32 off = *(s32 *)((char *)obj - 0x10);
    void *a1v;
    if (off == 0) {
        a1v = D_00690A10;
    } else {
        char *p = (char *)obj + off;
        *p = 0;
        a1v = *arg1;
    }
    func_005A6AB0((char *)arg0 + 0x10, a1v, 0x20);
}
