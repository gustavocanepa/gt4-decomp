typedef int s32;

struct Obj0 {
    char pad[4];
    s32 unk4;
    s32 unk8;
};

struct Obj1 {
    s32 unk0;
    char pad[4];
    s32 unk8;
};

extern "C" void func_0045B740(Obj0 *arg0, Obj1 *arg1) {
    s32 v = arg0->unk4;
    if (v >= 0) {
        arg1->unk8 = arg1->unk0 + (v + arg0->unk8);
    }
}
