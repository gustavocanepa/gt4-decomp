typedef int s32;
typedef unsigned char u8;

extern s32 GT4Model__BinStreamBase__get(void);

u8 GT4Model__BinStreamReader__read8u(void) {
    return (u8)GT4Model__BinStreamBase__get();
}
