/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

extern char D_008744D0[];

extern "C" s32 func_00575D00(void);
extern "C" void *func_005725A8(void *heap, s32 size, s32 align);

extern "C" void *func_00575DF0(s32 n) {
    return func_005725A8(D_008744D0, func_00575D00() - n, 0x10);
}
