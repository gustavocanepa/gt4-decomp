extern "C" int func_005ADCC0(int arg0);

struct func_00539BA8_arg0 {
    char pad0[0xC];
    int unkC;
};

extern "C" int func_00539BA8(struct func_00539BA8_arg0 *arg0) {
    if (arg0 == 0) {
        return 2;
    }
    int r = func_005ADCC0(arg0->unkC);
    return (~r != 0) ? 0 : 0x384;
}
