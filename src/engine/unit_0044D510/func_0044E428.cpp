typedef unsigned char u8;

struct Inner {
    char pad[0x11];
    u8 unk11;
};

struct Obj {
    char pad[0x14];
    Inner *unk14;
};

extern "C" Obj *D_00624980;

extern "C" u8 func_0044E428(void) {
    return D_00624980->unk14->unk11;
}
