typedef unsigned int u32;
typedef unsigned char u8;

struct Obj {
    char pad[0x11];
    u8 unk11;
};

extern "C" u32 func_00448908(Obj *arg0) {
    return (u32)arg0->unk11 % 100u;
}
