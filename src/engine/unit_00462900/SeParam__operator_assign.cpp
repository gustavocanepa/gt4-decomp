typedef int s32;

struct Obj {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
};

extern "C" Obj *SeParam__operator_assign(Obj *arg0, Obj *arg1) {
    arg0->unk0 = arg1->unk0;
    arg0->unk4 = arg1->unk4;
    arg0->unk8 = arg1->unk8;
    arg0->unkC = arg1->unkC;
    return arg0;
}
