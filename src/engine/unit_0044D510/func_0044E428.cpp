typedef unsigned char u8;

struct Inner {
    char pad[0x11];
    u8 unk11;
};

struct Obj {
    char pad[0x14];
    Inner *unk14;
};

extern "C" Obj *PDISTD__global_font_manager;

extern "C" u8 func_0044E428(void) {
    return PDISTD__global_font_manager->unk14->unk11;
}
