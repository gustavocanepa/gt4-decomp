typedef int s32;

struct S { char pad[0xC]; s32 unkC; };

extern "C" void CameraSys__CameraManager__initReplayMode(S *arg0, s32 arg1) {
    arg0->unkC = arg1;
}
