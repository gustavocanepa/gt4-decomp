typedef unsigned int u32;

extern "C" void func_006124D8();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A4B38[];
extern int D_006D6278;

extern int D_0088FB10;

extern "C" void *func_005FFE18(void) {
    if (D_0088FB10 == 0) {
        func_006124D8();
        func_005BFB68(&D_0088FB10, D_006A4B38, &D_006D6278);
    }
    return &D_0088FB10;
}
