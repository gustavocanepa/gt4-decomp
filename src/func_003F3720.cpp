typedef float f32;

struct Inner {
    char pad0[4];
    f32 unk4;
    char pad[0x50 - 8];
    f32 unk50;
};

struct Obj {
    char pad[0x10];
    Inner *unk10;
};

extern "C" f32 func_003F3720(Obj *arg0) {
    Inner *temp_v0 = arg0->unk10;
    return temp_v0->unk4 - temp_v0->unk50;
}
