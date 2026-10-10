typedef int s32;
typedef float f32;

extern "C" void GT4Model__BinStreamReader__readArray(s32 arg0, char *arg1, s32 arg2);

extern "C" f32 GT4Model__BinStreamReader__readFloat(s32 arg0) {
    f32 buf;
    GT4Model__BinStreamReader__readArray(arg0, (char *)&buf, 4);
    return buf;
}
