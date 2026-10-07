typedef int s32;
typedef unsigned int u32;

extern "C" s32 func_0057A058(s32 arg0) {
    u32 temp_a0;

    temp_a0 = arg0 & 0xFF;
    return (temp_a0 << 3) | (temp_a0 >> 5);
}
