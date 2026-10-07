typedef int s32;

extern "C" void func_001CBDC8(void *arg0, s32 arg1);

extern "C" void func_001CBEB0(void *arg0) {
    volatile char pad[16];
    (void)pad;
    func_001CBDC8((char *)arg0 + 0xD, 7);
}
