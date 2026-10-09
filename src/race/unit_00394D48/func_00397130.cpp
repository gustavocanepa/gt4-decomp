typedef int s32;
typedef unsigned char u8;

struct Obj00397130 {
    u8 pad0[0x34];
    s32 unk34;
    s32 unk38;
};

extern "C" void func_00397188(struct Obj00397130 *arg0, s32 arg1, s32 arg2);

extern "C" void func_00397130(struct Obj00397130 *arg0, s32 arg1) {
    s32 v1 = arg0->unk34;
    s32 var_a2 = 0;

    if (arg1 != 0) {
        var_a2 = arg0->unk38;
    }
    func_00397188(arg0, v1, var_a2);
}
