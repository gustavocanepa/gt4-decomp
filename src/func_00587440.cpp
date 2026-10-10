/* compiler: ee-gcc2.9-991111 */
typedef int s32;
typedef unsigned char u8;

struct Req { u8 type; char pad[3]; s32 m4, m8, mC, m10, m14, m18, m1C, m20, m24, m28, m2C, m30, m34, m38, m3C; };
extern "C" s32 func_005878F8(Req *, s32);
extern "C" s32 func_0058B200(s32);
extern "C" s32 func_005B0750(const char *, ...);
extern char D_006CE7B0[];

extern "C" s32 func_00587440(s32 a, s32 b, s32 c, s32 d) {
    Req r;
    s32 x = func_0058B200((s32)__builtin_return_address(0));
    if (x >= 0 && a == x) {
        func_005B0750(D_006CE7B0);
        while (1)
            ;
    }
    r.type = 7;
    r.m4 = a;
    r.mC = 0;
    r.m20 = b;
    r.m24 = c;
    r.m28 = d;
    return func_005878F8(&r, 0);
}
