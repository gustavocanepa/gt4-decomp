typedef int s32;

struct S { char pad[0x18]; s32 unk18; };

extern "C" void RaceDisplay__setExternalStartLogo(S *arg0, s32 arg1) {
    arg0->unk18 = arg1;
}
