/* libio (GNU iostream library, gcc 2000-10-03 snapshot): the type_info function of libio's class ostream (compiler-generated from its declaration).
 * licence: libio (GPLv2 with the libio special exception, see THIRD_PARTY.md) */
typedef int s32;

extern "C" void func_00615148();
extern "C" void func_005BFB40(void *a0, void *a1, void *a2, s32 a3);

extern char D_006CF7D8[];
extern int D_006CF7E8;

extern int D_008A1BF0;

extern "C" void *ostream__tf(void) {
    if (D_008A1BF0 == 0) {
        func_00615148();
        func_005BFB40(&D_008A1BF0, D_006CF7D8, &D_006CF7E8, 1);
    }
    return &D_008A1BF0;
}
