typedef int s32;

struct Obj {
    s32 unk0;
    void *unk4;
    s32 unk8;
    s32 unkC;
};

extern "C" char D_0068A228[];

extern "C" void func_00616830(Obj *arg0, s32 arg1, s32 arg2, s32 arg3) {
    arg0->unkC = arg3;
    arg0->unk0 = arg1;
    arg0->unk8 = arg2;
    arg0->unk4 = D_0068A228;
}
