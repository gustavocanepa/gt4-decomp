typedef int s32;

extern "C" s32 func_004F04C8(void *arg0, s32 arg1, s32 arg2);

extern char D_00645570[];

extern "C" s32 func_001F1030(s32 arg0, s32 arg1)
{
    func_004F04C8(D_00645570, arg1, 1);
    return 1;
}
