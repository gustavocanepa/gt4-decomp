typedef int s32;
typedef signed char s8;

struct Obj { char pad[0x24]; s8 unk24; };

extern "C" void func_0043C8E0(Obj *arg0, s32 arg1, s32 arg2) {
    if (arg1 == 0) {
        arg0->unk24 = arg2;
    }
}
