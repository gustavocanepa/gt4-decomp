typedef int s32;

struct Obj { char pad[0xE8]; s32 unkE8; };

extern "C" s32 func_00233DA8(Obj *arg0) {
    return arg0->unkE8 & 1;
}
