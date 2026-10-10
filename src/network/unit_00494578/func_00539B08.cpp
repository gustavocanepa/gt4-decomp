extern "C" int func_005ADCE0(int arg0);

struct func_00539B08_arg0 {
    char pad0[0xC];
    int unkC;
};

extern "C" int func_00539B08(struct func_00539B08_arg0 *arg0) {
    if (arg0 == 0) {
        return 2;
    }
    int r = func_005ADCE0(arg0->unkC);
    return (~r != 0) ? 0 : 0x384;
}
