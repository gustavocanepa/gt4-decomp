typedef float f32;

struct Inner {
    char pad[0x10];
    f32 unk10;
    f32 unk14;
};

struct Obj {
    char pad[0x8];
    Inner *unk8;
};

extern "C" void func_003FF198(Obj *arg0, f32 *arg1, f32 *arg2) {
    Inner *temp = arg0->unk8;
    *arg1 = temp->unk10;
    *arg2 = temp->unk14;
}
