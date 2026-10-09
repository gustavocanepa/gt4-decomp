extern "C" void func_005BFB88(void *a0, void *a1);


extern int D_006D5E20;

extern "C" void *RefPointer__tf(void) {
    if (D_006D5E20 == 0) {
        func_005BFB88(&D_006D5E20, ((char *)"10RefPointer"));
    }
    return &D_006D5E20;
}
