typedef int s32;

struct Obj { char pad[0x8]; s32 unk8; };

extern "C" void func_00430398(Obj *arg0, s32 arg1) {
    if (arg1 < 0x21) {
        arg0->unk8 = arg1;
    }
}
