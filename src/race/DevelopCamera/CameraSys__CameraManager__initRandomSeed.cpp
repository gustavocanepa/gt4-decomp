typedef int s32;

struct S { char pad[0x4]; s32 unk4; };

extern "C" void CameraSys__CameraManager__initRandomSeed(S *arg0, s32 arg1) {
    arg0->unk4 = arg1;
}
