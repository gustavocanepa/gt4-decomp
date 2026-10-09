typedef int s32;
typedef float f32;

struct Inner {
    char pad[0x230];
    f32 unk230;
};

struct Obj {
    char pad[0x10];
    Inner *unk10;
};

extern "C" s32 func_003F3790(Obj *arg0) {
    s32 var_v1 = 1;
    if (arg0->unk10->unk230 == 0.0f) {
        var_v1 = 0;
    }
    return var_v1;
}
