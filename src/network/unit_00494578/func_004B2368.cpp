typedef int s32;

extern char D_00851180;

struct Obj {
    s32 unk0;
    s32 unk4;
    s32 unk8;
};

extern "C" void func_004B2368(Obj *arg0) {
    arg0->unk4 = -1;
    arg0->unk0 = (s32)&D_00851180;
    arg0->unk8 = 0;
}
