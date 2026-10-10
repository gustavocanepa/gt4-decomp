typedef int s32;

struct S { char pad[0x20]; s32 unk20; };

extern "C" s32 GTSOUNDINSTRUMENTJAM__getJam(S *arg0) {
    return arg0->unk20;
}
