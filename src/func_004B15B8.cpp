extern "C" int D_00634BC0;
extern "C" char D_0084E000[];
extern "C" void func_00548A20(void *buf, int size);

extern "C" void func_004B15B8(void) {
    int *done = &D_00634BC0;
    if (*done == 0) {
        func_00548A20(D_0084E000, 0x3180);
        *done = 1;
    }
}
