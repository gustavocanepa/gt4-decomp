typedef int s32;

struct Obj {
    s32 unk0;
    s32 unk4;
};

extern "C" Obj *func_0048F298(Obj *arg0, Obj *arg1) {
    arg0->unk0 = arg1->unk0;
    arg0->unk4 = arg1->unk4;
    return arg0;
}
