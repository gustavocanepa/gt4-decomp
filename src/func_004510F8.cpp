typedef int s32;

struct Obj {
    char pad[0x34];
    s32 unk34;
};

extern "C" s32 func_004510F8(Obj **arg0) {
    s32 var_v0;
    Obj *temp_a0;

    temp_a0 = *arg0;
    var_v0 = 0;
    if (temp_a0 != 0) {
        var_v0 = temp_a0->unk34;
    }
    return var_v0;
}
