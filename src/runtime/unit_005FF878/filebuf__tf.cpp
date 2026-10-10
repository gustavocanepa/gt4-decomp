/* libio (GNU iostream library, gcc 2000-10-03 snapshot): the type_info function of libio's class filebuf (compiler-generated from its declaration).
 * licence: libio (GPLv2 with the libio special exception, see THIRD_PARTY.md) */
typedef unsigned int u32;

extern "C" void streambuf__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_008A1C30;

extern int D_008A1C20;

extern "C" void *filebuf__tf(void) {
    if (D_008A1C20 == 0) {
        streambuf__tf();
        func_005BFB68(&D_008A1C20, ((char *)"7filebuf"), &D_008A1C30);
    }
    return &D_008A1C20;
}
