typedef int s32;

struct Sub {
    s32 unk0;
};

struct SomeStruct {
    char pad[0x14];
    struct Sub sub;
};

extern "C" s32 func_003284E8(s32);

extern "C" s32 func_003055C8(struct SomeStruct *arg0) {
    struct Sub *s0 = &arg0->sub;
    s32 temp_v0;
    s32 var_s1;
    s32 var_v0;

    var_s1 = 0;
    temp_v0 = s0->unk0;
    if ((temp_v0 == 0) || (func_003284E8(temp_v0) == 0)) {
        var_s1 = 1;
    }
    var_v0 = 0;
    if (var_s1 == 0) {
        var_v0 = s0->unk0;
    }
    return var_v0;
}
