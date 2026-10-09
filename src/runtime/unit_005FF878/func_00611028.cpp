typedef unsigned int u32;

extern "C" void func_00610DE8();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_006D6248;

extern int D_008A1A60;

extern "C" void *func_00611028(void) {
    if (D_008A1A60 == 0) {
        func_00610DE8();
        func_005BFB68(&D_008A1A60, ((char *)"Q212PlayStation29laserbird"), &D_006D6248);
    }
    return &D_008A1A60;
}
