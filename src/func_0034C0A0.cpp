typedef int s32;
typedef short s16;
typedef unsigned char u8;

struct Obj0034C0A0 {
    char pad0[0xCBDC];
    u8 unkCBDC;
    char pad1[0xCBF4 - 0xCBDC - 1];
    s16 unkCBF4;
};

extern "C" void func_0034C0A0(struct Obj0034C0A0 *arg0, s32 arg1) {
    if (arg0->unkCBDC == 4) {
        arg0->unkCBF4 = (s16)(arg1 * 0x3C + 1);
    }
}
