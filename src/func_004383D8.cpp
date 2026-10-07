typedef int s32;

struct Obj {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    void *unkC;
};

extern "C" char D_00687C60[];

extern "C" void func_004383D8(struct Obj *arg0, s32 arg1, s32 arg2, s32 arg3) {
    arg0->unk0 = arg1;
    arg0->unkC = D_00687C60;
    arg0->unk4 = arg2;
    arg0->unk8 = arg3;
}
