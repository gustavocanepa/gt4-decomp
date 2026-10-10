typedef int s32;

extern "C" void GT4Model__BinStreamReader__readArray(void *arg0, s32 *arg1, s32 arg2);

extern "C" s32 func_0045B1B8(void *arg0) {
    s32 local;
    GT4Model__BinStreamReader__readArray(arg0, &local, 4);
    return local;
}
