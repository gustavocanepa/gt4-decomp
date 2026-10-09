typedef int s32;

struct Obj {
    char pad[0x10];
    s32 unk10;
};

extern "C" s32 func_00450FB0(Obj **arg0) {
    s32 var_v0;
    Obj *temp_a0;

    temp_a0 = *arg0;
    var_v0 = 0;
    if (temp_a0 != 0) {
        var_v0 = temp_a0->unk10;
    }
    return var_v0;
}
