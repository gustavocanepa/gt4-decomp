typedef int s32;

extern "C" void GT4Model__BinStreamWriter__writeArray(void *arg0, s32 *arg1, s32 arg2);

extern "C" void func_0045AFC8(void *arg0, s32 arg1) {
    s32 local = arg1;
    GT4Model__BinStreamWriter__writeArray(arg0, &local, 4);
}
