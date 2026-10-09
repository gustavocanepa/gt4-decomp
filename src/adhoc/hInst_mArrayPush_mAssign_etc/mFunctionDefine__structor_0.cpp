typedef int s32;

extern "C" s32 func_002F41F8(void *arg0, s32 arg1);
extern "C" void *mDefine__structor_0(void *arg0);
extern char mFunctionDefine__vtable[];

extern "C" s32 mFunctionDefine__structor_0(void *arg0, s32 arg1, s32 arg2) {
    mDefine__structor_0(arg0);
    *(void **)((char *)arg0 + 0x4) = mFunctionDefine__vtable;
    return func_002F41F8((char *)arg0 + 0xC, arg2);
}
