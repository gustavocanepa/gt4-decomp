/* compiler: ee-gcc2.9-991111 */
typedef int s32;
typedef unsigned char u8;

struct Req {
    u8 type;
    char pad1[3];
    s32 a;
    s32 pad8;
    s32 b;
    char pad10[0x10];
    s32 c;
    s32 d;
    s32 e;
    char pad2c[0x14];
};

extern "C" s32 func_005878F8(Req *, s32);

extern "C" s32 func_00587220(s32 a, s32 b, s32 c, s32 d, s32 e) {
    Req r;
    r.type = 4;
    r.a = a;
    r.b = b;
    r.c = c;
    r.d = d;
    r.e = e;
    return func_005878F8(&r, 0);
}
