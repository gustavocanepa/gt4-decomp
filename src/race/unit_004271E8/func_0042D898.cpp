typedef int s32;

struct Obj {
    s32 unk0;
    char pad4[4];
    s32 unk8;
};

extern "C" void func_0042D898(struct Obj *arg0, s32 arg1) {
    s32 v1 = arg0->unk0;
    s32 a2 = arg0->unk8;
    s32 v0 = v1 + arg1;
    s32 a1 = a2 + arg1;
    if (v1 == 0) v0 = 0;
    if (a2 == 0) a1 = 0;
    arg0->unk0 = v0;
    arg0->unk8 = a1;
}
