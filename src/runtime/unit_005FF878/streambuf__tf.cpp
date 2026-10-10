/* libio (GNU iostream library, gcc 2000-10-03 snapshot): the type_info function of libio's class streambuf (compiler-generated from its declaration).
 * licence: libio (GPLv2 with the libio special exception, see THIRD_PARTY.md) */
typedef unsigned int u32;

extern "C" void _IO_FILE__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_006D62F0;

extern int D_008A1C30;

extern "C" void *streambuf__tf(void) {
    if (D_008A1C30 == 0) {
        _IO_FILE__tf();
        func_005BFB68(&D_008A1C30, ((char *)"9streambuf"), &D_006D62F0);
    }
    return &D_008A1C30;
}
