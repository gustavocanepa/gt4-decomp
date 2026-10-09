extern "C" void CameraBase__structor_1(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *SceneCameraBase__vtable;

extern "C" void SceneCameraBase__structor_3(void *arg0, int arg1) {
    *(void **)arg0 = &SceneCameraBase__vtable;
    CameraBase__structor_1(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
