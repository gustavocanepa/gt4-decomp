typedef int s32;

struct S_005FE1C8 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    void *unkC;
};

extern "C" char RaceResultBase__vtable[];

extern "C" void RaceResultBase__structor_1(struct S_005FE1C8 *arg0) {
    arg0->unk0 = 0;
    arg0->unk4 = 0;
    arg0->unkC = RaceResultBase__vtable;
    arg0->unk8 = 0;
}
