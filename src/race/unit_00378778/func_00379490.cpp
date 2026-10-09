typedef float f32;

struct Obj {
    char pad[0x8];
    f32 unk8;
    char pad2[0x74 - 0x8 - 4];
    f32 unk74;
};

extern "C" f32 func_00379490(Obj *arg0, f32 fparg0) {
    f32 temp_f1 = arg0->unk8;
    return temp_f1 + ((arg0->unk74 - temp_f1) * fparg0);
}
