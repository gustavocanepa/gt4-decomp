typedef unsigned int u32;

extern "C" void func_005D1E70();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_0088DF70;

extern int D_0088DF60;

extern "C" void *func_005D1FA0(void) {
    if (D_0088DF60 == 0) {
        func_005D1E70();
        func_005BFB68(&D_0088DF60, ((char *)"Q25GT4MC20FileGT4SlideShowList"), &D_0088DF70);
    }
    return &D_0088DF60;
}
