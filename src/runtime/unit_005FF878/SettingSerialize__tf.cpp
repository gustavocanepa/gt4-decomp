typedef unsigned int u32;

extern "C" void func_00603BE8();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_006D60F8;

extern int D_0088FE30;

extern "C" void *SettingSerialize__tf(void) {
    if (D_0088FE30 == 0) {
        func_00603BE8();
        func_005BFB68(&D_0088FE30, ((char *)"16SettingSerialize"), &D_006D60F8);
    }
    return &D_0088FE30;
}
