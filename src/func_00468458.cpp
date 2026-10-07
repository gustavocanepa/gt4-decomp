typedef float f32;

struct Inner {
    char pad[0xFE0];
    f32 unkFE0;
};

struct Obj {
    char pad[0x10];
    Inner *unk10;
};

extern "C" f32 func_00468418(f32 arg0);

extern "C" f32 func_00468458(Obj *arg0) {
    return func_00468418(arg0->unk10->unkFE0);
}
