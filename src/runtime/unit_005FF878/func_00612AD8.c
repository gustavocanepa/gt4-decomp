typedef int s32;
typedef unsigned u32;
s32 func_00612AD8(char *arg0, s32 arg1) {
    s32 temp_t0;
    s32 temp_v0;
    u32 temp_a0;
    u32 temp_a1;

    temp_v0 = *(s32 *)(arg0 + 8);
    temp_t0 = (temp_v0 < arg1) ? temp_v0 : arg1;
    temp_a0 = *(u32 *)(arg0 + 0x1C) + temp_t0;
    temp_a1 = temp_a0 - *(s32 *)(arg0 + 4);
    *(u32 *)(arg0 + 0x1C) = temp_a0;
    if (temp_a1 >= *(u32 *)arg0) {
        *(u32 *)(arg0 + 0x1C) = temp_a1;
    }
    *(s32 *)(arg0 + 8) = temp_v0 - temp_t0;
    *(s32 *)(arg0 + 0xC) = *(s32 *)(arg0 + 0xC) + temp_t0;
    *(s32 *)(arg0 + 0x10) = *(s32 *)(arg0 + 0x10) + temp_t0;
    *(s32 *)(arg0 + 0x14) = *(s32 *)(arg0 + 0x14) + temp_t0;
    return temp_t0;
}
