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

extern "C" s32 func_00587400(s32 a) {
    Req r;
    r.type = 6;
    r.a = a;
    r.b = 0;
    r.c = 0;
    r.d = 0;
    r.e = 0;
    return func_005878F8(&r, 1);
}
