typedef unsigned char u8;

struct Inner {
    char pad[0xD];
    u8 unkD;
};

struct Obj {
    char pad[0x14];
    Inner *unk14;
};

extern "C" Obj *PDISTD__global_font_manager;

extern "C" u8 func_0044E3F8(void) {
    return PDISTD__global_font_manager->unk14->unkD;
}
