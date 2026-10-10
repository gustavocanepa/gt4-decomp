/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned char u8;

extern s32 func_005950A8(void *fp, s32 c);

s32 func_00596EB0(s32 c, void *fp) {
    if (c == -1) {
        return -1;
    }
    return func_005950A8(fp, (u8)c);
}
