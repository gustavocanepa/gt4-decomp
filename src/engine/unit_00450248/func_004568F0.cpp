typedef int s32;

extern "C" s32 D_008465F0[16];

extern "C" void func_004568F0(s32 arg0, s32 arg1) {
    if (arg0 < 0x10) {
        D_008465F0[arg0] = arg1;
    }
}
