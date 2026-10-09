typedef int s32;

struct Obj {
    s32 unk0;
    s32 unk4;
};

extern "C" void func_001C5D70(Obj *arg0) {
    arg0->unk4 = 0;
    arg0->unk0 = 1;
}
