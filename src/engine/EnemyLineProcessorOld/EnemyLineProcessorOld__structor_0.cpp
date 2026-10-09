typedef int s32;

struct S {
    char pad[0x4];
    s32 unk4;
    s32 unk8;
    char pad2[0x18 - 0x8 - 4];
    void *unk18;
};

extern char EnemyLineProcessorOld__vtable;

extern "C" void EnemyLineProcessorOld__structor_0(S *arg0) {
    arg0->unk8 = 0;
    arg0->unk4 = 0;
    arg0->unk18 = &EnemyLineProcessorOld__vtable;
}
