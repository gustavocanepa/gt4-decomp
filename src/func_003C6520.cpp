typedef int s32;

struct S {
    s32 unk0;
    s32 unk4;
    void *unk8;
};

extern char D_00681BD0;

void func_003C6520(struct S *arg0) {
    arg0->unk4 = 0;
    arg0->unk0 = 0;
    arg0->unk8 = &D_00681BD0;
}
