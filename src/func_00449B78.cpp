typedef int s32;

extern char D_00688308;

struct Obj {
    s32 unk0;
    s32 unk4;
    void *unk8;
};

extern "C" void func_00449B78(Obj *arg0) {
    arg0->unk4 = -1;
    arg0->unk8 = &D_00688308;
    arg0->unk0 = 0;
}
