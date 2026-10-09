typedef unsigned char u8;

struct Inner {
    char pad[0xD];
    u8 unkD;
};

struct Obj {
    char pad[0x14];
    Inner *unk14;
};

extern "C" Obj *D_00624980;

extern "C" u8 func_0044E3F8(void) {
    return D_00624980->unk14->unkD;
}
