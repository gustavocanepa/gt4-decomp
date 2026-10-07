typedef int s32;

extern "C" s32 func_002F41F8(void *arg0, s32 arg1);
extern "C" void *func_00303950(void *arg0);
extern char D_00675158[];

extern "C" s32 func_00310F20(void *arg0, s32 arg1, s32 arg2) {
    func_00303950(arg0);
    *(void **)((char *)arg0 + 0x4) = D_00675158;
    return func_002F41F8((char *)arg0 + 0xC, arg2);
}
