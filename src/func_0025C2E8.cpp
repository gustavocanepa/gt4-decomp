typedef int s32;

struct Obj { char pad[0x58]; s32 unk58; };

extern "C" s32 func_0025C2E8(Obj *arg0) {
    return arg0->unk58;
}
