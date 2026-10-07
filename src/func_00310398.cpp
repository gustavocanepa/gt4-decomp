typedef int s32;

extern "C" s32 func_002F41F8(void *arg0, s32 arg1);
extern "C" void *func_002FA9D0(void *arg0);
extern char D_006750C8[];

extern "C" s32 func_00310398(void *arg0, s32 arg1, s32 arg2) {
    func_002FA9D0(arg0);
    *(void **)((char *)arg0 + 0x4) = D_006750C8;
    return func_002F41F8((char *)arg0 + 0xC, arg2);
}
