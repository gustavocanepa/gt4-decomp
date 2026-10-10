/* compiler: ee-gcc2.96-no-strict-aliasing */
/* libio (GNU iostream library, gcc 2000-10-03 snapshot): func_00596EB0.
 * licence: libio (GPLv2 with the libio special exception, see THIRD_PARTY.md) */
typedef int s32;
typedef unsigned char u8;

extern s32 func_005950A8(void *fp, s32 c);

s32 func_00596EB0(s32 c, void *fp) {
    if (c == -1) {
        return -1;
    }
    return func_005950A8(fp, (u8)c);
}
