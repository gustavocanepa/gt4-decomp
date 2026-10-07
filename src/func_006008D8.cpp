typedef int s32;

struct S {
    s32 unk0;
    void *unk4;
    s32 unk8;
};

extern char D_00687678;

void func_006008D8(struct S *arg0) {
    arg0->unk8 = 0;
    arg0->unk0 = 0;
    arg0->unk4 = &D_00687678;
}
