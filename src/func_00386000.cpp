typedef int s32;

struct Obj { char pad[0xC]; s32 unkC; };

extern "C" void func_00386000(Obj **arg0, s32 arg1) {
    (*arg0)->unkC = arg1;
}
