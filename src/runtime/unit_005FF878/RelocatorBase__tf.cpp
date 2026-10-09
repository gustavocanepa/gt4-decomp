extern "C" void func_005BFB88(void *a0, void *a1);


extern int D_006D62C0;

extern "C" void *RelocatorBase__tf(void) {
    if (D_006D62C0 == 0) {
        func_005BFB88(&D_006D62C0, ((char *)"13RelocatorBase"));
    }
    return &D_006D62C0;
}
