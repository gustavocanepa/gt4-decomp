typedef int s32;

struct Obj {
    s32 unk0;
    s32 unk4;
};

extern "C" void func_0048F280(Obj *arg0, Obj *arg1) {
    arg0->unk0 = arg1->unk0;
    arg0->unk4 = arg1->unk4;
}
