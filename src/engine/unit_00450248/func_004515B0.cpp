typedef int s32;

struct Obj { char pad[0x80]; s32 unk80; };

extern "C" s32 func_004515B0(Obj *arg0) {
    return arg0->unk80 == 0;
}
