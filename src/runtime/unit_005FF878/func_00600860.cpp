typedef int s32;

struct S {
    s32 unk0;
    void *unk4;
    s32 unk8;
};

extern char D_006877A0;

void func_00600860(struct S *arg0) {
    arg0->unk8 = 0;
    arg0->unk0 = 0;
    arg0->unk4 = &D_006877A0;
}
