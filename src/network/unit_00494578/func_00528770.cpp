typedef unsigned short u16;
typedef unsigned char u8;

struct Obj {
    char pad[2];
    u8 unk2;
    u8 unk3;
};

extern "C" u16 func_00528770(struct Obj *arg0) {
    u8 buf[2];
    buf[0] = arg0->unk2;
    buf[1] = arg0->unk3;
    return *(u16 *)buf;
}
