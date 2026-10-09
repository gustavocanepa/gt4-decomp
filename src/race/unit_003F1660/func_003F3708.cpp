typedef int s32;
typedef float f32;

struct Inner {
    f32 unk0;
    char pad[0x50 - 4];
    f32 unk50;
};

struct Obj {
    char pad[0x10];
    Inner *unk10;
};

extern "C" f32 func_003F3708(Obj *arg0) {
    Inner *temp_v0 = arg0->unk10;
    return temp_v0->unk0 + temp_v0->unk50;
}
