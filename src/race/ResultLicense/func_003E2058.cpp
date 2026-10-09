typedef float f32;

struct Obj {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
};

extern "C" void func_003E2058(Obj *arg0, f32 fparg0) {
    f32 temp_f1 = arg0->unk0;

    arg0->unk0 = temp_f1 + (((arg0->unk4 - temp_f1) * arg0->unk8 + arg0->unkC) * fparg0);
}
