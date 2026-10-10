/* compiler: ee-gcc2.9-991111 */
typedef int s32;
typedef unsigned char u8;

struct Req { u8 type; char pad[3]; s32 m4, m8, mC, m10, m14, m18, m1C, m20, m24, m28, m2C, m30, m34, m38, m3C; };
extern "C" s32 func_005878F8(Req *, s32);

extern "C" s32 func_00587010(s32 a, s32 b, s32 c, s32 d) {
    Req r;
    if (a & 3)
        return 0x81050016;
    r.type = 1;
    r.m10 = a;
    r.m14 = b;
    r.m18 = c;
    r.m1C = d;
    r.mC = 0;
    r.m20 = 0;
    r.m24 = 0;
    return func_005878F8(&r, 0);
}
