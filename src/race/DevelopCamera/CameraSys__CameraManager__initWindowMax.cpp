typedef int s32;

struct S { char pad[0x9B8]; s32 unk9B8; };

extern "C" void CameraSys__CameraManager__initWindowMax(S *arg0, s32 arg1) {
    arg0->unk9B8 = arg1;
}
