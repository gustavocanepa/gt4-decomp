/* libio (GNU iostream library, gcc 2000-10-03 snapshot): the type_info function of libio's class ios (compiler-generated from its declaration).
 * licence: libio (GPLv2 with the libio special exception, see THIRD_PARTY.md) */
typedef unsigned int u32;

extern "C" void _ios_fields__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006CF878[];
extern int D_006D62E8;

extern int D_008A1C40;

extern "C" void *func_00615148(void) {
    if (D_008A1C40 == 0) {
        _ios_fields__tf();
        func_005BFB68(&D_008A1C40, D_006CF878, &D_006D62E8);
    }
    return &D_008A1C40;
}
