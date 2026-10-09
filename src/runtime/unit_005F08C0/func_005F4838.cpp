typedef int s32;
typedef float f32;

struct Struct_005F4838 {
    char pad0[0x4];
    f32 unk4;
};

extern "C" s32 func_005F4838(struct Struct_005F4838 *arg0, struct Struct_005F4838 *arg1) {
    s32 var_v0;

    f32 a = arg0->unk4;
    f32 b = arg1->unk4;
    var_v0 = 1;
    if (!(b < a)) {
        var_v0 = 0;
    }
    return var_v0;
}
