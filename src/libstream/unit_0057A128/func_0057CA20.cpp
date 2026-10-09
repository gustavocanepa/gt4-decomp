typedef int s32;

struct S {
    s32 unk0;
    s32 unk4;
    void *unk8;
};

extern char D_00689F10;

void func_0057CA20(struct S *arg0) {
    arg0->unk4 = 0;
    arg0->unk0 = 0;
    arg0->unk8 = &D_00689F10;
}
