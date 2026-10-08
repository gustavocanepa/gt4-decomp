typedef int s32;
typedef unsigned char u8;

struct Obj {
    char pad[0x4];
    u8 *unk4;
};

extern "C" s32 func_0060B9C0(struct Obj *arg0) {
    u8 *p = arg0->unk4 + 0x10;
    s32 b = p[1];
    s32 a = p[0];
    return a | (b << 8);
}
