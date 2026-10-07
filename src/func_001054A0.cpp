typedef int s32;

struct Obj {
    char pad0[0x28];
    s32 unk28;
    char pad1[0x38 - 0x28 - 4];
    s32 unk38;
};

extern "C" void func_001054A0(Obj *arg0, s32 arg1) {
    s32 var_v1;

    arg0->unk28 = arg1;
    var_v1 = 0;
    if (arg1 != 0) {
        var_v1 = arg1 != 9;
    }
    arg0->unk38 = var_v1;
}
