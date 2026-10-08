typedef int s32;

extern "C" s32 func_00568208(void *arg0);

extern "C" s32 func_005681E8(s32 *arg0) {
    *arg0 = 0;
    return func_00568208((char *)arg0 + 4);
}
