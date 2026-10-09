typedef int s32;
typedef short s16;
typedef signed char s8;

struct Obj {
    s32 unk0;
    s16 unk4;
    char pad6[1];
    s8 unk7;
};

extern "C" void func_00438150(Obj *arg0, s32 arg1) {
    arg0->unk0 = arg1;
    arg0->unk4 = 0;
    if (arg1 == 0) {
        arg0->unk7 = 1;
        return;
    }
    arg0->unk7 = 0;
}
