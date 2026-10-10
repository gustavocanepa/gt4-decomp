/* compiler: ee-gcc2.9-991111 */
typedef int s32;
typedef unsigned char u8;

struct Req { u8 type; char pad[3]; s32 m4, m8, mC, m10, m14, m18, m1C, m20, m24, m28, m2C, m30, m34, m38, m3C; };
extern "C" s32 func_005878F8(Req *, s32);

extern "C" s32 func_00587260(s32 a, s32 b, s32 c, s32 d, s32 e) {
    Req r;
    r.type = 4;
    r.m4 = a;
    r.mC = b;
    r.m20 = c;
    r.m24 = d;
    r.m28 = e;
    return func_005878F8(&r, 1);
}
