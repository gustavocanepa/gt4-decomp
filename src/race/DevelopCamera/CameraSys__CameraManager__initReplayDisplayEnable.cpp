typedef int s32;

struct S { char pad[0x8]; s32 unk8; };

extern "C" void CameraSys__CameraManager__initReplayDisplayEnable(S *arg0, s32 arg1) {
    arg0->unk8 = arg1;
}
