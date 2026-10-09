typedef unsigned int u32;

extern "C" void func_005C1F98();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_0088D960;

extern int D_0088DA40;

extern "C" void *func_005C2868(void) {
    if (D_0088DA40 == 0) {
        func_005C1F98();
        func_005BFB68(&D_0088DA40, ((char *)"Q212GranTurismo414MenuGameObject"), &D_0088D960);
    }
    return &D_0088DA40;
}
