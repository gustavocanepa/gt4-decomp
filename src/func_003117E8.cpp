typedef int s32;

extern "C" s32 func_00309360(void *arg0, s32 arg1);
extern "C" void *func_00323C10(void *arg0);
extern char D_006751E8[];

extern "C" s32 func_003117E8(void *arg0, s32 arg1, s32 arg2) {
    func_00323C10(arg0);
    *(void **)((char *)arg0 + 0x4) = D_006751E8;
    return func_00309360((char *)arg0 + 0xC, arg2);
}
