typedef int s32;

struct Obj { char pad[0x438]; s32 unk438; };

extern "C" s32 func_0045CC50(Obj *arg0) {
    return arg0->unk438;
}
