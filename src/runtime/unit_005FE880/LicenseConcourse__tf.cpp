typedef unsigned int u32;

extern "C" void Concourse__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A44A8[];
extern int D_0088FA70;

extern int D_0088FA60;

extern "C" void *LicenseConcourse__tf(void) {
    if (D_0088FA60 == 0) {
        Concourse__tf();
        func_005BFB68(&D_0088FA60, D_006A44A8, &D_0088FA70);
    }
    return &D_0088FA60;
}
