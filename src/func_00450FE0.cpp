typedef int s32;

struct Inner00450FE0 {
    char pad[0x7C];
    s32 unk7C;
};

struct Mid00450FE0 {
    char pad[0x18];
    Inner00450FE0 *unk18;
};

extern "C" s32 func_00450FE0(Mid00450FE0 **arg0) {
    s32 var_v0;
    Mid00450FE0 *temp_a0;
    Inner00450FE0 *var_v1;

    temp_a0 = *arg0;
    var_v1 = 0;
    if (temp_a0 != 0) {
        var_v1 = temp_a0->unk18;
    }
    var_v0 = 0;
    if (var_v1 != 0) {
        var_v0 = var_v1->unk7C;
    }
    return var_v0;
}
