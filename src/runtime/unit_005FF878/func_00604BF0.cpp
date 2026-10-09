typedef unsigned int u32;

extern "C" void func_005CA498();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_006D5E50;

extern int D_0088FE80;

extern "C" void *func_00604BF0(void) {
    if (D_0088FE80 == 0) {
        func_005CA498();
        func_005BFB68(&D_0088FE80, ((char *)"Q28GT4Model23RecordedCarParamSponsor"), &D_006D5E50);
    }
    return &D_0088FE80;
}
