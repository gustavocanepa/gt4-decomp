typedef unsigned int u32;

extern "C" void type_info__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_006D6300;

extern int D_008A2130;

extern "C" void *__builtin_type_info__tf(void) {
    if (D_008A2130 == 0) {
        type_info__tf();
        func_005BFB68(&D_008A2130, ((char *)"19__builtin_type_info"), &D_006D6300);
    }
    return &D_008A2130;
}
