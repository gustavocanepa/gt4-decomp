/* libio (GNU iostream library, gcc 2000-10-03 snapshot): the type_info function of libio's class _IO_istream_withassign (compiler-generated from its declaration).
 * licence: libio (GPLv2 with the libio special exception, see THIRD_PARTY.md) */
typedef int s32;

extern "C" void func_00614570();
extern "C" void func_005BFB40(void *a0, void *a1, void *a2, s32 a3);

extern char D_006CF828[];
extern int D_006CF848;

extern int D_008A1C00;

extern "C" void *func_00614F28(void) {
    if (D_008A1C00 == 0) {
        func_00614570();
        func_005BFB40(&D_008A1C00, D_006CF828, &D_006CF848, 1);
    }
    return &D_008A1C00;
}
