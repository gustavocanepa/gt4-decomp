typedef unsigned char u8;
typedef int s32;

struct Obj {
    char pad[0xEE];
    u8 unkEE;
    u8 unkEF;
};

extern "C" void func_002A3A18(Obj *arg0, s32 *arg1, s32 *arg2) {
    *arg1 = arg0->unkEE;
    *arg2 = arg0->unkEF;
}
