typedef int s32;
typedef short s16;

extern "C" void GT4Model__BinStreamReader__readArray(s32 arg0, char *arg1, s32 arg2);

extern "C" s16 func_0045B168(s32 arg0) {
    s16 local;
    GT4Model__BinStreamReader__readArray(arg0, (char *)&local, 2);
    return local;
}
