typedef unsigned int u32;

extern "C" u32 func_00579330(u32 *arg0) {
    u32 temp_v0 = (*arg0 * 0x11) + 0x11;
    *arg0 = temp_v0;
    return temp_v0 ^ ((temp_v0 << 16) | (temp_v0 >> 16));
}
