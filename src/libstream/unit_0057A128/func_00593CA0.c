/* compiler: ee-gcc2.96-no-strict-aliasing */
/* libio (GNU iostream library, gcc 2000-10-03 snapshot): streambuf::vscan.
 * licence: libio (GPLv2 with the libio special exception, see THIRD_PARTY.md) */
typedef int s32;
typedef unsigned char u8;

struct Out {
    char pad0[0x1A];
    u8 flags;
};

extern s32 func_005956A0(s32 a, s32 b, s32 c, s32 *flags);

s32 func_00593CA0(s32 a, s32 b, s32 c, struct Out *out) {
    s32 flags = 0;
    s32 r = func_005956A0(a, b, c, &flags);
    s32 f = flags;
    if (out) {
        out->flags |= f;
    }
    return r;
}
