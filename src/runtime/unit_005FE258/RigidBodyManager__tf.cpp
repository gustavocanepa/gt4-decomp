extern "C" void func_005BFB88(void *a0, void *a1);

extern char D_006A39E0[];

extern int D_006D6058;

extern "C" void *RigidBodyManager__tf(void) {
    if (D_006D6058 == 0) {
        func_005BFB88(&D_006D6058, D_006A39E0);
    }
    return &D_006D6058;
}
