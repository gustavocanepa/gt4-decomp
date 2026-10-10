typedef unsigned char u8;

struct C { char pad[0xC]; u8 unkC; };
struct B { char pad[0x14]; C *unk14; };

extern B *PDISTD__global_font_manager;

extern "C" u8 func_0044E3E0(void) {
    return PDISTD__global_font_manager->unk14->unkC;
}
