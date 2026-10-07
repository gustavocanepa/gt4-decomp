typedef unsigned int u32;

extern "C" void func_005F26E0();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069DE88[];
extern int D_006D5F58;

extern int D_0088EB70;

extern "C" void *func_005EFF90(void) {
    if (D_0088EB70 == 0) {
        func_005F26E0();
        func_005BFB68(&D_0088EB70, D_0069DE88, &D_006D5F58);
    }
    return &D_0088EB70;
}
