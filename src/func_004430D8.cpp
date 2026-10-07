typedef short s16;
typedef unsigned short u16;
typedef unsigned char u8;

struct Src {
    u8 pad[0x167];
    u8 unk167;
};

struct Dst {
    u8 pad[0x11D];
    u8 unk11D;
    u16 unk11E;
};

extern "C" void func_004430D8(Src *arg0, Dst *arg1, u16 *arg2) {
    arg1->unk11D = arg0->unk167;
    arg1->unk11E = *arg2;
}
