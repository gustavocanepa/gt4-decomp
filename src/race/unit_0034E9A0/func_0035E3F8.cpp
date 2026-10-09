typedef int s32;
typedef unsigned char u8;

struct Obj0 {
    u8 pad0[0xDC];
    s32 unkDC;
    u8 pad1[0xEC - 0xDC - 4];
    s32 unkEC;
};

struct Obj1 {
    u8 pad0[0xCBDC];
    u8 unkCBDC;
};

extern "C" s32 func_0035E3F8(Obj0 *arg0, Obj1 *arg1) {
    if (arg1->unkCBDC != 0) {
        return 1;
    }
    if (arg0->unkEC != 0) {
        return 1;
    }
    return arg0->unkDC != 0;
}
