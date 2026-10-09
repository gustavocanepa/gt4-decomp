typedef unsigned int u32;

extern "C" void func_00607408();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_006D6170;

extern int D_0088FEB0;

extern "C" void *func_00608F30(void) {
    if (D_0088FEB0 == 0) {
        func_00607408();
        func_005BFB68(&D_0088FEB0, ((char *)"Q26strobe14SpriteInstance"), &D_006D6170);
    }
    return &D_0088FEB0;
}
