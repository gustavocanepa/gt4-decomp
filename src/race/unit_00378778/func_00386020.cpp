typedef int s32;

struct Obj { char pad[0x14]; s32 unk14; };

extern "C" void func_00386020(Obj **arg0, s32 arg1) {
    (*arg0)->unk14 = arg1;
}
