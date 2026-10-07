typedef unsigned int u32;

extern "C" void func_005FFE18();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069F1A8[];
extern int D_0088FB10;

static int D_0088D9A0;

extern "C" void *func_005F3368(void) {
    if (D_0088D9A0 == 0) {
        func_005FFE18();
        func_005BFB68(&D_0088D9A0, D_0069F1A8, &D_0088FB10);
    }
    return &D_0088D9A0;
}
