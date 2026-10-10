typedef int s32;

extern "C" void RaceCarSound__playStop(void *arg0, s32 arg1);

extern "C" void func_005FAE50(char *arg0) {
    RaceCarSound__playStop(arg0 + 0x2900, 1);
}
