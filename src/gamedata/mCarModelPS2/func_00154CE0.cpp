typedef int s32;

struct Obj {
    char pad[0x4];
    s32 unk4;
    s32 unk8;
};

extern "C" void func_00154CE0(Obj *arg0, Obj *arg1) {
    arg0->unk8 = arg1->unk8;
    arg0->unk4 = arg1->unk4;
}
