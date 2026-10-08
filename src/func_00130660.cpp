typedef int s32;
typedef float f32;

struct Obj_00130660 {
    char pad0[0x40];
    f32 unk40;
};

extern "C" s32 func_00130660(Obj_00130660 *arg0, Obj_00130660 *arg1) {
    f32 temp_f1;
    f32 temp_f0;
    s32 var_v0;

    temp_f1 = arg0->unk40;
    temp_f0 = arg1->unk40;
    var_v0 = 1;
    if (!(temp_f1 < temp_f0)) {
        var_v0 = -1;
        if (!(temp_f0 < temp_f1)) {
            var_v0 = 0;
        }
    }
    return var_v0;
}
