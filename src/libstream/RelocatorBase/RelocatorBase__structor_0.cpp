typedef int s32;

struct S0057A070 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    void *unk10;
};

extern "C" char RelocatorBase__vtable[];

extern "C" void RelocatorBase__structor_0(struct S0057A070 *arg0) {
    arg0->unk0 = 0;
    arg0->unk4 = 0;
    arg0->unk8 = 0;
    arg0->unk10 = RelocatorBase__vtable;
    arg0->unkC = 0;
}
