typedef int s32;

extern "C" void HIO__operator_shr(s32 arg0, void *arg1);

extern "C" void mCall__read(void *arg0, s32 arg1) {
    HIO__operator_shr(arg1, (char *)arg0 + 8);
}
