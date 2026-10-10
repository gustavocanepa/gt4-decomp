typedef int s32;

extern "C" void func_00577F80(void);
extern "C" s32 func_005B6840(void *);

extern "C" void func_00577700(void *self) {
    while (func_005B6840(self) < 0) {
        func_00577F80();
    }
}
