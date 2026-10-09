typedef unsigned int u32;

extern "C" void func_005D1A28();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_0088DEA0;

extern int D_0088DFA0;

extern "C" void *func_005D22D8(void) {
    if (D_0088DFA0 == 0) {
        func_005D1A28();
        func_005BFB68(&D_0088DFA0, ((char *)"Q25GT4MC17FileGT4ReplayDemo"), &D_0088DEA0);
    }
    return &D_0088DFA0;
}
