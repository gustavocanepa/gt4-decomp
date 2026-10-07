typedef int s32;

struct Obj552AC8 {
    char pad[0x108];
    s32 unk108;
    s32 unk10C;
};

extern "C" void func_00552AC8(Obj552AC8 *arg0, s32 arg1, s32 arg2) {
    arg0->unk108 = arg1;
    arg0->unk10C = arg2;
}
