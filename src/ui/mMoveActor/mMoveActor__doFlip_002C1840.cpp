typedef int s32;

struct S { char pad[0x54]; s32 unk54; };

extern "C" void mMoveActor__doFlip(S *arg0) {
    arg0->unk54 = arg0->unk54 ^ 1;
}
