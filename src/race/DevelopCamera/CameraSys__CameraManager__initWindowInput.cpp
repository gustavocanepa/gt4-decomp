typedef int s32;

extern "C" void CameraSys__CameraControl__init(s32 arg0, s32 arg1, s32 arg2);

extern "C" void CameraSys__CameraManager__initWindowInput(s32 arg0, s32 arg1, s32 arg2) {
    s32 k = 0x19C;
    CameraSys__CameraControl__init(arg0 + arg1 * k + 0xE0, arg2, 1);
}
