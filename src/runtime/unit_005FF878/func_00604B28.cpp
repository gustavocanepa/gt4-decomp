typedef unsigned int u32;

extern "C" void func_005CA498();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_006D5E50;

extern int D_0088FE70;

extern "C" void *func_00604B28(void) {
    if (D_0088FE70 == 0) {
        func_005CA498();
        func_005BFB68(&D_0088FE70, ((char *)"Q28GT4Model23ShowRoomCarParamSponsor"), &D_006D5E50);
    }
    return &D_0088FE70;
}
