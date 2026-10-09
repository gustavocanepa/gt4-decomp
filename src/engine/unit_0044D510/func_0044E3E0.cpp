typedef unsigned char u8;

struct C { char pad[0xC]; u8 unkC; };
struct B { char pad[0x14]; C *unk14; };

extern B *D_00624980;

extern "C" u8 func_0044E3E0(void) {
    return D_00624980->unk14->unkC;
}
