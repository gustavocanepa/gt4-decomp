typedef int s32;

extern "C" char D_008744D0[];
extern "C" s32 func_005725A8(void *arg0, s32 arg1, s32 arg2);

extern "C" s32 malloc(s32 arg0) {
    return func_005725A8(D_008744D0, arg0, 0x10);
}
