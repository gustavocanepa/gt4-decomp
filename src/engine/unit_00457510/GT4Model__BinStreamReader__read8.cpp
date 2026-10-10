typedef int s32;
typedef signed char s8;

extern "C" s32 GT4Model__BinStreamBase__get(void);

extern "C" s8 GT4Model__BinStreamReader__read8(void) {
    return (s8)GT4Model__BinStreamBase__get();
}
