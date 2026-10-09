extern "C" void SceneCameraBase__structor_0(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *DevelopCamera__vtable;

extern "C" void DevelopCamera__structor_2(void *arg0, int arg1) {
    *(void **)arg0 = &DevelopCamera__vtable;
    SceneCameraBase__structor_0(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
