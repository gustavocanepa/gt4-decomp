/* libio (GNU iostream library, gcc 2000-10-03 snapshot): the type_info function of libio's class _IO_ostream_withassign (compiler-generated from its declaration).
 * licence: libio (GPLv2 with the libio special exception, see THIRD_PARTY.md) */
typedef int s32;

extern "C" void ostream__tf();
extern "C" void func_005BFB40(void *a0, void *a1, void *a2, s32 a3);

extern char D_006CF850[];
extern int D_006CF870;

extern int D_008A1BD0;

extern "C" void *func_00615078(void) {
    if (D_008A1BD0 == 0) {
        ostream__tf();
        func_005BFB40(&D_008A1BD0, D_006CF850, &D_006CF870, 1);
    }
    return &D_008A1BD0;
}
