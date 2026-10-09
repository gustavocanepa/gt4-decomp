typedef unsigned char u8;

struct Inner {
    char pad[0x29];
    u8 unk29;
};

struct Obj {
    Inner *unk0;
    u8 unk4;
};

extern "C" void func_00365228(Obj *arg0, u8 arg1) {
    if (arg0->unk4 == 0) {
        arg0->unk0->unk29 = arg1;
    }
}
