typedef unsigned char u8;
typedef int s32;

struct Dst {
    char pad[0x178];
    u8 unk178;
    u8 unk179;
    u8 unk17A;
};

struct Src {
    char pad[0x3];
    u8 unk3;
    u8 unk4;
    u8 unk5;
};

extern "C" void func_00441950(s32 arg0, struct Dst *arg1, struct Src *arg2) {
    arg1->unk178 = arg2->unk3;
    arg1->unk179 = arg2->unk4;
    arg1->unk17A = arg2->unk5;
}
