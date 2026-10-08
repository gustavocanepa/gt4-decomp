typedef int s32;

extern "C" void func_001C5000(void *arg0);
extern "C" s32 func_001C5250(void *arg0);

extern "C" void func_001C52E8(void *arg0) {
    void *s0 = arg0;
    func_001C5000(arg0);
    do {
    } while (func_001C5250(s0) != 0);
}
