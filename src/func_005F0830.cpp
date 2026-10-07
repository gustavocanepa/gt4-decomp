typedef unsigned int u32;

extern "C" void func_005F1A58();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069E530[];
extern int D_006D5F40;

extern int D_0088EC80;

extern "C" void *func_005F0830(void) {
    if (D_0088EC80 == 0) {
        func_005F1A58();
        func_005BFB68(&D_0088EC80, D_0069E530, &D_006D5F40);
    }
    return &D_0088EC80;
}
