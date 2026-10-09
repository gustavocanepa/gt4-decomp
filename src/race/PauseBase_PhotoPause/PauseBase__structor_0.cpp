typedef int s32;

struct S {
    s32 unk0;
    s32 unk4;
    void *unk8;
};

extern char PauseBase__vtable;

void PauseBase__structor_0(struct S *arg0) {
    arg0->unk4 = 0;
    arg0->unk0 = 0;
    arg0->unk8 = &PauseBase__vtable;
}
