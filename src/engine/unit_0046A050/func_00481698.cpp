typedef unsigned char u8;
typedef int s32;

struct Cursor {
    u8 *ptr;
};

extern "C" s32 func_00481698(Cursor *arg0) {
    u8 *p = arg0->ptr;
    s32 lo = p[0];
    s32 hi = p[1];
    arg0->ptr = p + 2;
    return (lo + (hi << 8)) & 0xFFFF;
}
