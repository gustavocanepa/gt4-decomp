/* compiler: ee-gcc2.9-991111 */
typedef int s32;
typedef unsigned char u8;

struct Req { u8 type; char pad[3]; s32 m4, m8, mC, m10, m14, m18, m1C, m20, m24, m28, m2C, m30, m34, m38, m3C; };
extern "C" s32 func_005878F8(Req *, s32);

extern "C" void func_005873C0(s32 a) {
    Req r;
    r.type = 6;
    r.m4 = a;
    r.mC = 0;
    r.m20 = 0;
    r.m24 = 0;
    r.m28 = 0;
    func_005878F8(&r, 0);
}
