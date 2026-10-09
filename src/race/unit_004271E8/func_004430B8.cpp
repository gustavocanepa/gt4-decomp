typedef unsigned char u8;

struct Src {
    char pad[0x15B];
    u8 unk15B;
    u8 unk15C;
};

struct Dst {
    char pad[0x5];
    u8 unk5;
    u8 unk6;
};

extern "C" void func_004430B8(Src *arg0, Dst *arg1) {
    arg1->unk5 = arg0->unk15B;
    arg1->unk6 = arg0->unk15C;
}
