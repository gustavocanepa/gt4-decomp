typedef int s32;

struct Obj { char pad[0xB4]; s32 unkB4; };

extern "C" s32 func_00293B30(Obj *arg0) {
    return (arg0->unkB4 >> 2) & 1;
}
