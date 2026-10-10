typedef unsigned char u8;
typedef int s32;

extern "C" void HIO__read(void *arg0, u8 *arg1, s32 arg2);

extern "C" u8 HIO__read8(void *arg0) {
    u8 local;
    HIO__read(arg0, &local, 1);
    return local;
}
