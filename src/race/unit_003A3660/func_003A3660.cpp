typedef unsigned int u32;

struct S003A3660 {
    char pad[0x8];
    u32 unk8;
};

extern "C" void func_003A3660(S003A3660 *arg0, u32 arg1) {
    if (arg1 > 0x03FFFFFEU) {
        arg1 = 0x03FFFFFFU;
    }
    arg0->unk8 = arg1;
}
