/* compiler: ee-gcc2.9-991111 */
typedef int s32;

extern "C" s32 func_005B0DF0(s32, s32, s32, s32, s32, s32);

extern "C" s32 func_005B16C0(s32 a, s32 b, s32 c, s32 d) {
    if (func_005B0DF0(0x80000008, d, 0x40, 0, 0, 0) != 0)
        return 0;
    return 0x800;
}
