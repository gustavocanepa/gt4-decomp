typedef int s32;

struct Obj {
    s32 unk0;
    s32 unk4;
};

extern "C" void func_004CF370(Obj *arg0, s32 arg1) {
    s32 a = arg0->unk0;
    s32 b = arg0->unk4;
    if (b == a) {
        arg0->unk4 = arg1;
    }
    arg0->unk0 = arg1;
}
