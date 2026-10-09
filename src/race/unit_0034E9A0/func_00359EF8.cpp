typedef unsigned int u32;

extern char D_006205C8[];

extern "C" void *func_00359EF8(u32 arg0) {
    u32 v = (arg0 >= 3U) ? 0U : arg0;
    return D_006205C8 + v * 0x78;
}
