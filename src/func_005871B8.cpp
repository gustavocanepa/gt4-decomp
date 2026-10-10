/* compiler: ee-gcc2.9-991111 */
typedef int s32;
typedef unsigned char u8;

struct Req { u8 type; char pad[3]; s32 m4, m8, mC, m10, m14, m18, m1C, m20, m24, m28, m2C, m30, m34, m38, m3C; };
extern "C" s32 func_005878F8(Req *, s32);

extern "C" s32 func_005871B8(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h) {
    Req r;
    if (a & 3)
        return 0x81050016;
    r.type = 3;
    r.mC = e;
    r.m10 = a;
    r.m14 = b;
    r.m18 = c;
    r.m1C = d;
    r.m20 = f;
    r.m24 = g;
    r.m28 = h;
    return func_005878F8(&r, 1);
}
