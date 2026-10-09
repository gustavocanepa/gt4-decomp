typedef int s32;

struct Obj_002E54B8 {
    char pad0[0x3C0];
    s32 unk3C0;
    char pad1[0x3C4 - 0x3C0 - 4];
    s32 unk3C4;
};

extern "C" s32 func_002E54B8(struct Obj_002E54B8 *arg0, s32 arg1) {
    s32 var_v1;
    s32 temp_v0;
    s32 temp_a1;

    var_v1 = 0;
    if (arg0->unk3C4 != 0) {
        temp_v0 = arg0->unk3C0;
        if (temp_v0 > 0) {
            temp_a1 = temp_v0 - arg1;
            arg0->unk3C0 = temp_a1;
            if (temp_a1 <= 0) {
                arg0->unk3C0 = 0;
                arg0->unk3C4 = 0;
            }
            var_v1 = 1;
        }
    }
    return var_v1;
}
