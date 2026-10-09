typedef int s32;

struct Obj { char pad[0xC0]; s32 unkC0; };

extern "C" s32 func_00238F58(Obj *arg0) {
    return arg0->unkC0;
}
