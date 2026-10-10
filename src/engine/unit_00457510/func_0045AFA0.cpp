typedef short s16;
typedef int s32;

extern "C" void GT4Model__BinStreamWriter__writeArray(void *arg0, s16 *arg1, s32 arg2);

extern "C" void func_0045AFA0(void *arg0, s16 arg1) {
    s16 local = arg1;
    GT4Model__BinStreamWriter__writeArray(arg0, &local, 2);
}
