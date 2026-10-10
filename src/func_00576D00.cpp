typedef int s32;

extern "C" void func_00577F80(void);
extern "C" s32 func_0058B360(void *);

extern "C" void func_00576D00(void *self) {
    while (func_0058B360(self) < 0) {
        func_00577F80();
    }
}
