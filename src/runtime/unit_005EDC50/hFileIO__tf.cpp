typedef unsigned int u32;

extern "C" void hIO__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_0088EAE0;

extern int D_0088EA80;

extern "C" void *hFileIO__tf(void) {
    if (D_0088EA80 == 0) {
        hIO__tf();
        func_005BFB68(&D_0088EA80, ((char *)"7hFileIO"), &D_0088EAE0);
    }
    return &D_0088EA80;
}
