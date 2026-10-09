typedef unsigned int u32;

extern "C" void func_00604F28();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_006D6130;

extern int D_0088DE40;

extern "C" void *func_005D0D10(void) {
    if (D_0088DE40 == 0) {
        func_00604F28();
        func_005BFB68(&D_0088DE40, ((char *)"Q28Jpeg2Sys14JpegEncoderGT4"), &D_006D6130);
    }
    return &D_0088DE40;
}
