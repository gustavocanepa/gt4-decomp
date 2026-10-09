typedef unsigned int u32;

extern "C" void func_005D0C00();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_006D5E80;

extern int D_0088DF80;

extern "C" void *func_005D2160(void) {
    if (D_0088DF80 == 0) {
        func_005D0C00();
        func_005BFB68(&D_0088DF80, ((char *)"Q25GT4MC8DeviceMC"), &D_006D5E80);
    }
    return &D_0088DF80;
}
