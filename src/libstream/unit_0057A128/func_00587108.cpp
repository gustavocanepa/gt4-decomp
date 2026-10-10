/* compiler: ee-gcc2.9-991111 */
typedef int s32;
typedef unsigned char u8;

struct Req { u8 type; char pad[3]; s32 m4, m8, mC, m10, m14, m18, m1C, m20, m24, m28, m2C, m30, m34, m38, m3C; };
extern "C" s32 func_005878F8(Req *, s32);

extern "C" s32 func_00587108(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f) {
    Req r;
    r.type = 2;
    r.mC = a;
    r.m10 = 0;
    r.m18 = b;
    r.m1C = c;
    r.m20 = d;
    r.m24 = e;
    r.m28 = f;
    return func_005878F8(&r, 1);
}
