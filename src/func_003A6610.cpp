typedef unsigned char u8;
typedef int s32;
typedef float f32;

struct Obj {
    u8 unk0;
    char pad[0x27];
    f32 unk28;
};

extern "C" s32 func_003A6610(Obj *arg0) {
    s32 var_v1 = 0;
    if (arg0->unk0 != 0 && arg0->unk28 >= 0.0f) {
        var_v1 = 1;
    }
    return var_v1;
}
