typedef int s32;
typedef unsigned short u16;

struct Obj {
    char pad[0x2E];
    u16 unk2E;
};

extern "C" s32 func_00428AB8(Obj **arg0) {
    s32 var_v0;
    Obj *temp_a0;

    temp_a0 = *arg0;
    var_v0 = 0;
    if (temp_a0 != 0) {
        var_v0 = temp_a0->unk2E << 6;
    }
    return var_v0;
}
