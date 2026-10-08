typedef int s32;
typedef unsigned int u32;

struct Obj {
    s32 unk0;
    s32 unk4;
    u32 unk8;
    s32 unkC;
    s32 unk10;
};

extern "C" void func_003BAB90(Obj *arg0) {
    u32 v1 = arg0->unk8;
    v1 = v1 & 0xFFFFFF00;
    v1 = v1 & 0xFFFF00FF;

    arg0->unk10 = -1;
    arg0->unk4 = 0;
    arg0->unk8 = v1;
    arg0->unkC = 0;
    arg0->unk0 = 0;
}
