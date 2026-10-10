typedef int s32;

extern "C" void CameraSys__CameraControl__init(void *arg0, void *arg1, s32 arg2);

extern "C" void RacePhotoModeCameraManager__virtual_57(void *arg0, void *arg1) {
    CameraSys__CameraControl__init((char *)arg0 + 0xDD0, arg1, 1);
}
