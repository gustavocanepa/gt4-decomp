typedef int s32;

struct Obj {
    char pad0[0xC];
    void **unkC;
    s32 unk10;
    s32 unk14;
};

extern "C" void *func_00575C00(Obj *arg0)
{
    void **a2 = arg0->unkC;
    s32 v1 = arg0->unk14;
    s32 a1 = arg0->unk10;
    void **v0 = a2;
    void *a3 = *a2;

    v1 = v1 - 1;
    a1 = a1 + 1;
    arg0->unk14 = v1;
    arg0->unkC = (void **)a3;
    arg0->unk10 = a1;

    return v0;
}
