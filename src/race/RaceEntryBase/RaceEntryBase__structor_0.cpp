typedef int s32;

struct S003B6C10 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    char pad14[0x1C - 0x14];
    s32 unk1C;
    void *unk20;
};

extern "C" char RaceEntryBase__vtable[];

extern "C" void RaceEntryBase__structor_0(struct S003B6C10 *arg0) {
    arg0->unk1C = 0;
    arg0->unk0 = 0;
    arg0->unk4 = 0;
    arg0->unk8 = 0;
    arg0->unkC = 0;
    arg0->unk10 = 0;
    arg0->unk20 = RaceEntryBase__vtable;
}
