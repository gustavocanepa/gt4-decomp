typedef int s32;
typedef unsigned char u8;

struct Obj {
    char pad[0xA68];
    s32 unkA68;
    char pad2[0xA6C - 0xA68 - 4];
    u8 unkA6C;
    char pad3[0xBAC - 0xA6C - 1];
    s32 unkBAC;
    u8 unkBB0;
};

extern "C" void func_0042FB48(Obj *arg0) {
    arg0->unkBB0 = 0;
    arg0->unkA68 = 0;
    arg0->unkA6C = 0;
    arg0->unkBAC = -1;
}
