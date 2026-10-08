typedef int s32;
typedef unsigned char u8;

struct Obj {
    char pad[0x1A];
    u8 unk1A;
};

extern "C" void func_00615358(Obj *arg0, s32 arg1) {
    arg0->unk1A = (u8)(arg0->unk1A & ~arg1);
}
