extern "C" void func_00576788(void *arg0);

struct S {
    char pad000[0x15C];
    int unk15C;
    char pad160[0x18C - 0x15C - 4];
    int unk18C;
};

extern "C" int func_004F0C88(S *arg0) {
    if (arg0->unk18C != 0) {
        return 0;
    }
    func_00576788((char *)arg0 + 8);
    arg0->unk18C = 1;
    arg0->unk15C = 0;
    return 1;
}
